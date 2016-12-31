//! Polar Bear
#ifndef POLAR_BEAR_MEM_ALLCOATION_H
#define POLAR_BEAR_MEM_ALLCOATION_H

#include <vector>
#include <map>
#include <list>
#include "base/PBmemAllocationPool.h"

using namespace std;

POLAR_BEAR_BEGIN

class MemoryAllocationPool
{
	PB_DECLARE_NO_COPY(MemoryAllocationPool)
	PB_DECLARE_NO_MOVE(MemoryAllocationPool)

public:
	MemoryAllocationPool();
	~MemoryAllocationPool();

	pbvoidpt memoryAllocation(const ulong size);
	pbvoid memoryfree(pbvoidpt buffer);

private:
	size_t _allocated;
};

POLAR_BEAR_END

#endif