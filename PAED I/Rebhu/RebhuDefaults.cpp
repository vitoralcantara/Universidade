#include "RebhuDefaults.h"

namespace Rebhu {

byte charBits = CHAR_BIT;
byte maxByte = UCHAR_MAX;
uint maxUInt = UINT_MAX;

EncodeError::EncodeError(const char* m) {
	msg = m;
}

EncodeError::~EncodeError() throw() { 
}

const char* EncodeError::what() const throw() { 
	return msg.c_str(); 
}

DecodeError::DecodeError(const char* m) {
	msg = m;
}

DecodeError::~DecodeError() throw() { 
}
	
const char* DecodeError::what() const throw() { 
	return msg.c_str(); 
}

/** 
* Converte um unsigned int para um byte 
* array alocado dinâmicamente.
* A notação utilizada é inversa à notação utilizada pelos
* compiladores em geral, para facilitar a conversão.
*/
byte* UInt::toByte(uint x) {
	byte* bin = new byte[4];
	for (int i = 0; i < 4; ++i) 
		bin[i] = 0;
	int numByte = 0, numBit = 0;
	uint y = x;
	while (y) {
		bin[numByte] |= (((y&1)?128:0) >> numBit++);
		y >>= 1;
		if (numBit == 8) {
			numBit = 0;
			++numByte;
		}
	}
	return bin;
}

/** 
* Converte um array de bytes para um unsigned int.
* Pode vir tanto do UInt::toByte como da classe BitArray.
*/
uint UInt::fromByte(byte* arr, const int& size) {
	uint x = 0, factor = 1;
	for (int i = 0; i < size; ++i)
		for (int b = 0; b < 8; ++b, factor <<= 1)
			x += ((arr[i] & (128 >> b)) ? 1 : 0) * factor;
	return x;
}

}
