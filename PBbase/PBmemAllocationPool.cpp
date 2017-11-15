#include "PBmemAllocation.h"

POLAR_BEAR_BEGIN

static MemoryAllocationPool* g_ptrMemAlloc = nullptr;

bool InitMemAllocPool()
{
	if (nullptr == g_ptrMemAlloc)
		g_ptrMemAlloc = new MemoryAllocationPool();
	return (nullptr != g_ptrMemAlloc);
}

void DestroyMemAllocPool()
{
	PB_DELETE_PTR(g_ptrMemAlloc);
	return;
}

void* MemoryAlloc(const pbulong size)
{
	return g_ptrMemAlloc->memoryAllocation(size);
}

void MemoryFree(void* buffer)
{
	g_ptrMemAlloc->memoryfree(buffer);
	return;
}

POLAR_BEAR_END


