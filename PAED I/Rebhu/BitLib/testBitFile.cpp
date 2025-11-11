#include <cstdlib>
#include <iostream>
#include "BitFile.h"
using BitLib::BitFile;
using namespace std;

typedef unsigned char byte;

int main(void) {
	BitFile crap;

	crap.open("crap.out",BitFile::Out);
	crap << byte(56) << byte(108);
	uint old = crap.currentPos();
	crap.move(4);
	crap << byte(80);
	crap.gotoPos(old);
	crap.write(11123644463u);
	crap.close();

	// 56 108 123643 80
	crap.open("crap.out",BitFile::In);
	cout << uint(crap.readByte()) << ' ';
	cout << uint(crap.readByte()) << ' ';
	cout << crap.readInt() << ' ';
	cout << uint(crap.readByte()) << endl;
	crap.close();

	return 0;
}
