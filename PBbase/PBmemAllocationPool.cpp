#include "PBmemAllocation.h"

POLAR_BEAR_BEGIN

static MemoryAllocationPool* g_ptrMemAlloc = nullptr;

bool InitMemAllocPool()
{
	if (nullptr == g_ptrMemAlloc)
		g_ptrMemAlloc = new MemoryAllocationPool();
	return (nullptr != g_ptrMemAlloc);
}

pbvoid DestroyMemAllocPool()
{
	PB_DELETE_PTR(g_ptrMemAlloc)
	return;
}

pbvoidpt MemoryAlloc(const ulong size)
{
	return g_ptrMemAlloc->memoryAllocation(size);
}

pbvoid MemoryFree(pbvoidpt buffer)
{
	g_ptrMemAlloc->memoryfree(buffer);
	return;
}

POLAR_BEAR_END


