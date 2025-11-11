#include "HuffmanTree.h"

namespace Huff {

//! Cria uma nova árvore com peso w, cuja raiz é um nó com o byte x
HuffmanTree::HuffmanTree(uint w, const byte x) 
	: BinarySearchTree<byte>(), weight(w) {
	insert(x);
}

//! Deep copy de ht
HuffmanTree::HuffmanTree(const HuffmanTree& ht)
	: BinarySearchTree<byte>(ht), weight(ht.weight) { }

/**
* Monta uma nova árvore cuja raiz é indefinida,
* os filhos são h1 e h2 e o peso é a soma dos pesos
* de h1 e h2. Representa a operação join do algoritmo de
* Huffman.
*/
HuffmanTree::HuffmanTree(const HuffmanTree& h1, const HuffmanTree& h2)
	: BinarySearchTree<byte>(h1,h2), weight(h1.weight + h2.weight) { }

/**
* Este operator foi feito para usar as HuffmanTree's dentro de
* uma priority queue. Compara as ávore primeiro pelo peso e depois
* pelo número de filhos.
*/
bool HuffmanTree::operator< (const HuffmanTree& ht) const {
	if (weight != ht.weight)
		return (weight < ht.weight);
	else
		return (size() < ht.size());
}

/**
* Operator feito para colocar Huffman Tree's em Priority Queue's.
* Comparaprimeiro pelo peso, e depois pelo número de filhos.
*/
bool HuffmanTree::operator> (const HuffmanTree& ht) const {
	if (weight != ht.weight)
		return (weight > ht.weight);
	else
		return (size() > ht.size());
}

// Canonical Huffman Code: Só precisa do code length de cada um
// 1 byte serve para representar o code length de cada um

/**
* Monta uma tabela de bytes, previamente alocada, que
* contêm o tamanho do código huffman (altura daquela sub-árvore) para
* cada byte armazenado na árvore. Coloca em nonzero o número de bytes
* para os quais o código existe (não é vazio).
*/
void HuffmanTree::lengthTable(byte*& table, uint& nonzero) const {
	for (uint i = 0; i < 256; ++i)
		table[i] = 0;
	nonzero = 0;
	if (this->root) lengthTable(this->root,table,byte(0),nonzero);
}

//! Helper recursiva para o lengthTable principal
void HuffmanTree::lengthTable(BinarySearchTree<byte>::BNode* pt, byte*& table, byte l, uint& nonzero) const {
	if (!(pt->left || pt->right)) {
		table[pt->data] = l;
		++nonzero;
	}
	else {
		assert((int(l)+1) <= 255);
		lengthTable(pt->left,table,(l+1),nonzero);
		lengthTable(pt->right,table,(l+1),nonzero);
	}
}

//! Hack: Deleta as sub-árvores abaixo de it e seta o byte de it para b.
void HuffmanTree::set_del_under(NavigateIterator<byte>& it, byte b) {
	it.getPt()->data = b;
	deleteTree(it.getPt()->left);
	deleteTree(it.getPt()->right);
}

/**
* Helper para o algoritmo Huffman.
* enche a árvore com valores indefinidos por level níveis.
* Não necessita manter o número de nós.
*/
void HuffmanTree::fillTree(uint level) {
	makeEmpty();
	fillTree(root,0,level);
}

void HuffmanTree::fillTree(BinarySearchTree<byte>::BNode*& pt, uint level, uint max) {
	pt = new BinarySearchTree<byte>::BNode(0);
	if (level != max) {
		fillTree(pt->left,level+1,max);
		fillTree(pt->right,level+1,max);
	}
}

}

