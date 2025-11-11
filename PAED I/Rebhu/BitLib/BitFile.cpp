#include "BitFile.h"

namespace BitLib {

//! Construtor padrão que não abre nenhum arquivo
BitFile::BitFile() {
	_open = false;
}

//! Abre o arquivo name, com as flags de leitura e truncamento passadas
BitFile::BitFile(const char* name, bool in, bool novo) {
	_open = false;
	open(name,in, novo);
}

//! Fecha o arquivo
BitFile::~BitFile() {
	close();
}

/**
* Abre o arquivo de nome "name", com as flags passadas.
* inFlag: BitFile::In ou BitFile::Out
* trunc: BitFile::Trunc (default) ou BitFile::NoTrunc
* A segunda flag só faz sentido para BitFile::Out
*/
void BitFile::open(const char* name, bool inFlag, bool novo) {
	close();
	_in = inFlag;
	if (inFlag) {
		if (novo)
			throw BadFileAcess("Erro: Tentativa de criar um arquivo para leitura",name);
		file = fopen(name,"rb");
		bitpos = 8;
		if (file == NULL)
			throw BadFileAcess("Erro ao abrir o arquivo para leitura", name);
	}
	else {
		file = fopen(name,(novo?"wb":"rb+"));
		bitpos = 0;
		if (file == NULL)
			throw BadFileAcess("Erro ao abrir o arquivo para escrita", name);
	}
	nome = name;
	buff = 0;
	_open = true;
}

/*

NOTE: (operator<<(int))
Há indecição de resolução para as chamadas do operator<< com esse tipo (int) entre
bool, byte e uint. Decisão final é não escrever outro operador,
pois não há realmente suporte para ints, somente para uint's.

NOTE: (Uso de "cout << file.readAlgo() << file.readAlgo() << file.readAlg()")
A ordem em que os argumentos passados nessas chamadas encadeadas são avaliados
não é definida!! Tem que ter cuidado pra não usar essa forma se for ler
mais de uma coisa no mesmo encadeamento! Separando-se as expressões o problema some.

*/

BitFile& BitFile::operator<<(bool v) {
	write(v);
	return *this;
}

BitFile& BitFile::operator<<(byte b) {
	write(b);
	return *this;
}

BitFile& BitFile::operator<<(uint i) {
	write(i);
	return *this;
}

BitFile& BitFile::operator<<(_bit b) {
	write(b);
	return *this;
}

BitFile& BitFile::operator<<(BitArray& ba) {
	write(ba);
	return *this;
}

BitFile& BitFile::operator>>(bool& b) {
	b = readBit();
	return *this;
}

BitFile& BitFile::operator>>(_bit& b) {
	b = readBit();
	return *this;
}

BitFile& BitFile::operator>>(byte& b) {
	b = readByte();
	return *this;
}

BitFile& BitFile::operator>>(uint& i) {
	i = readInt();
	return *this;
}

BitFile& BitFile::operator>>(BitArray& ba) {
	ba = readArray(ba.size());
	return *this;
}

/** 
* Escreve o unsigned int i, com numbits bits (default = 32).
* Note que, na implementação atual, a escrita se dá do bit
* menos significante ao bit mais significante (contrário da 
* notação usual). Nota-se também que está de acordo com a implementação
* das conversões para uint da classe BitArray, de modo que é possível
* interoperar entre elas.
*/
void BitFile::write(uint i, uint numbits) {
	uint y = i, c = 0;
	while (c < numbits) {
		write(bool(y & 1));
		y >>= 1;
		++c;
	}
}

void BitFile::write(int i) {
	write(uint(i));
}

//! Acumula o bit num buffer (byte). Se o buffer estiver cheio, escreve no arquivo
void BitFile::write(bool v) {
	buff |= ((v?128:0) >> (bitpos++));
	if (bitpos == 8) {
		fputc(buff,file);
		buff = 0;
		bitpos = 0;
	}
}

void BitFile::write(_bit b) {
	write(bool(b));
}

//! Se o buffer estiver vazio, escreve o byte direto. Senão, escreve bit-a-bit.
void BitFile::write(byte b) {
	if (bitpos == 0) {
		fputc(b,file);
		buff = 0;
	}
	else {
		for (int i = 7; i >= 0; --i)
			write(bool(b & (1 << i)));
	}
}

//! Se o buffer estiver vazio, escreve direto os bytes. Senão, escreve de um em um.
void BitFile::write(byte* b, uint size) {
	if (bitpos == 0)
		fwrite((const void*)b,sizeof(byte),size,file);
	else
		for (uint i = 0; i < size; ++i)
			write(b[i]);
}

/*
NOTE:
Escreve o BitArray indo do último até o primeiro (reverse),
para compatibilidade com o código de decoding
presente no HuffmanCoder (Huffman/Huffman.h).
*/

void BitFile::write(BitArray& ba) {
	for (int i = ba.size()-1; i >= 0; --i)
		write(bool(ba[i]));
}

//! Lê um unsigned int de numbits bits
uint BitFile::readInt(uint numbits) {
	uint x = 0, factor = 1;
	for (uint i = 0; i < numbits; ++i, factor <<= 1)
		x += (readBit()?1:0) * factor;
	return x;
}

//! Lê um único bit do arquivo
bool BitFile::readBit(void) {
	if (bitpos == 8) {
		if (feof(file))
			throw BadFileAcess("readBit em arquivo com EOF",nome.c_str());
		bitpos = 0;
		buff = fgetc(file);
	}
	return bool(buff & (128 >> bitpos++));
}

//! Lê um byte do arquivo
byte BitFile::readByte(void) {
	if (bitpos == 8) {
		if (feof(file)) throw BadFileAcess("readByte em arquivo com EOF",nome.c_str());
		return fgetc(file);
	}
	byte b = 0;
	for (uint i = 0; i < 8; ++i)
		b |= ((readBit()?128:0) >> i);
	return b;
}

byte* BitFile::readBytes(uint& size) {
	byte* b = new byte[size];
	if (bitpos == 8) {
		size = fread((void*)b,sizeof(byte),size,file);
	}
	else {
		uint i = 0;
		for (; i < size && !eof(); ++i)
			b[i] = readByte();
		size = i;
	}
	return b;
}

BitArray BitFile::readArray(uint size) {
	BitArray ba(size);
	for (uint i = 0; i < size; ++i)
		ba[i] = readBit();
	return ba;
}

bool BitFile::eof(void) const {
	if (!_open) return true;
	if (_in)
		return feof(file);
	else
		throw BadFileAcess("BitFile::eof() em arquivo Out",nome.c_str());
}

void BitFile::close(void) {
	if (!_open) return;
	if (!_in)
		if (bitpos)
			fputc(buff,file);
	fclose(file);
	_open = false;
}

void BitFile::clearBuffer(void) {
	buff = 0;
	bitpos = 0;
}

//! Joga os últimos bits no arquivo e limpa o buffer interno
void BitFile::flush(void) {
	if (!(_open && !_in)) return;
	if (bitpos) {
		fputc(buff,file);
		buff = 0;
		bitpos = 0;
	}
	fflush(file);
}

/**
* Ignora os  bits que iriam ser lidos (estavam no buffer) e
* atualiza o buffer. Esta função é utilizada ao final da leitura de um
* bloco do arquivo, e funciona como um próprio sistema de padding de bits
* do rebhu.
*/
void BitFile::ignorePadBits(void) {
	if (_open && _in && bitpos != 8) {
		bitpos = 0;
		buff = fgetc(file);
	}
}

//! Move o ponteiro de arquivo em relação à posição atual
void BitFile::move(long long lenght) {
	if (!_open)
		throw BadFileAcess("BitFile::move() : Arquivo fechado",nome.c_str());
	if (fseek(file,lenght,SEEK_CUR) != 0)
		throw BadFileAcess("BitFile::move() : failbit setado no BitFile",nome.c_str());
}

//! Move o ponteiro de arquivo para a posição pos
void BitFile::gotoPos(uint pos) {
	if (!_open)
		throw BadFileAcess("BitFile::gotoPos() : Arquivo fechado",nome.c_str());
	if (fseek(file,pos,SEEK_SET) != 0)
		throw BadFileAcess("BitFile::gotoPos() : failbit setado no BitFile",nome.c_str());
}

//! Move o ponteiro de arquivo para o início do arquivo
void BitFile::gotoBegin(void) {
	if (!_open)
		throw BadFileAcess("BitFile::gotoBegin() : Arquivo fechado",nome.c_str());
	if (fseek(file,0,SEEK_SET) != 0)
		throw BadFileAcess("BitFile::gotoBegin() : failbit setado no BitFile",nome.c_str());
}

//! Move o ponteiro de arquivo para o final do arquivo
void BitFile::gotoEnd(void) {
	if (!_open)
		throw BadFileAcess("BitFile::gotoEnd() : Arquivo fechado",nome.c_str());
	if (fseek(file,0,SEEK_END) != 0)
		throw BadFileAcess("BitFile::gotoEnd() : failbit setado no BitFile",nome.c_str());
}

//! Retorna a posição absoluta atual do arquivo
uint BitFile::currentPos(void) {
	if (!_open)
		throw BadFileAcess("BitFile::currentPos() : Arquivo fechado",nome.c_str());
	long s = ftell(file);
	if (s == -1)
		throw BadFileAcess("BitFile::currentPos() : failbit setado no BitFile",nome.c_str());
	return s;
}

//! Para arquivos de leitura, retorna o tamanho total do arquivo em bytes
uint BitFile::size(void) {
	if (!(_open && _in))
		throw BadFileAcess("BitFile::size() : Arquivo aberto para escrita",nome.c_str());
	uint old = currentPos();
	gotoEnd();
	uint size = currentPos();
	gotoPos(old);
	return size;
}

//! Retorna o nome do arquivo aberto
const string& BitFile::getName(void) const {
	if (!_open)
		throw BadFileAcess("BitFile::getName() : Arquivo fechado",nome.c_str());
	return nome;
}

//! Checa se o arquivo está aberto
const bool BitFile::isOpen(void) const {
	return _open;
}

}
