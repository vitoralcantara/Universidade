#include <cstdlib>
#include <iostream>
using namespace std;

typedef unsigned char byte;

#include "BurrowsWheeler.h"
using BWT::BurrowsWheeler;

#include "../BitLib/BitFile.h"
using BitLib::BitFile;

int main(void) {
	for (uint x = 0; x < 1; ++x) {
	const uint size = 15*1024u; // 60kb (4*15kb)
	BurrowsWheeler bwt;
	BitFile out;

	byte *buffA = new byte[size], *buffB;

	cout << "Escrevendo dados aleatórios" << endl;
	srand(time(0));
	for (uint i = 0; i < size; ++i)
		buffA[i] = rand()%256;

	uint sizetmp;
	bwt.setCode(buffA,size);
	
	cout << "Encoder" << endl;
	buffB = bwt.getEncoded(sizetmp);

	cout << "Decoder" << endl;
	bwt.setCode(buffB,sizetmp);
	out.open("crap.out",BitFile::Out);
	bwt.getDecoded(out,sizetmp);

	bool err = (size != sizetmp);
	cout << endl << "Comparação" << endl;
	cout << "SizeA = " << size << " SizeB = " << sizetmp << endl;

	out.close();
	out.open("crap.out",BitFile::In);

	for (uint i = 0; i < sizetmp; ++i) {
		byte tmp = out.readByte();
		cout << "A = " << int(buffA[i]) 
			 << "\tB = " << int(tmp) << endl;
		err |= (buffA[i] != tmp);
	}

	cout << endl << endl;
	cout << (err?"Diferentes!":"Iguais!") << endl;

	delete[] buffA;
	delete[] buffB;
}
	return 0;
}
