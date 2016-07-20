//PBbase

#ifndef POLAR_BEAR_ALLOCATE_MEMORY_POOL_H
#define POLAR_BEAR_ALLOCATE_MEMORY_POOL_H

#include <memory>
#include "platform.h"

POLAR_BEAR_BEGIN

struct MemoryBlock 
{
	MemoryBlock* _next;
	MemoryBlock* _prev;
	void* _brick;
	MemoryBlock()
		: _next(nullptr)
		, _prev(nullptr)
		, _brick(nullptr){}
};

struct MemoryList 
{
	unsigned int _size;
	MemoryList* _next;
	MemoryBlock* _free;
	MemoryBlock* _freeLast;
	MemoryBlock* _used;
	MemoryBlock* _usedLast;

	MemoryList()
		: _size(0)
		, _next(nullptr)
		, _free(nullptr), _freeLast(nullptr)
		, _used(nullptr), _usedLast(nullptr){}
};

class BASE_EXT AllocMemoryPool
{
public:
	static AllocMemoryPool& GetInstance();
	static void DestroyInstance();

	~AllocMemoryPool();
	void releaseMemoryPool();

	void* allocateBuffer(const unsigned int& size);
	bool  freeBuffer(void* pBuffer);
private:
	AllocMemoryPool();
	void initMemoryPool();
private:
	static AllocMemoryPool* mMemoryPool;
	MemoryList* mMemoryList;
	MemoryList* mMemoryListLast;
};

POLAR_BEAR_END
#endif