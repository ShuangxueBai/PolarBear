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

void AllocMemoryPool::initMemoryPool()
{
	// allocate Memory list
	const unsigned int kByte = 1024;
	const unsigned int listCount = 8;
	unsigned int baseBit = 1;
	MemoryList* pList = nullptr;
	pList = new MemoryList();
	pList->_size = baseBit * kByte;
	mMemoryList = pList;
	mMemoryListLast = pList;
	baseBit = baseBit << 1;

	while (baseBit < 0x0100)
	{
		pList = new MemoryList();
		pList->_size = baseBit * kByte;
		baseBit = baseBit << 1;
		mMemoryListLast->_next = pList;
		mMemoryListLast = pList;
	}//end while


}

void AllocMemoryPool::releaseMemoryPool()
{

}

void* AllocMemoryPool::allocateBuffer(size_t size)
{

}

bool AllocMemoryPool::freeBuffer(void* pBuffer)
{

}









POLAR_BEAR_END
