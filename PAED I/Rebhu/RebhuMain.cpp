#include "RebhuMain.h"


namespace Rebhu {

#ifdef __linux__
const char* RebFile::defaultTmp = "/tmp/";
#else
const char* RebFile::defaultTmp = "C:\\";
#endif

File::File(uint _pos, string _nome, uint _compSize, uint _origSize, uint _huff_x, uint _rle_x, uint _bwt_x) : 
	nome(_nome), pos(_pos), compSize(_compSize),
	origSize(_origSize),
	huff_x(_huff_x), rle_x(_rle_x), bwt_x(_bwt_x) {
}

float File::compressionRatio (void) const {
	long diff = (long)origSize-(long)compSize;
	uint gain = (diff < 0) ? 0u : uint(diff);
	return (100*gain / float(origSize));
}

RebFile::RebFile() {
	tmp = defaultTmp;
}

RebFile::RebFile(const char* nome, bool _novo) {
	open(nome,_novo);
	tmp = defaultTmp;
}

RebFile::~RebFile() {
	close(false);
}

void RebFile::open(const char* nome, bool _novo) {
	novo = _novo;

	string filen(nome);

	if (filen.length() < 5 || filen.substr(filen.length()-4) != ".reb")
		filen.append(".reb");

	if (_novo)
		file.open(filen.c_str(),BitFile::Out,BitFile::New);
	else
		file.open(filen.c_str(),BitFile::In,BitFile::Open);

	inside.clear();
	to_add.clear();
	analize();
}

void RebFile::setTmpDir(string _t) {
	tmp = _t;
}

void RebFile::close(bool com) {
	novo = true;
	if (com) comit();
	file.close();
}

void RebFile::addFile(FileSpec& file) {
	to_add.push_back(file);
}

void RebFile::decompressFile(const string& name, string& dir) {
	list<File>::const_iterator it = inside.begin();
	for (uint i = 0; it != inside.end(); ++it, ++i) {
		if ((*it).nome == name) {
			decompressNth(file,i,dir);
			break;
		}
	}
}
		

// Var global pra ajudar no std::list::remove_if
string str;

template<typename FileT>
bool sameName (FileT& a) {
	return (a.nome == str);
}

bool RebFile::removeFile(string name) {
	uint old = to_add.size();
	str = name; // Seta a var global pra usar no remove_if
	to_add.remove_if(sameName<FileSpec>);
	return (old != to_add.size());
}

void RebFile::analize(void) {
	if (novo || !(file.isOpen())) return;

	file.gotoBegin();
	inside.clear();

	// Sempre é MultiFile (???)
	file.readByte();

	uint numFiles = uint(file.readByte());

	for (uint i = 0; i < numFiles; ++i) {
		file.readByte(); // FullCompressFlag

		string nome = "";
		char b = char(file.readByte());
		while(b) {
			nome.push_back(b);
			b = char(file.readByte());
		}

		uint compSize = file.readInt();
		uint origSize = file.readInt();
		uint huff_x = file.readInt();
		uint rle_x = file.readInt();
		uint bwt_x = file.readInt();
		
		inside.push_back(
			File(i,nome,compSize,origSize,huff_x,rle_x,bwt_x)
		);
		
		file.move(compSize);
	}
	file.gotoBegin();
}


void RebFile::comit(RebhuProgressDialog* pd) {
	if (to_add.empty()) return;

	string orig = file.getName();
		
	if (novo) {
		file << MultiFile << byte(to_add.size());
	}
	else {
		byte num;
		uint endPos;
		
		file.gotoPos(1u);
		num = file.readByte();
		for (uint i = 0; i < num; ++i) {
			while (file.readByte()); // Skip Flag e o nome
			uint compSize = file.readInt();

			for (uint j = 0; j < 4u; ++j) file.readInt(); // Skip uints
			file.move(compSize);
		}
		endPos = file.currentPos();
		file.close();
		
		file.open(orig.c_str(),BitFile::Out,BitFile::Open);

		file.gotoPos(1u);
		file.write(byte(num + byte(to_add.size()))); // Ajeita o contador de arquivos

		file.gotoPos(endPos);
	}
	
	// Neste momento, sendo o arquivo novo ou não,
	// ele estará na posição exata de inserção dos novos arquivos comprimidos
	// com o header correto e em modo Out.
	list<FileSpec>::iterator it;
	for (it = to_add.begin(); it != to_add.end();) {
		FileSpec f(*it);
		BitFile fileA(f.nome.c_str(),BitFile::In,BitFile::Open);
		compress(fileA,file,f.bwtSize,f.rleSize,f.huffSize,pd);
		it = to_add.erase(it);
	}
	
	// Ajeita flag e poe modo In denovo pro analize()
	novo = false;
	file.close();
	file.open(orig.c_str(),BitFile::In,BitFile::Open);

	analize();
}

bool RebFile::hasModifications(void) const {
	return (!to_add.empty());
}

bool RebFile::isOpen(void) const {
	return (file.isOpen());
}

string RebFile::getName(void) {
	return (file.getName());
}

/** 
* Implementações das funções
*/

string removePath(string original) {
	string out(original);
	std::size_t pos = out.rfind('/');

	#ifdef WIN32
		pos = out.rfind('\\');
	#endif

	if (pos != string::npos)
		out.erase(0,pos+1);

	return out;
}

void decompressNth (BitFile& fileA, uint pos, string& dir) {
	if (!fileA.isOpen()) return;
	fileA.gotoBegin();
	
	fileA.readByte();
	if (pos >= uint(fileA.readByte())) 
		return;

	for (uint i = 0; i < pos; ++i) {
		// Pula flag e nome
		while (fileA.readByte());

		uint compSize = fileA.readInt();
		for (uint i = 0; i < 4; ++i) fileA.readInt();

		fileA.move(compSize);
	}
	
	decompress(fileA,dir);

}

string uint_to_string (uint x) {
	if (x == 0) return string("0");
	string num = "";
	while (x) {
		char tmp[2];
		tmp[0] = char('0' + (x % 10));
		tmp[1] = '\0';
		num.insert(0,tmp);
		x /= 10;
	}
	return num;
}
	
void compress (BitFile& fileA, BitFile& fileB, uint bwtSize, uint rleSize, uint huffSize, RebhuProgressDialog* pd) {
	BurrowsWheeler bwt;
	RunLength rle;
	HuffmanCoder huff;
	byte *buffA = 0, *filebuff = 0;

	if (pd)	pd->setFile(removePath(fileA.getName()));

	uint tmp = fileA.size();

	uint filebuffsize = 2*tmp, pos = 0;
	filebuff = new byte[filebuffsize];

	uint bwt_x = (tmp/bwtSize) + ((tmp%bwtSize)?1:0);

	//cout << "Compactação" << endl;

	//cout << "BWT Coding (" << bwt_x << " blocks)" << endl;


	if (pd) {
		pd->setMinMax(0,10000);
		pd->setStep(10000/bwt_x);
		pd->reset();
	}
	

	// BWT BLocks
	uint size = bwtSize, sizetmp = 0;
	for (uint i = 0; i < bwt_x; ++i) {
		
		if (pd)
			pd->setOperation(string("BWT Encoding [bloco " + uint_to_string(i+1) + ']'));
		
		//cout << "\tBloco " << i+1 << "..." << flush;
		buffA = fileA.readBytes(size);
		bwt.setCode(buffA,size);
		bwt.getEncoded(sizetmp,filebuff+pos);
		pos += sizetmp;

		delete[] buffA;
		//cout << " Done!" << endl;
		
		if (pd) pd->step();
		
	}

	// RLE Blocks
	filebuffsize = pos;

	// Com relação ao que tá em filebuff, saído do BWT Blocks
	uint rle_x = (pos/rleSize) + ((pos%rleSize)?1:0); pos = 0;
	byte* tmpbuff = new byte[filebuffsize+filebuffsize/2]; uint tmpPos = 0;

	//cout << "Rle Coding (" << rle_x << " blocks)" << endl;

	if (pd) {
		pd->setMinMax(0,10000);
		pd->setStep(10000/rle_x);
		pd->reset();
	}


	for (uint i = 0; i < rle_x; ++i) {
		
		if (pd)
			pd->setOperation(string("RLE Encoding [bloco " + uint_to_string(i+1) + ']'));
		
		//cout << "\tBloco " << i+1 << "..." << flush;	
		uint diff = filebuffsize - pos;
		if (diff < rleSize) {
			rle.setCode(filebuff+pos,diff);
			pos += diff;
		}
		else {
			rle.setCode(filebuff+pos,rleSize);
			pos += rleSize;
		}
		rle.getEncoded(size,tmpbuff+tmpPos);
		tmpPos += size;
		//cout << " Done!" << endl;
		
		if (pd) pd->step();
		
	}

	pos = 0;
	for (uint i = 0; i < tmpPos; ++i)
		filebuff[pos++] = tmpbuff[i];
	delete[] tmpbuff;

	// Huff Blocks
	filebuffsize = pos;
	uint huff_x = (pos/huffSize) + ((pos%huffSize)?1:0); // Com relação ao filebuff, saído do Rle Blocks
	pos = 0;

	/* NOTE:
	* Neste momento, tem que escrever em fileB
	* o cabeçalho relativo à compactação
	*/
	
	fileB << FullCompressFlag;

	string fileName = removePath(fileA.getName());
	for (uint i = 0; i < fileName.length(); ++i)
		fileB << byte(fileName[i]);
	fileB << byte(0u);

	uint compressedSizePos = fileB.currentPos();

	fileB.move(4);
	fileB << tmp << huff_x << rle_x << bwt_x;

	uint compressedPos = fileB.currentPos();

	//cout << "Huffman Coding (" << huff_x << " blocks)" << endl;

	if (pd) {
		pd->setMinMax(0,10000);
		pd->setStep(10000/huff_x);
		pd->reset();
	}


	for (uint i = 0; i < huff_x; ++i) {
		
		if (pd)
			pd->setOperation(string("Huffman Encoding [bloco " + uint_to_string(i+1) + ']'));
		
		//cout << "\tBloco " << i+1 << "..." << flush;
		uint diff = filebuffsize - pos;
		if (diff < huffSize) {
			huff.setCode(filebuff+pos,diff);
			pos += diff;
		}
		else {
			huff.setCode(filebuff+pos,huffSize);
			pos += huffSize;
		}
		huff.getEncoded(fileB);
		//cout << " Done!" << endl;
		
		if (pd)
			pd->step();
		
	}
	//cout << endl;
	fileB.flush();
	
	uint compressedEndPos = fileB.currentPos();

	// Completa o cabeçalho
	fileB.gotoPos(compressedSizePos);
	fileB << uint(compressedEndPos-compressedPos);
	fileB.gotoPos(compressedEndPos);

	delete[] filebuff;

}

void decompress (BitFile& fileA, string path) {
	BitFile fileB;
	BurrowsWheeler bwt;
	RunLength rle;
	HuffmanCoder huff;
	byte *filebuff = 0, *filebuffB = 0;

	fileA.readByte();

	char* nome = new char[400];
	uint p = 0;
	for(;;) {
		nome[p++] = char(fileA.readByte());
		if (!nome[p-1]) break;
	}
	if (path.empty())
		fileB.open(nome,BitFile::Out,BitFile::New);
	else
		fileB.open((path+nome).c_str(),BitFile::Out,BitFile::New);
	delete[] nome;

	//cout << "File: " << fileB.getName() << endl;
	//cout << "Descompactação" << endl;

	// Header específico da compressão
	fileA.readInt(); // compressedSize
	uint fileSize = fileA.readInt();
	uint huff_x = fileA.readInt();
	uint rle_x = fileA.readInt();
	uint bwt_x = fileA.readInt();

	// Huffman Decoding
	filebuff = new byte[fileSize+fileSize/2];
	uint pos = 0, size = 0, sizetmp = 0, pos2 = 0;

	//cout << "Huffman Decoding (" << huff_x << " blocks)" << endl;

	for (uint i = 0; i < huff_x; ++i) {
		//cout << "\tBloco " << i+1 << "..." << flush;
		huff.getDecoded(size,fileA,filebuff+pos);
		pos += size;
		//cout << " Done!" << endl;
	}

	fileA.ignorePadBits();

	// Rle Decoding
	filebuffB = new byte[fileSize+fileSize/2];
	pos = 0; size = 0; sizetmp = 0; pos2 = 0;

	//cout << "RLE Decoding (" << rle_x << " blocks)" << endl;

	for (uint i = 0; i < rle_x; ++i) {
		//cout << "\tBloco " << i+1 << "..." << flush;
		rle.setCode(filebuff+pos2,0);
		rle.getDecoded(size,sizetmp,filebuffB+pos);

		pos += size;
		pos2 += sizetmp;
		//cout << " Done!" << endl;
	}
	delete[] filebuff;

	// BWT Decoding
	pos = size = 0;

	//cout << "BWT Decoding (" << bwt_x << " blocks)" << endl;

	for (uint i = 0; i < bwt_x; ++i) {
		//cout << "\tBloco " << i+1 << "..." << flush;
		bwt.setCode(filebuffB+pos,0);
		bwt.getDecoded(fileB,size);
		pos += size;
		//cout << " Done!" << endl;
	}
	delete[] filebuffB;

	//cout << endl;

}

}
