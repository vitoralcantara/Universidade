#include "Huffman.h"

namespace Huff {

HuffmanCoder::HuffmanCoder(byte* code, uint size, uint* f) {
	setCode(code,size,f);
}

void HuffmanCoder::setCode(byte* code, uint size, uint* f) {
	buffer = code;
	buffSize = size;
	freq = f;
}

// Altera esse parâmetro por ref
void HuffmanCoder::makeHuffmanTree(HuffmanTree& hufftree) {
	// Se ainda não tem a tabela de frequências, pega ela
	bool gotFreq = false;
	if (!freq) { getFreq(); gotFreq = true; }
	// Fila de prioridade com árvores de Huffman, para decodificação.
	PriorityQueue<HuffmanTree> pq(260);
	for (uint i = 0; i < 256; ++i) 
		// Se o byte ocorrer no buffer, cria uma árvore correspondente
		// com o peso certo, e armazena na fila
		if (freq[i]) {
			HuffmanTree ht(freq[i],byte(i));
			pq.toss(ht);
		}
	pq.fixHeap();
	assert(pq.queueSize() >= 1);
	// Algoritmo guloso que monta a árvore ótima de huffman
	while (pq.queueSize() > 1) {
		HuffmanTree ht(pq.popMin(),pq.popMin());
		pq.insert(ht);
	}
	// A árvore ótima e a única que sobrou na fila
	hufftree = pq.popMin();
	if (gotFreq) delete[] freq;
}


/*
Com relação ao encoding:

NOTE: (Header)
O header da saída do HuffmanCoder é:
tamanho_original_do_bloco(4 bytes) +
code_lengths_em_sequencia_com_zeros (256 bytes)
Total disperdício = 36 + 256 = 292 bytes = 2336 bits.
Pesquisar como diminuir isso sem usar EOF_char.

NOTE: (Ordem invertida)
Os códigos em forma canônica são armazenados como se fossem
"de trás-pra-frente" em relação à representação usual (MSD à esquerda).
Requer cuidado para remontar a árvore e/ou tabela.
RESOLVIDO: O método do BitFile para escrever BitArrays escreve invertidamente, deixando o código do BitFile com o 
MSD à esquerda: traverse na árvore dá certo =)

NOTE: (BitFile)
Trabalha com um BitFile direto, pois o Huffman será usado
como último estágio de compressão no Rebhu (diminui o overhead de alo-
cação e cópia de bytes). FEITO

*/

void HuffmanCoder::getEncoded(BitFile& out) {
	// Monta a árvore e depois escreve o header
	HuffmanTree ht;
	makeHuffmanTree(ht);
	out << uint(buffSize); // Tamanho depois de descompactado

	uint nonzero = 0;
	byte* lenghts = new byte[256];
	ht.lengthTable(lenghts,nonzero);

	// Vê se é melhor armazenar em ordem sem chars, 
	// ou com chars e excluindo zeros
	if (nonzero*2+2 < 256) {
		out << byte(nonzero);
		for (uint i = 0; i < 256; ++i)
			if (lenghts[i])
				out << byte(i) << lenghts[i];
	}
	else {
		out << byte(0);
		for (uint i = 0; i < 256; ++i)
			out << lenghts[i];
	}

	// Calcula e escreve os códigos
	BitArray* codes = canonicalCode(lenghts);
	for (uint i = 0; i < buffSize; ++i)
		out << codes[buffer[i]];

	delete[] lenghts;
	delete[] codes;
}

/*
Com relação ao decoding:

NOTE: (Número de bits à serem lidos)
O algoritmo sabe quando para de encodar qnd o número de bytes
escritos no byte* de retorno é igual ao tamanho original, que é
o primeiro uint escrito no header do huffman. Essa técnica não é
quebrada pelos bits de padding do sistema operacional.

NOTE: (Remontar a árvore)
Se os códigos forem armazenados na forma canônica, não teria como
remontar a árvore -> teria que usar busca binária nos códigos à
cada bit lido.
RESOLVIDO: Monta um BT temporária (cheia). Percorre em ordem inversa à
lida pelo 

NOTE: (BitFile)
Trabalha com um BitFile de entrada direto pois o Huffman é o último
algoritmo de compressão aplicado aos arquivos. Note que o arquivo de
entrada tem que vir já na posição de leitura onde começa a codificação
huffman associada à este trecho. Em particular, isso é importante quando
o arquivo compactado engloba vários arquivos separados.

*/

byte* HuffmanCoder::getDecoded(uint& outSize, BitFile& in, byte* dec) {
	HuffmanTree ht;
	NavigateIterator<byte> it;

	// Processa o header (pega outSize e forma os códigos)
	outSize = in.readInt();// Tamanho depois de descompactado
	byte* lenghts = new byte[256], tmp;
	tmp = in.readByte();

	if (tmp) {
		for (uint i = 0; i < 256; ++i) 
			lenghts[i] = 0;
		for (uint i = 0; i < tmp; ++i) {
			byte a = in.readByte();
			lenghts[a] = in.readByte();
		}
	}
	else {
		for (uint i = 0; i < 256; ++i)
			in >> lenghts[i];
	}

	BitArray* codes = canonicalCode(lenghts);
	makeCanonicalTree(ht,codes);

	uint c = 0; // posição atual em decoded
	byte* decoded;
	if (dec)
		decoded = dec;
	else
		decoded = new byte[outSize];

	// Parte lenta: processa o arquivo bit-a-bit, descendo na árvore
	while (c < outSize) {
		it = ht.beginNavigate();
		while (!(it.done()))
			if (in.readBit()) it.goRight();
			else it.goLeft();
		decoded[c++] = *it;
	}

	delete[] lenghts;
	delete[] codes;
	return decoded;
}


void HuffmanCoder::makeCanonicalTree(HuffmanTree& ht, BitArray* codes) {
	uint max = 0;
	for (uint i = 0; i < 256; ++i)
		if (codes[i].size() > max) max = codes[i].size();

	ht.fillTree(max);
	NavigateIterator<byte> it;
	for (uint i = 0; i < 256; ++i) {
		if (codes[i].size() == 0) continue;
		it = ht.beginNavigate();
		assert(codes[i].size() <= 255);
		for (int j = codes[i].size()-1; j >= 0; --j) {
			if (codes[i][j]) it.goRight();
			else it.goLeft();
		}
		ht.set_del_under(it,i); // hack
	}
}


/*
Esta estrutura ajuda na ordenação dos códigos 
temporários para montar o canonical.
*/

struct canonCode {
	byte b;
	uint l;
	canonCode(byte x = 0, byte le = 0) : b(x), l(le) { }
	bool operator< (const canonCode& co) const {
		return ((l == co.l)?(b < co.b):(l < co.l));
	}
};

/*
NOTE: (RESOLVIDO)
O código do canonicalCode não estava lidando com os códigos vazios
(frequências/lenghts vazias).
*/

BitArray* HuffmanCoder::canonicalCode(byte* lenghtTable) {

	BitArray* codes = new BitArray[256];
	canonCode aux[256];
	for (uint i = 0; i < 256; ++i) {
		codes[i] = BitArray(0u);
		aux[i] = canonCode(i,lenghtTable[i]);
	}
	sort(aux,aux+256);

	// Skip os vazios
	uint i = 0;
	while (aux[i].l == 0) ++i; // 0's estão só no início de aux (sorted)
	codes[aux[i].b] = BitArray(aux[i].l);
	++i; // continua do próximo
	
	// Algoritmo para construção do código canônico (Ref: Wikipedia)
	for (; i < 256; ++i) {
		if (aux[i].l == aux[i-1].l) {
			codes[aux[i].b] = BitArray(aux[i].l);
			codes[aux[i].b].fromUint(codes[aux[i-1].b].toUint()+1);
		}
		else { // '>'
			BitArray old(codes[aux[i-1].b]), novo(aux[i].l);
			old.fromUint(old.toUint()+1);
			int dif = aux[i].l - aux[i-1].l;
			for (uint j = 0; j < old.size(); ++j)
				novo[j+dif] = old[j];
			codes[aux[i].b] = novo;
		}
	}

	return codes;
}

// Determina frequencia de cada caractere em O(n)
void HuffmanCoder::getFreq() {
	freq = new uint[256];
	for (uint i = 0; i < 256; ++i) freq[i] = 0;
	for (uint i = 0; i < buffSize; ++i)
		++freq[buffer[i]];
}

}
