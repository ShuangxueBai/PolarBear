//! Polar Bear
#ifndef POLAR_BEAR_MEM_ALLOCATION_POOL_H
#define POLAR_BEAR_MEM_ALLOCATION_POOL_H

#include "PBdefine.h"
#include "base/_baseExport.h"

POLAR_BEAR_BEGIN

BASE_EXT bool InitMemAllocPool();
BASE_EXT pbvoid DestroyMemAllocPool();

BASE_EXT pbvoidpt MemoryAlloc(const ulong size);
BASE_EXT pbvoid MemoryFree(pbvoidpt buffer);


POLAR_BEAR_END

#endif
