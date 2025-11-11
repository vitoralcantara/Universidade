#include "Rle.h"

//! Retorna verdadeiro se os 3 últimos elementos de b são verdadeiros
inline bool last3Equal (byte* b, uint i) {
	return ((i > 1) && (b[i] == b[i-1]) && (b[i] == b[i-2]));
}

namespace RLE {

//! Seta o código interno para code, de tamanho size
RunLength::RunLength(byte* code, uint size) {
	buff = code;
	buffSize = size;
}

//! Shallow copy de cp: ficam compartilhando o mesmo buffer interno
RunLength::RunLength(const RunLength& cp) {
	buff = cp.buff;
	buffSize = cp.buffSize;
}

RunLength::~RunLength() {
	//delete[] freq;
}

void RunLength::setCode(byte* code, uint size) {
	buff = code;
	buffSize = size;
}

//! Codifica o buffer interno em enc, utilizando o algoritmo Packbits para o RLE
byte* RunLength::getEncoded(uint& num, byte* enc) {
	// Prevê espaço para o pior caso, mas se comprimir usa menos que buffSize
	byte* encoded;
	if (enc)
		encoded = enc;
	else
		encoded = new byte[buffSize+10+buffSize/127+200];
	byte* minibuff = new byte[127];	
	// encSize: posição atual no buffer encoded (1 à frente: próxima posição à escrever)
	// i: posição atual do buffer (1 à frente: número de elementos lidos)
	// run: conta número de repetições em um run
	// mini: posição atual do minibuffer (1 à frente: número de elementos escritos no minibuffer)
	uint encSize = 8, i = 0, run = 0, mini = 0;

	// RLE com unsigned packbits
	while (true) {

		// Alimenta o buff menor até encher, ou acabar os bytes ou começar uma run
		while (mini < 127 && i < buffSize) {
			minibuff[mini++] = buff[i++];
			if (last3Equal(minibuff,mini-1))
				break;
		}

		// Terminou tudo e as últimas não têm repetição
		if (i >= buffSize && (mini > 0 && !last3Equal(minibuff,mini-1))) {
			encoded[encSize++] = (mini+128); // Tamanho da sequência sem repetição
			for (uint x = 0; x < mini; ++x)
				encoded[encSize++] = minibuff[x];
			break;
		}

		// Não terminou, mas escreve sem repetição (buffer cheio)
		else if (mini == 127 && !last3Equal(minibuff,mini-1)) {
			encoded[encSize++] = (mini+128); // Tamanho da sequência sem repetição
			for (uint x = 0; x < mini; ++x)
				encoded[encSize++] = minibuff[x];
			mini = 0;
		}

		// Não terminou, e escreve com repetição
		else {
			if (mini-3 > 0) { // Escrevendo sem repetição os que estavam no minibuff
				encoded[encSize++] = (mini-3+128);
				for (uint x = 0; x < mini-3; ++x)
					encoded[encSize++] = minibuff[x];
			}
			run = 3;
			// Verifica qual o tamanho da run
			while (run != 127 && i < buffSize && buff[i++] == minibuff[mini-1]) 
				++run;
			if (buff[i-1] != minibuff[mini-1]) --i; // Avançou uma posição à mais

			// Gravando o tamanho da run
			encoded[encSize++] = run;
			// Gravando qual era o char da run
			encoded[encSize++] = minibuff[mini-1];
			mini = 0;
			if (i >= buffSize) break; // A run coincidiu com o final do buffer
		}
	}

	// Header: tamanho do bloco inteiro (com header) e o tamanho original da informação
	byte *blockSize = UInt::toByte(encSize), *origSize = UInt::toByte(buffSize);

	for (uint i = 0; i < 4; ++i) {
		encoded[i] = blockSize[i];
		encoded[i+4] = origSize[i];
	}

	// Num: tamanho do bloco inteiro, incluindo header
	num = encSize;

	delete[] blockSize;
	delete[] origSize;
	delete[] minibuff;
	// Na prática, o bloco alocado é maior que o espaço utilizado (disperdício de memória em runtime)
	// Porém é melhor do que alocar outro bloco e re-arranjar os elementos: O(n)
	return encoded;
}

//! Decodifica o buffer interno em dec, fazendo o esquema interno ao acima
byte* RunLength::getDecoded(uint& outNum, uint& inNum, byte* dec) {
	// i guarda posição do encoded, j guarda posição no decoded
	uint encSize, i = 0, j = 0;
	inNum = UInt::fromByte(buff);
	outNum = UInt::fromByte(buff+4);
	encSize = inNum;

	i = 8;

	byte* decoded;
	if (dec)
		decoded = dec;
	else
		decoded = new byte[outNum];

	while (i < encSize) {
		if (buff[i] < 128) { // Repetição
			++i;
			for (int x = 0; x < buff[i-1]; ++x)
				decoded[j++] = buff[i];
			++i;
		}
		else { // Sem repetição
			uint orig = i++;
			for (int x = 0; x < buff[orig]-128; ++x,++i)
				decoded[j++] = buff[i];
		}
	}

	assert(i == inNum);
	// Diz se todos os caracteres foram de fato lidos
	assert(j == outNum);

	return decoded;
}

}
