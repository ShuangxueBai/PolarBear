#ifndef POLAR_BEAR_STR_HASH_H
#define POLAR_BEAR_STR_HASH_H

#include "PBdefine.h"


POLAR_BEAR_BEGIN

typedef unsigned int hash_uint;
typedef unsigned long hash_ulong;

namespace StrHash
{
	extern hash_uint BKDRhash(const char* s);
	extern hash_uint SDBMhash(const char* s);
	extern hash_uint RShash(const char* s);
	extern hash_uint APhash(const char* s);
	extern hash_uint JShash(const char* s);
	extern hash_uint DEKhash(const char* s);
	extern hash_uint FNVhash(const char* s);
	extern hash_uint DJBhash(const char* s);
	extern hash_uint DJB2hash(const char* s);
	extern hash_uint PJWhash(const char* s);
	extern hash_uint ELFhash(const char* s);
}


namespace OneWayHash
{
	typedef struct hash_s {
		hash_ulong _nHash;
		hash_ulong _nHashA;
		hash_ulong _nHashB;
		int _bExists;
	} hash_t;

	extern const unsigned int hashTableArraySize;
	extern hash_t lpTable[];

	extern void PrepareCryptTable();
	extern hash_ulong StringToHash(const char* s, const unsigned int hashType);
	extern int InsertHashTable(const char* s, hash_t* table, int nTableSize);
	extern int GetHashTablePos(const char* s, hash_t* table, int nTableSize);
}


POLAR_BEAR_END

#endif