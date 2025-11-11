#include <cstdlib>
#include <iostream>
using namespace std;

#include "../BitLib/BitFile.h"
using BitLib::BitFile;

#include "Huffman.h"
using Huff::HuffmanCoder;

int main(void) {
	const uint size = 200*1024u; // 10kb
	const char* fileName = "crap.out";
	uint sizetmp;
	HuffmanCoder huff;
	BitFile file;
	
	// Preparando dados aleatórios
	byte *buffA = new byte[size], *buffB;
	srand(time(0));
	for (uint i = 0; i < size; ++i)
		buffA[i] = rand()%100;

	// Encoding
	file.open(fileName,BitFile::Out);
	huff.setCode(buffA,size);
	huff.getEncoded(file);

	// Decoding
	file.open(fileName,BitFile::In);
	buffB = huff.getDecoded(sizetmp,file);
	
	// Comparação
	bool err = (size != sizetmp);
	cout << "SizeA = " << size << endl
		 << "SizeB = " << sizetmp << endl;

	uint min = (size < sizetmp) ? size : sizetmp;
	uint count = 0;
	for (uint i = 0; i < min; ++i) {
		cout << "A = " << int(buffA[i])
			 << " B = " << int(buffB[i]) << endl;
		if (buffA[i] != buffB[i]) {
			err = true;
			++count;
		}
	}

	cout << (err?"Diferentes!":"Iguais!") << endl;
	cout << "Num erros = " << count << endl;	

	delete[] buffA;
	delete[] buffB;
	return EXIT_SUCCESS;
}
