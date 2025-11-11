#ifndef _BIT_FILE_H
#define _BIT_FILE_H

#include <cstdio>

#include <exception>
#include <string>
using std::exception;
using std::string;

#include "BitArray.h"
#include "RebhuDefaults.h"
using BitLib::_bit;
using BitLib::BitArray;
using Rebhu::byte;

namespace BitLib {

/**
* Exceção principal da classe BitFile.
* Esta exceção é propagada quando uma operação inválida
* é executada no BitFile (com um estado inválido, possivelmente).
* Geralmente, a mensagem mais descritiva da exceção (incluindo o método que a jogou),
* é incluída dentro da string msg.
*/
class BadFileAcess : public exception {
	public:
		BadFileAcess(const char* m = "Acess operation on invalid file.", const char* fileName = "") : msg(m), name(fileName) { }
		~BadFileAcess() throw() { }
		const char* what() const throw() { return (msg+" - "+name).c_str(); }
		const char* fileName() const { return name.c_str(); }
	private:
		string msg, name;
};

/**
* Esta classe representa um verdadeiro arquivo binário.
* Todas as operações são baseadas na escrita de bits/bytes.
* Deste modo, é possível escrever no arquivo de bit em bit,
* e a classe toma conta de adicionar bits de padding no final
* para completar a escrita em bytes exigidas pelo sistema operacional.
*/
class BitFile {
	public:
		BitFile(); 
		BitFile(const char* name, bool in, bool novo = true);
		~BitFile();	
		void open(const char* name, bool inFlag, bool novo = true);

		BitFile& operator<<(bool v);
		BitFile& operator<<(byte b);
		BitFile& operator<<(uint i);
		BitFile& operator<<(BitArray& ba);
		BitFile& operator<<(_bit b);

		BitFile& operator>>(bool& b);
		BitFile& operator>>(_bit& b);
		BitFile& operator>>(byte& b);
		BitFile& operator>>(uint& i);
		BitFile& operator>>(BitArray& ba);

		void write(int i);
		void write(uint i, uint numbits = 32);
		void write(bool v);
		void write(_bit b);
		void write(byte b);
		void write(byte* b, uint size);
		void write(BitArray& ba);
		
		uint readInt(uint numbits = 32);
		bool readBit(void);
		byte readByte(void);
		byte* readBytes(uint& size);
		BitArray readArray(uint size = 8);

		void clearBuffer(void);
		void flush(void);

		bool eof(void) const;
		void close(void);
		uint size(void);

		void move(long long lenght);
		void gotoPos(uint pos);
		void gotoBegin(void);
		void gotoEnd(void);
		uint currentPos(void);
		void ignorePadBits(void);

		const string& getName(void) const;
		const bool isOpen(void) const;

		static const bool In = true;
		static const bool Out = false;

		static const bool New = true;
		static const bool Open = false;

	private:
		BitFile(const BitFile& cp) { cp.getName(); }
		FILE* file;
		byte buff;
		int bitpos;
		string nome;
		bool _open, _in;
};

}

#endif
