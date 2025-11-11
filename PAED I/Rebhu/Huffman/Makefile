# Programa para testar a implementação do Huffman
# Giuliano Vilela

all: a.out

# Compilação principal
a.out: HuffmanTree.o Huffman.o testHuffman.o RebhuDefaults.o BitArray.o BitFile.o
	g++ HuffmanTree.o Huffman.o testHuffman.o RebhuDefaults.o BitArray.o BitFile.o -Wall -O3

# Main source
testHuffman.o: testHuffman.cpp 
	g++ testHuffman.cpp -c -Wall -O3

# Auxiliares

RebhuDefaults.o: ../RebhuDefaults.h ../RebhuDefaults.cpp
	g++ ../RebhuDefaults.h ../RebhuDefaults.cpp -c -Wall -O3

BitArray.o: ../BitLib/BitArray.h ../BitLib/BitArray.cpp
	g++ ../BitLib/BitArray.h ../BitLib/BitArray.cpp -c -Wall -O3

BitFile.o: ../BitLib/BitFile.h ../BitLib/BitFile.cpp
	g++ ../BitLib/BitFile.h ../BitLib/BitFile.cpp -c -Wall -O3


# Sources principais

HuffmanTree.o: HuffmanTree.h HuffmanTree.cpp
	g++ HuffmanTree.h HuffmanTree.cpp -c -Wall -O3

Huffman.o: Huffman.h Huffman.cpp
	g++ Huffman.h Huffman.cpp -c -Wall -O3


# Limpando a casa
clean:
	rm *.o *~ *.gch ../BitLib/*.gch ../BitLib/*.o ../BitLib/*~ -f a.out