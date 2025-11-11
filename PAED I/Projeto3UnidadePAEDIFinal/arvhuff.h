#ifndef ARVHUFF_H
#define ARVHUFF_H
#include <iostream>
using namespace std;
//tipo de dado de cada no do ArvHuff
typedef struct noHuff
{
        cP info;
        noHuff *left;
        noHuff *right;
}huf;

//Arvore de codificação Huffman
class ArvHuff
{
	private:
            huff * ptPai;
    public:
		ArvHuff();
		ArvHuff(
		~ArvHuff();
};

#endif // ARVHUFF_H
