#include <ctype.h>
#include <cstring>
#include <memory>
#include "StrHash.h"

POLAR_BEAR_BEGIN

namespace StrHash {

	hash_uint BKDRhash(const char* s)
	{
		register hash_uint hash = 0;
		while (char ch = *s++)
		{
			hash = (hash << 7) + (hash << 1) + hash + (hash_uint)ch;
		}//end while
		return hash;
	}

	hash_uint SDBMhash(const char* s)
	{
		register hash_uint hash = 0;
		while (char ch = *s++)
		{
			hash = (hash << 6) + (hash << 16) - hash + (hash_uint)ch;
		}//end while
		return hash;
	}

	hash_uint RShash(const char* s)
	{
		register hash_uint hash = 0;
		hash_uint magic = 63689;
		while (char ch = *s++)
		{
			hash = hash * magic + (hash_uint)ch;
			magic *= 378551;
		}//end while
		return hash;
	}

	hash_uint APhash(const char* s)
	{
		register hash_uint hash = 0;
		char ch;
		for (long i = 0; ch = *s++; ++i)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ (hash_uint)ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ (hash_uint)ch ^ (hash >> 5)));
			}
		}
		return hash;
	}

	hash_uint JShash(const char* s)
	{
		if (!*s)
			return 0;
		register hash_uint hash = 1315423911;
		while (char ch = *s++)
		{
			hash ^= ((hash << 5) + (hash_uint)ch + (hash >> 2));
		}//end while
		return hash;
	}

	hash_uint FNVhash(const char* s)
	{
		if (!*s)
			return 0;
		register hash_uint hash = 2166136261;
		while (char ch = *s++)
		{
			hash ^= 16777619;
			hash ^= (hash_uint)ch;
		}//end while
		return hash;
	}

	hash_uint DJBhash(const char* s)
	{
		if (!*s)
			return 0;
		register hash_uint hash = 5381;
		while (char ch = *s++)
		{
			hash += (hash << 5) + (hash_uint)ch;
		}//end while
		return hash;
	}

	hash_uint PJWhash(const char* s)
	{
		static const hash_uint totalBits = sizeof(hash_uint) * 8;
		static const hash_uint threeQuarters = (totalBits * 3) / 4;
		static const hash_uint oneEighth = totalBits / 8;
		static const hash_uint highBits = ((hash_uint)-1) << (totalBits - oneEighth);

		register hash_uint hash = 0;
		hash_uint magic = 0;
		while (char ch = *s++)
		{
			hash = (hash << oneEighth) + (hash_uint)ch;
			if ((magic = hash & highBits) != 0)
			{
				hash ^= (magic >> threeQuarters);
				hash &= ~magic;
			}
		}
		return hash;
	}
}

namespace OneWayHash
{
	static hash_ulong cryptTable[0x500] = {0};
	const unsigned int hashTableArraySize = 1024;
    hash_t lpTable[hashTableArraySize];

	hash_ulong StringToHash(const char* s, const unsigned int hashType)
	{
		unsigned char* key = (unsigned char*)s;
		hash_ulong seed1 = 0x7FED7FED, seed2 = 0xEEEEEEEE;
		int ch;

		while (*key != 0)
		{
			ch = toupper(*key++);

			seed1 = cryptTable[(hashType << 8) + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
		}//end while
		return seed1;
	}

	int InsertHashTable(const char* s, hash_t* table, int nTableSize)
	{
		const hash_ulong hash_offset = 0, hash_a = 1, hash_b = 2;
		hash_ulong nHash, nHashA, nHashB;
		int nHashPos;
		int nHashInsertPos = -1;
		int nHashStart;

		nHash = StringToHash(s, hash_offset);
		nHashPos = nHash % nTableSize;
		nHashStart = nHashPos;
		nHashA = StringToHash(s, hash_a);
		nHashB = StringToHash(s, hash_b);

		do 
		{
			if (lpTable[nHashPos]._bExists){
				if (lpTable[nHashPos]._nHashA == nHashA && lpTable[nHashPos]._nHashB == nHashB)
					return 0;
			}
			else{
				nHashInsertPos = nHashPos;
				break;
			}
			++nHashPos;
			nHashPos = nHashPos % hashTableArraySize;
		} while (nHashStart != nHashPos);

		if (nHashInsertPos != -1){
			lpTable[nHashInsertPos]._nHash = nHash;
			lpTable[nHashInsertPos]._nHashA = nHashA;
			lpTable[nHashInsertPos]._nHashB = nHashB;
			lpTable[nHashInsertPos]._bExists = 1;
		}
		return 0;
	}

	int GetHashTablePos(const char* s, hash_t* table, int nTableSize)
	{
		const int hash_offset = 0, hash_a = 1, hash_b = 2;
		hash_ulong nHash = StringToHash(s, hash_offset);
		hash_ulong nHashA = StringToHash(s, hash_a);
		hash_ulong nHashB = StringToHash(s, hash_b);
		hash_ulong nHashStart = nHash % nTableSize;
		hash_ulong nHashPos = nHashStart;

		while (lpTable[nHashPos]._bExists)
		{
			if (lpTable[nHashPos]._nHashA == nHashA && lpTable[nHashPos]._nHashB == nHashB)
				return nHashPos;
			else
				nHashPos = (nHashPos + 1) % nTableSize;
			if (nHashPos == nHashStart)
				break;
		}//end while
		return -1;
	}

	void PrepareCryptTable()
	{
		hash_ulong seed = 0x00100001, index1 = 0, index2 = 0, i;

		for (index1 = 0; index1 < 0x100; ++index1)
		{
			for (index2 = index1, i = 0; i < 5; ++i, index2 += 0x100)
			{
				hash_ulong temp1, temp2;

				seed = (seed * 125 + 3) % 0x2AAAAB;
				temp1 = (seed & 0xFFFF) << 0x10;

				seed = (seed * 125 + 3) % 0x2AAAAB;
				temp2 = (seed & 0xFFFF);

				cryptTable[index2] = (temp1 | temp2);
			}//end for
		}//end for
	}

}

namespace Encryption
{

}


POLAR_BEAR_END
