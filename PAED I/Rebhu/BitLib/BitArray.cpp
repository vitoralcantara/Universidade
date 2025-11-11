#include <cstdio>

#include "BitArray.h"

namespace BitLib {

//! Constrói um BitArray de s bits
BitArray::BitArray(const uint s) {
	arrSize = (s/8) + ((s%8 != 0) ? 1:0);
	array = new byte[arrSize];
	_size = s;
	reset();
}

//! Constroi um BitArray com os 8 bits de b
BitArray::BitArray(const byte& b) {
	arrSize = 1;
	array = new byte[1];
	array[0] = b;
	_size = 8;
}

//! Constroi um BitArray com os size bytes de b
BitArray::BitArray(byte* b, const uint& size) {
	arrSize = size;
	array = new byte[size];
	for (uint i = 0; i < size; ++i)
		array[i] = b[i];
	_size = 8*size;
}

//! Constrói um BitArray que é um deep copy de cp
BitArray::BitArray(const BitArray& cp) {
	arrSize = cp.arrSize;
	array = new byte[arrSize];
	for (uint i = 0; i < arrSize; ++i)
		array[i] = cp.array[i];
	_size = cp._size;
}

//! Desaloca memória utilizada
BitArray::~BitArray() {
	delete[] array;
}

//! Libera memória alocada e faz um deep copy de rhs
BitArray& BitArray::operator=(const BitArray& rhs) {
	delete[] array;
	arrSize = rhs.arrSize;
	array = new byte[arrSize];
	for (uint i = 0; i < arrSize; ++i)
		array[i] = rhs.array[i];
	_size = rhs._size;
	return *this;
}

/** 
* Retorna um objeto da classe _bit que pode 
* alterar o valor do bit naquela posição do array
*/
_bit BitArray::operator[](uint pos) {
	return _bit(pos,this);
}

//! Tamanho do BitArray
uint BitArray::size(void) const {
	return _size;
}

//! Retorna o valor lógico do bit na posição pos
bool BitArray::getBit(uint pos) const {
	uint bytePos = pos / 8;
	uint bitPos = pos % 8;
	if (bytePos >= arrSize || bitPos + bytePos*8 >= _size) 
		throw InvalidBitPos();
	return (array[bytePos] & (128 >> bitPos));
}

//! Seta o valor lógico do bit na posição pos para ser equivalente à v
void BitArray::setBit(uint pos, bool v) {
	uint x = v ? 128 : 0;
	uint bytePos = pos/8;
	uint bitPos = pos%8;
	if (bytePos >= arrSize || bitPos + bytePos*8 >= _size) 
		throw InvalidBitPos();
	byte b = array[bytePos];
	if ((b & (128 >> bitPos)) && !x)
		array[bytePos] = b xor (128 >> bitPos);
	else
		array[bytePos] |= (x >> bitPos);
}

//! Reseta todos os bits do array para 0
void BitArray::reset(void) {
	for (uint i = 0; i < arrSize; ++i)
		array[i] = byte(0);
}

//! Seta todos os bits do array para 1
void BitArray::preset(void) {
	for (uint i = 0; i < arrSize; ++i)
		array[i] = ~(byte(0));
}

//! Retorna uma cópia (alocada no heap) do array interno de bytes
byte* BitArray::getArray(void) const {
	byte* novo = new byte[arrSize];
	for (uint i = 0; i < arrSize; ++i)
		novo[i] = array[i];
	return novo;
}

/**
* Interpreta o BitArray como sendo um unsigned int
* Só levam em consideração até o limite do BitArray: _size
* O espaço desperdiçado no final não é considerado.
*/
uint BitArray::toUint(void) const {
	uint x = 0, factor = 1;
	for (uint i = 0; i < _size; ++i, factor <<= 1)
		x += (getBit(i)?1:0) * factor;
	return x;
}

/**
* Inicializa o BitArray com os bits do uint x.
* Este método só copia _size bits do uint x, ou seja,
* pode haver truncamento de o BitArray for pequeno demais para x.
*/
void BitArray::fromUint(uint x) {
	uint y = x, c = 0;
	if (y > uint((1u << _size)-1))
		throw InvalidUintRange();
	while (y && c < _size) {
		setBit(c++,bool(y & 1));
		y >>= 1;
	}
}

/**
* Um _bit é associado à uma posição de um BitArray.
* Dessa maneira, tem acesso para ler e para setar o bit
* naquela posição
*/
_bit::_bit(uint p, BitArray* arr) : pos(p), bitarr(arr) {
}

_bit& _bit::operator=(const int& x) {
	bitarr->setBit(pos,bool(x));
	return *this;
}

_bit& _bit::operator=(const bool& x) {
	bitarr->setBit(pos,x);
	return *this;
}

_bit& _bit::operator=(const _bit& cp) {
	bitarr->setBit(pos,bool(cp));
	return *this;
}

//! Interpreta o valor lógico do bit como sendo um bool
_bit::operator bool() const {
	return (bitarr->getBit(pos));
}

}
