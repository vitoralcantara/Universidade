#ifndef _RUNLENGTHENCODING
#define _RUNLENGTHENCODING

#include <cassert>

#include "RebhuDefaults.h"
using Rebhu::UInt;
using Rebhu::byte;

#include "BitLib/BitArray.h"
using BitLib::BitArray;

namespace RLE {

	/**
	* Máquina de codificação/decodificação RLE.
	* Apresenta funções de codificação e decodificação
	* de um buffer interno de bytes.
	*/
	class RunLength {
		public:
			RunLength(byte* code = NULL, uint size = 0u);
			RunLength(const RunLength& cp);
			~RunLength();
			void setCode(byte* code, uint size);
			byte* getEncoded(uint& num, byte* enc = 0);
			byte* getDecoded(uint& outNum, uint& inNum, byte* dec = 0);
		protected:
			void saveFrequency(void);
			byte getControlChar(void);
		protected:
			byte* buff;
			uint buffSize;
	};

}

#endif
