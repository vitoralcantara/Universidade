all: a.out

a.out: BitArray.o BitFile.o testBitFile.o
	g++ BitArray.o BitFile.o testBitFile.o -Wall -O3

BitArray.o: BitArray.h BitArray.cpp
	g++ BitArray.h BitArray.cpp -c -Wall -O3

BitFile.o: BitFile.h BitFile.cpp
	g++ BitFile.h BitFile.cpp -c -Wall -O3

testBitFile.o: testBitFile.cpp
	g++ testBitFile.cpp -c -Wall -O3
