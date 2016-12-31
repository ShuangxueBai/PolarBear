#ifndef POLAR_BEAR_TREE_H
#define POLAR_BEAR_TREE_H
#include "base/_baseExport.h"
#include "PBdefine.h"

POLAR_BEAR_BEGIN


template<typename T>
struct PBtreeNode
{
	T _data;
	std::list<PBtreeNode*> _subNode;
};

template<typename T, int n>
struct PBtree 
{


};

POLAR_BEAR_END

#endif

