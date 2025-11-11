#include "BurrowsWheeler.h"

//! Seta o buffer interno para code, de tamanho size
BWT::BurrowsWheeler::BurrowsWheeler(byte* code, uint size) {
	buff = code;
	buffSize = size;
}

//! Faz shallow copy de cp: ficam compartilhando o mesmo buffer
BWT::BurrowsWheeler::BurrowsWheeler(const BurrowsWheeler& cp) {
	buff = cp.buff;
	buffSize = cp.buffSize;
}

//! Destrutor não desaloca a memória do buffer
BWT::BurrowsWheeler::~BurrowsWheeler() {
}

//! Seta o código interno para code, de tamanho size
void BWT::BurrowsWheeler::setCode(byte* code, uint size) {
	buff = code;
	buffSize = size;
}

/**
* Faz a codificação do buffer interno.
* Caso enc seja um buffer válido, armazena o resultado em enc
* Caso contrário, aloca memória para o resultado e retorna
* um ponteiro para este bloco.
*/
byte* BWT::BurrowsWheeler::getEncoded(uint& num, byte* enc) {
	uint origPos = 0;
	num = buffSize+8;

	byte* encoded;
	if (enc) 
		encoded = enc;
	else 
		encoded = new byte[buffSize+8];
	
	// Ordena as permutações e reserva o bloco de memória
	uint* m = sortedPermutations(origPos);

	// Escreve o cabeçalho (tamanho do bloco(sem hd) + posição da string original)
	byte* blockSize = UInt::toByte(buffSize);
	byte* origPosBytes = UInt::toByte(origPos);

	for (uint i = 0; i < 4; ++i) {
		encoded[i] = blockSize[i];
		encoded[i+4] = origPosBytes[i];
	}

	// Escreve o resultado final da string
	for (uint i = 0; i < buffSize; ++i)
		encoded[i+8] = buff[m[i]?(m[i]-1):(buffSize-1)];
		
	delete[] m;
	delete[] blockSize; 
	delete[] origPosBytes;

	return encoded;
}

/**
* Pega o resultado da decodificação do buffer interno
* e escreve no arquivo out. Coloca em num o tamanho de bytes escritos
* no arquivo.
*/
void BWT::BurrowsWheeler::getDecoded(BitFile& out, uint& num) {
	// Processa cabeçalho e monta o vetor de transformação
	uint blockSize = UInt::fromByte(buff);
	uint origPos = UInt::fromByte(buff+4);
	uint* trans = transformationVector(blockSize);

	//num = blockSize;
	num = blockSize+8;
	byte* str = buff+8;

	// Algoritmo de decodificação BWT em O(n)
	for (uint i = 0, index = origPos; i < blockSize; ++i, index = trans[index])
		out << str[trans[index]];

	delete[] trans;
}

// Variáveis globais para que comp possa acessar a str original
byte* str;
uint size;

//! Função de comparação normal (letra à letra) entre duas permutações de str
int comp(const void* x, const void* y) {
	uint *a = (uint*)x, *b = (uint*)y;
	uint i = *a, j = *b, c = 0;
	for (; c != size; i = (i+1)%size, j = (j+1)%size, ++c) {
		if (str[i] == str[j]) continue;
		return ((str[i] < str[j]) ? -1 : 1);
	}
	return 0;
}

/**
* Parte essencial da codificação BWT:
* Monta um array de uints, cada um representando uma permutação diferente do buffer original
* Cada permutação é modelada como um único uint, que representa a primeira posição da permutação.
* As permutações são retornadas de forma ordenada, e a posição da primeira permutação (uint = 0)
* é armazenada no parâmetro firstPos.
*/
uint* BWT::BurrowsWheeler::sortedPermutations(uint& firstPos) {
	uint* vet = new uint[buffSize];
	
	for (uint i = 0; i < buffSize; ++i)
		vet[i] = i;
	
	str = buff;
	size = buffSize;

	//std::sort(vet,vet+buffSize);
	qsort(vet,buffSize,sizeof(uint),comp);
	
	for (uint i = 0; i < buffSize; ++i)
		if (vet[i] == 0) {
			firstPos = i;
			break;
		}

	return vet;
}

//! Representa um par (byte-uint)
struct _pair {
	byte b;
	uint i;
	_pair (byte bt = 0, uint it = 0) : b(bt),i(it) { }
};

//! Pra usar no qsort (ordena por bytes, e nos empates pela posiçao original)
int compPair(const void* x, const void* y) {
	_pair a = *(_pair*)x, b = *(_pair*)y;
	return ((a.b != b.b)?(a.b-b.b):(a.i-b.i));
}

/**
* Parte essencial da decodificação BWT:
* Retorna o vetor de transformação que permite descobrir a posição original
* de cada caractere do buffer interno.
*/
uint* BWT::BurrowsWheeler::transformationVector(const uint& blockSize) {
	byte* str = buff+8; // depois do header
	_pair* sorted = new _pair[blockSize];
	uint* trans = new uint[blockSize];

	/* NOTE:
	* O trecho abaixo é crítico na performance. Maior atraso da descompactação.
	* Idéia: Fazer uma estrutura (byte,uint), ordernar pelos bytes guardando as posições originais
	* Dava pra pegar o vetor depois em O(n) (ou O(1)?).
	for (uint i = 0; i < blockSize; ++i)
		for (it = not_used.begin();; ++it)
			if (ordStr[i] == str[*it]) {
				trans[i] = *it;
				not_used.erase(it);
				break;
			}
	*/
	
	/* NOTE:
	* Resolvido: Ordena os bytes guardando as posições originais: 
	* Estas posições originais formam o vetor de transformação.
	* Esta solução é O(nlogn + n) = O(nlogn). Bem mais rápida que acima (era O(n²)).
	* Reduz o tempo de descompactação drasticamente.
	*/

	for (uint i = 0; i < blockSize; ++i)
		sorted[i] = _pair(str[i],i);

	qsort(sorted,blockSize,sizeof(_pair),compPair);

	for (uint i = 0; i < blockSize; ++i)
		trans[i] = sorted[i].i;

	delete[] sorted;
	return trans;
}
