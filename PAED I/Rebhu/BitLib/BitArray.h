/**
* @file BitArray.h
* @author Giuliano Vilela
*/

#ifndef _BIT_ARRAY_H
#define _BIT_ARRAY_H

#include "RebhuDefaults.h"
using Rebhu::byte;

namespace BitLib {


class InvalidBitPos {};
class InvalidUintRange {};


class BitArray; // Pra _bit reconhecer

/**
* Representa um único bit.
* Esta classe é retornada e manipulada pelo operator [] do
* BitArray de modo à habilitar o uso dinâmico do array.
* Ex: bitarray a; a[5] = 1;
* Seta o 6o bit de a.
* O _bit pode ser lido como bool, e pode ser atribuido com int's, bool's e outros _bits
*/
class _bit {
	public:
		_bit(uint p, BitArray* arr);
		_bit& operator=(const int& x);
		_bit& operator=(const bool& x);
		_bit& operator=(const _bit& cp);
		operator bool() const;
	private:
		_bit() { }
		uint pos;
		BitArray* bitarr;
};

/**
* Esta classe representa um array estático de bits.
* Contêm operações de grande facilidade para atribuição
* e leitura de bits arbitrários do array.
*/
class BitArray {
	public:
		BitArray(const uint s = 8);
		BitArray(const byte& b);
		BitArray(byte* b, const uint& size);
		BitArray(const BitArray& cp);
		virtual ~BitArray();

		BitArray& operator=(const BitArray& rhs);
		_bit operator[](uint pos);
		
		uint size(void) const;
		bool getBit(uint pos) const;
		void setBit(uint pos, bool v);
		void reset(void);
		void preset(void);
		
		uint toUint(void) const;
		void fromUint(uint x);

		byte* getArray(void) const;

	private:
		byte* array;
		uint arrSize;
		uint _size;
};

}
#endif
