#include <cstdlib>
#include <iostream>
using namespace std;

typedef unsigned char byte;

#include "Rle.h"
using RLE::RunLength;

int main(void) {

	const uint size = 50u*1024u;
	RunLength rle;
	byte *buffA = new byte[size], *buffB, *buffC;
	
	cout << "Escrevendo dados aleatórios" << endl;
	srand(time(0));
	for (uint i = 0; i < size; ++i)
		buffA[i] = rand()%256;

	uint sizetmp;
	rle.setCode(buffA,size);

	cout << "Encoder" << endl;
	rle.getEncoded(buffB,sizetmp,true);

	cout << "Antes = " << size << endl
		 << "Depois = " << sizetmp << endl;

	cout << "Decoder" << endl;
	rle.setCode(buffB,sizetmp);
	rle.getDecoded(buffC,sizetmp,true);

	bool err = (size != sizetmp);

	cout << endl << "Comparação" << endl;
	for(uint i = 0; i < sizetmp; ++i) {
		cout << "A = " << int(buffA[i])
			 << " B = " << int(buffC[i])
			 << endl;
		err |= (buffA[i] != buffC[i]);
	}

	cout << endl << endl
		 << (err?"Diferentes!":"Iguais!") << endl;

	delete[] buffA;
	delete[] buffB;
	delete[] buffC;

	return 0;
}
