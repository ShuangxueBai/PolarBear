#include "allocMemoryPool.h"

POLAR_BEAR_BEGIN


AllocMemoryPool* mMemoryPool = nullptr;
AllocMemoryPool& AllocMemoryPool::GetInstance()
{
	if (nullptr == mMemoryPool)
		mMemoryPool = new AllocMemoryPool();
	return *mMemoryPool;
}

void AllocMemoryPool::DestroyInstance()
{
	if (mMemoryPool)
	{
		delete mMemoryPool;
		mMemoryPool = nullptr;
	}
}

AllocMemoryPool::AllocMemoryPool()
	: mMemoryList(nullptr)
	, mMemoryListLast(nullptr)
{
	initMemoryPool();
}

AllocMemoryPool::~AllocMemoryPool()
{
	releaseMemoryPool();
}

static void sInitMemoryBlock(MemoryList* pList)
{

}

void AllocMemoryPool::initMemoryPool()
{

}

void AllocMemoryPool::releaseMemoryPool()
{

}

void* AllocMemoryPool::allocateBuffer(const unsigned int& size)
{
	return nullptr;
}

bool AllocMemoryPool::freeBuffer(void* pBuffer)
{
	return true;
}

POLAR_BEAR_END
