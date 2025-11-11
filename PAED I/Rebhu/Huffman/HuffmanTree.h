#ifndef _HUFF_TREE
#define _HUFF_TREE

#include <cmath>
#include <cassert>

#include "RebhuDefaults.h"
using Rebhu::byte;

#include "BST/BinarySearchTree.h"
using BST::BinarySearchTree;
using BST::NavigateIterator;

namespace Huff {

/**
* Representa um árvore codificadora Huffman
* Para todos os efeitos, é uma BinarySearchTree<Byte>, porém com o diferencial
* de alguns métodos helpers para o algoritmo e também o fato de guardar um campo
* adicional, que é o peso da árvore. Esta médida de peso de cada árvore é essencial
* para o algoritmo de Huffman.
*/
class HuffmanTree : public BinarySearchTree<byte> {
	public:
		HuffmanTree(uint w = 0, const byte x = 0);
		HuffmanTree(const HuffmanTree&);
		HuffmanTree(const HuffmanTree&, const HuffmanTree&);
		bool operator< (const HuffmanTree&) const;
		bool operator> (const HuffmanTree&) const;
		void lengthTable(byte*&, uint&) const;
		void fillTree(uint level);
		void set_del_under(NavigateIterator<byte>&, byte);
	protected:
		void fillTree(BinarySearchTree<byte>::BNode*&,uint, uint);
		void lengthTable(BinarySearchTree<byte>::BNode*, byte*&, byte, uint&) const;
	private:
		uint weight;
	friend class NavigateIterator<byte>;
};

}

#endif
