//! Polar Bear
#ifndef POLAR_BEAR_MEM_ALLOCATION_POOL_H
#define POLAR_BEAR_MEM_ALLOCATION_POOL_H

#include "PBdefine.h"
#include "base/_baseExport.h"
#include "base/PBtypes.h"

POLAR_BEAR_BEGIN

BASE_EXT bool InitMemAllocPool();
BASE_EXT void DestroyMemAllocPool();

BASE_EXT void* MemoryAlloc(const pbulong size);
BASE_EXT void MemoryFree(void* buffer);


POLAR_BEAR_END

#endif
