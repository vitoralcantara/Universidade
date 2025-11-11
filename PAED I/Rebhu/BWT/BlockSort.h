#ifndef _BLOCK_SORT_BWT
#define _BLOCK_SORT_BWT

#include <cstdlib>
#include <queue>
using std::queue;

typedef unsigned char byte;

/**
* Contêm funções experimentais de ordenação
* para o BWT, de modo à otimizar o seu desempenho.
*/
namespace BlockSort {

void quickSort (uint* data, uint dataSize, byte* orig);
void lsdRadixSort (byte* orig, uint*& data, uint _size);

void countSort (uint*& data, uint size, uint dig);
void bucketSort (uint* data, uint size, uint dig);
inline byte get(uint& first, uint& pos);
int comp(const void* x, const void* y);

}

#endif
