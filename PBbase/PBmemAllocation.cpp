#pragma comment(lib, "jemalloc.lib")

#include "jemalloc/jemalloc.h"
#include "PBmemAllocation.h"


POLAR_BEAR_BEGIN

MemoryAllocationPool::MemoryAllocationPool()
{

	size_t sz = sizeof(_allocated);
	je_mallctl("stats.active", &_allocated, &sz, NULL, 0);
	je_malloc_stats_print(NULL, NULL, NULL);
	return;
}

MemoryAllocationPool::~MemoryAllocationPool()
{
	je_malloc_stats_print(NULL, NULL, NULL);
	size_t allocated1 = _allocated;
	size_t sz;
	je_mallctl("stats.active", &_allocated, &sz, NULL, 0);
	size_t allocated2 = _allocated;
	
	size_t leaked = allocated2 - allocated1;
	printf("\nDone. Leaked: %zd bytes\n", leaked);
	bool failed = leaked > 65536; // in case C++ runtime allocated (e.g. iostream locale or facet)
	printf("\nTest %s!\n", (failed ? "FAILED" : "successful"));
	return;
}

void* MemoryAllocationPool::memoryAllocation(const pbulong size)
{
	return je_malloc(static_cast<size_t>(size));
}

void MemoryAllocationPool::memoryfree(void* buffer)
{
	je_free(buffer);
	return;
}

POLAR_BEAR_END