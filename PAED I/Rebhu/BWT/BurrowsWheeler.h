#ifndef _BURROWS_WHEELER_T
#define _BURROWS_WHEELER_T


#include <cstdlib>

#include "RebhuDefaults.h"
using Rebhu::byte;
using Rebhu::UInt;

#include "BitLib/BitFile.h"
using BitLib::BitFile;

//! Algoritmo de codificação BWT - Classe
namespace BWT {

	/**
	* Representa um Burrows Wheeler Transform Encoder/Decoder
	* Apresenta funções para codificar e decodificar um array de bytes
	* com algumas opções de otimização.
	*/
	class BurrowsWheeler {
		public:
			BurrowsWheeler(byte* code = NULL, uint size = 0u);
			BurrowsWheeler(const BurrowsWheeler& cp);
			virtual ~BurrowsWheeler();
			void setCode(byte* code, uint size);
			byte* getEncoded(uint& num, byte* enc = 0);
			void getDecoded(BitFile& out, uint& num);
		protected:
			uint* sortedPermutations(uint& firstPos);
			uint* transformationVector(const uint& blockSize);
		private:
			byte* buff;
			uint buffSize;
	};

}

#endif
