/**
* Rebhu
* @author Giuliano Vilela
*/

#ifndef _REBHU_MAIN
#define _REBHU_MAIN

// libstdc++
#include <cassert>
#include <string>
#include <list>
using std::string;
using std::list;

// librebhu
#include "RebhuDefaults.h"
#include "BWT/BurrowsWheeler.h"
#include "RLE/Rle.h"
#include "Huffman/Huffman.h"
#include "BitLib/BitFile.h"
#include "BitLib/BitArray.h"
using Rebhu::byte;
using Rebhu::UInt;
using BitLib::BitFile;
using BitLib::BitArray;
using BWT::BurrowsWheeler;
using RLE::RunLength;
using Huff::HuffmanCoder;

#include "rebhuProgressDialog.h"

#define mb(x) ((x)*1024u*1024u)
#define kb(x) ((x)*1024u)

namespace Rebhu {

// Macros e constantes
const uint bwtSize = kb(200);
const uint rleSize = mb(10);
const uint huffSize = kb(100);

/**
* Helper dependente da plataforma.
* Recebe um caminho para um arquivo (filepath)
* e retorna somente a parte que contêm o nome do arquivo
* em si (sem caminho de diretórios)
*/
string removePath(string original);

/**
* Função chave de compactação do Rebhu.
* Compacta fileA em fileB, utilizando os tamanhos de bloco especificados
* e mantêm a RebhuProgressDialog atualizando as informações de compactação.
*/
void compress (BitFile& fileA, BitFile& fileB, uint bwtSize, uint rleSize, uint huffSize,RebhuProgressDialog* pd);

/**
* Função chave de descompactação do Rebhu.
* Descompacta fileA no diretório path.
* Note que esta função recebe o fileA na posição correta para a descompactação
* no arquivo daquela posição. fileA pode conter mais de um arquivo interno compactado,
* porém esta função só descompacta o arquivo na posição atual.
*/
void decompress (BitFile& fileA, string path = "");

/**
* Recebe o fileA em qualquer posição e descompacta o 
* arquivo na posição interna pos (de 0 à numFiles-1) no diretório dir.
*/
void decompressNth (BitFile& fileA, uint pos, string& dir);

//! Byte indicador de arquivo compactado
const byte FullCompressFlag = 7;
//! Byte indicar de arquivo sem compactação
const byte NoCompressFlag = 0;
//! Byte indicador de um arquivo com múltiplos compactados
const byte MultiFile = (1 << 7);

/**
* Esta é uma classe simples semelhante à struct
* que armazena informações sobre um arquivo interno
* de um .reb. Todas as informações que esta classe armazena
* podem ser recuperadas de dentro do arquivo .reb
*/
class File {
	public:
		File(uint _pos, string _nome, uint _compSize, uint _origSize, uint _huff_x = 0, uint _rle_x = 0, uint _bwt_x = 0);
		float compressionRatio (void) const;
		string nome;
		uint pos, compSize, origSize, huff_x, rle_x, bwt_x;
};

/**
* Classe semelhante à File, porém
* simula um arquivo que irá ser adicionado à um RebFile.
* Em vez de números de blocos contêm o tamanho em bytes dos blocos
*/
struct FileSpec {
	string nome;
	uint bwtSize, rleSize, huffSize;
	FileSpec(string n = "", uint bwt = 0, uint rle = 0, uint huff = 0) 
		: nome(n), bwtSize(bwt), rleSize(rle), huffSize(huff) { }
};

/**
* Classe principal do Rebhu.
* Modela a interação entre o código e um arquivo .reb.
* Apresenta métodos para compactar arquivos, extraí-los e remove-los.
* À medida que as operações são feitas, o arquivo original não é modificado.
* Ele só é modificado em uma chamada à comit(), quando todas as operações requisitadas
* são de fato efetuadas no arquivo.
*/
class RebFile {

	public:
		//! Não cria nenhum arquivo.
		RebFile();
		/**
		* Construtor padrão para o RebFile.
		* Interage com o arquivo nome, sendo este novo
		* ou aberto para leitura de acordo com o segundo
		* parâmetro (RebFile::New ou RebFile::Open).
		*/
		RebFile(const char* nome, bool _novo = false);
		virtual ~RebFile();
		//! Abre um arquivo de nome _nome e com a flag do segundo parâmetro
		void open(const char* nome, bool _novo = false);
		//! Realiza as operações requisitadas no RebFile, mostrando o progresso em pd
		void comit(RebhuProgressDialog* pd = 0);
		//! Fecha o arquivo atual. Se com for true, realiza um comit.
		void close(bool com = true);
		//! Seta o diretório temporário para utilização interna da classe
		void setTmpDir(string _t);
		//! Adiciona o arquivo descrito pelo FileSpec ao .reb
		void addFile(FileSpec& file);
		//! Remove o arquivo de nome name da lista interna de adicionação.
		bool removeFile(string name);
		//! Extrai o arquivo de nome name, no diretório dir.
		void decompressFile(const string& name, string& dir);
		//! Checa se há modificações não salvar no arquivo
		bool hasModifications(void) const;
		//! Indica se o arquivo interno está aberto.
		bool isOpen(void) const;
		//! Lista de arquivos que estão dentro do .reb
		list<File> inside;
		//! Lista de descrições de arquivos que ainda serão adicionados no .reb
		list<FileSpec> to_add;
		//! Flag para criar um novo arquivo (trunca ao abrir)
		static const bool New = true;
		//! Flag para abrir um arquivo para leitura (mantêm dados originais)
		static const bool Open = false;
		//! Analiza totalmente o arquivo interno e atualiza a lista de File's.
		void analize(void);
		//! Retorna o nome do arquivo atual
		string getName(void);

	private:
		BitFile file;
		bool novo;
		string tmp;
		static const char* defaultTmp;
};

}

#endif
