all: a.out

a.out: RebhuDefaults.o testRle.o Rle.o
	g++ RebhuDefaults.o testRle.o Rle.o -Wall -O3

testRle.o: testRle.cpp
	g++ testRle.cpp -c -Wall -O3

Rle.o: Rle.h Rle.cpp
	g++ Rle.h Rle.cpp -c -Wall -O3

RebhuDefaults.o: ../RebhuDefaults.h ../RebhuDefaults.cpp
	g++ ../RebhuDefaults.h ../RebhuDefaults.cpp -c -Wall -O3

clean:
	rm *.o *~ *.gch -f