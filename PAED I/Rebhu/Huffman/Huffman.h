#ifndef _HUFFMAN_CODER
#define _HUFFMAN_CODER

#include <cassert>
#include <algorithm>
using std::sort;

#include "RebhuDefaults.h"
using Rebhu::byte;

#include "PriorityQueue/PriorityQueue.h"

#include "BitLib/BitFile.h"
#include "BitLib/BitArray.h"
using BitLib::BitFile;
using BitLib::BitArray;

#include "HuffmanTree.h"
using Huff::HuffmanTree;


namespace Huff {
	
/**
* Representa um Huffman Encoder/Decoder
* Apresenta funções para codificar e decodificar um array de bytes
* com algumas opções de otimização.
*/
class HuffmanCoder {
	public:
		/**
		* Cria uma máquina com o código code, de tamanho size.
		* Recebe opcionalmente um array de uint's com as frequencias de cada
		* byte no arquivo.
		*/
		HuffmanCoder(byte* code = 0, uint size = 0u, uint* f = 0);
		virtual ~HuffmanCoder() { }
		//! Seta o buffer interno para code, de tamanho size, com a tabela de frequencia f
		void setCode(byte* code, uint size, uint* f = 0);
		//! Codifica o buffer interno, jogando a saída para o arquivo out
		void getEncoded(BitFile& out);
		//! Decodifica os dados no arquivo in, armzenando em dec
		byte* getDecoded(uint& outSize, BitFile& in, byte* dec = 0);
	protected:
		//! Se necessário, pega a frequência de cada byte no buffer e armazena internamente
		void getFreq();
		/**
		* Monta uma HuffmanTree à partir do buffer interno, armazenando em hufftree
		*/
		void makeHuffmanTree(HuffmanTree& hufftree);
		/**
		* A partir do array de códigos codes, monta a árvore prefixa de huffman
		* que gera aqueles códigos para aqueles bytes. Ajuda na decodificação do arquivo.
		*/
		void makeCanonicalTree(HuffmanTree& ht, BitArray* codes);
		/**
		* A partir de uma tabela de tamanhos de código huffman, monta um
		* array de códigos canônicos, únicos para aquela tabela.
		*/
		BitArray* canonicalCode(byte* lenghtTable);
	private:
		byte* buffer;
		uint buffSize;
		uint* freq;
};

}

#endif
