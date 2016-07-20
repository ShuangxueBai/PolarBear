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
	if (nullptr == pList)
		return;
	const unsigned int blockCount = 10;
	pList->_free = new MemoryBlock();
	pList->_free->_brick = (void*)malloc(pList->_size);
	pList->_freeLast = pList->_free;
	for (int i = 1; i < blockCount; ++i)
	{
		MemoryBlock* pBlock = new MemoryBlock();
		pBlock->_brick = (void*)malloc(pList->_size);
		pBlock->_prev = pList->_freeLast;
		pList->_freeLast->_next = pBlock;
		pList->_freeLast = pBlock;
	}//end for
	return;
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
		//init memory block
		sInitMemoryBlock(pList);
		baseBit = baseBit << 1;
		mMemoryListLast->_next = pList;
		mMemoryListLast = pList;
	}//end while
	return;
}

void AllocMemoryPool::releaseMemoryPool()
{

}

void* AllocMemoryPool::allocateBuffer(const unsigned int& size)
{
	MemoryList* pFindList = mMemoryList;
	while (pFindList != nullptr)
	{
		if (pFindList->_size >= size)
			break;
		pFindList = pFindList->_next;
	}//end while

	//find block
	if (pFindList)
	{
		if (pFindList->_freeLast)
		{
			MemoryBlock* pFindBlock = pFindList->_freeLast;
			if (pFindList->_freeLast->_prev)
			{
				pFindList->_freeLast = pFindList->_freeLast->_prev;
				pFindList->_freeLast->_next = nullptr;
				if (pFindList->_usedLast)
				{
					pFindList->_usedLast->_next = pFindBlock;
					pFindBlock->_prev = pFindList->_usedLast;
					pFindList->_usedLast = pFindBlock;
				}
				else
				{
					pFindList->_used = pFindBlock;
					pFindList->_usedLast = pFindBlock;
				}
			}
			else
			{
				//Create block
				pFindList->_free = nullptr;
				pFindList->_freeLast = nullptr;
				if (pFindList->_usedLast)
				{
					pFindList->_usedLast->_next = pFindBlock;
					pFindBlock->_prev = pFindList->_usedLast;
					pFindList->_usedLast = pFindBlock;
				}
				else
				{
					pFindList->_used = pFindBlock;
					pFindList->_usedLast = pFindBlock;
				}
			}
			return pFindBlock->_brick;
		}
		else
		{
			//create block
			MemoryBlock* pFindBlock = new MemoryBlock();
			pFindBlock->_brick = (void*)malloc(pFindList->_size);
			if (pFindList->_usedLast)
			{
				pFindList->_usedLast->_next = pFindBlock;
				pFindBlock->_prev = pFindList->_usedLast;
				pFindList->_usedLast = pFindBlock;
			}
			else
			{
				pFindList->_used = pFindBlock;
				pFindList->_usedLast = pFindBlock;
			}
			return pFindBlock->_brick;
		}
	}
	else
	{
		//create memory list
	}

}

bool AllocMemoryPool::freeBuffer(void* pBuffer)
{

}

POLAR_BEAR_END
