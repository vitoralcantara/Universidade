#include <cstdlib>
#include <iostream>
using namespace std;

typedef unsigned char byte;

#include "BlockSort.h"
using BlockSort::lsdRadixSort;
using BlockSort::quickSort;


int main(void) {
	srand(time(0));

	const uint _w = 10*1024u;

	byte* data = new byte[_w];
	uint* perm = new uint[_w];

	for (uint i = 0; i < _w; ++i) {
		data[i] = rand()%256;
		perm[i] = i;
	}

	lsdRadixSort(data,perm,_w);
	//quickSort(perm,_w,data);
	
	delete[] perm;
	delete[] data;
	return 0;
}
