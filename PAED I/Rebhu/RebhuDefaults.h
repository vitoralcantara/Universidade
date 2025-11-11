/**
* @file RebhuDefaults.h
* @author Giuliano Vilela
* Definição do tipo byte principal utilizado pelo programa
* e também de uma classe de conversão entre byte arrays e uint's.
* Um pouco obsoleta devido à classe BitArray da BitLib, porém mantida
* por compatibilidade com alguns trechos de código.
*/

#ifndef _REBHU_DEFAULTS
#define _REBHU_DEFAULTS

#include <climits>
#include <exception>
#include <string>
using std::exception;
using std::string;

namespace Rebhu {

	//! Tipo byte principal, utilizado ao longo do programa
	typedef unsigned char byte;
	typedef bool bit;

	//! Exceção jogada pela UInt
	class EncodeError : public exception {
		public:
			EncodeError(const char* m = "There was an error when encoding the file.");
			~EncodeError() throw();
			const char* what() const throw();
		private:
			string msg;
	};

	//! Exceção jogada pela UInt
	class DecodeError : public exception {
		public:
			DecodeError(const char* m = "There was an error when decoding the file.");
			~DecodeError() throw();
			const char* what() const throw();
		private:
			string msg;
	};

	//! Classe "estática" para conversões entre unsigned int e byte array's
	class UInt {
		public:
			static byte* toByte (uint x);
			static uint fromByte (byte* arr, const int& size = 4);
	};

}

#endif
