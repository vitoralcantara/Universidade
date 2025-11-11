#include "BlockSort.h"

#include <cstdio>
#include <iostream>
using namespace std;


namespace BlockSort {

byte* str;
uint size;

/**
* Retorna o dígito na posição pos da string
* que representa uma permutação de str, que tem como primeira
* posição a posição original first.
*/
inline byte get(uint& first, uint& pos) {
	return str[(first+pos)%size];
}

/**
* Implementação direta do countSort que ordena as permutações em data
* com relação ao dígito dig (para ser usado no radixSort).
* Assume que data tenha sido alocado dinâmicamente.
*/
void countSort (uint*& data, uint size, uint dig) {
	static uint count[256];
	uint* tmp = new uint[size];

	for (uint i = 0; i < 256; ++i)
		count [i] = 0;
	for (uint i = 0; i < size; ++i)
		++count[get(data[i],dig)];
	for (uint i = 1; i < 256; ++i)
		count[i] += count[i-1];
	for (long long i = size-1; i >= 0; --i)
		tmp[--count[get(data[i],dig)]] = data[i];

	delete[] data;
	data = tmp;
}

/**
* Implementação direta do bucketSort.
* Ordena as permutações em data, com relação ao dígito dig.
* Algoritmo de ordenação estável para ser usado no Radix Sort.
*/
void bucketSort (uint* data, uint size, uint dig) {
	static queue<uint> bins[256]; uint c = 0;
	for (uint i = 0; i < size; ++i)
		bins[get(data[i],dig)].push(data[i]);
	for (uint i = 0; i < 256; ++i)
		for(; !bins[i].empty(); bins[i].pop())
			data[c++] = bins[i].front();
}

//! Radix Sort simples pelo dígito menos significante e sem recursão
void lsdRadixSort (byte* orig, uint*& data, uint _size) {
	str = orig;
	size = _size;
	// Pode aplicar qualquer algoritmo stable nessa etapa.
	// countSort e bucketSort seriam os mais viáveis (complexidade menor neste caso)
	for (long long i = _size-1; i >= 0; --i)
		countSort(data,_size,i);
		//bucketSort(data,_size,i);
}

//! Função de comparação simples (letra à letra) entre duas permutações de str
int comp(const void* x, const void* y) {
	uint *a = (uint*)x, *b = (uint*)y;
	uint i = *a, j = *b, c = 0;
	//if (i == j) return 0; // Não precisa, No BWT todas as permutações são diferentes
	for (; c != size; i = (i+1)%size, j = (j+1)%size, ++c) {
		if (str[i] == str[j]) continue;
		return (str[i] - str[j]); // Positivo se x for maior, negativo se for menor
	}
	return 0; // 0 caso sejam iguais
}

/** 
* QuickSort da biblioteca padrão do C, utilizando 
* uma função de comparação normal entre strings.
*/
void quickSort (uint* data, uint dataSize, byte* orig) {
	str = orig;
	size = dataSize;
	qsort(data,size,sizeof(uint),comp);
}

}
