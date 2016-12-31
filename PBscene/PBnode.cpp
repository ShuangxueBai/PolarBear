#include "scene/PBnode.h"
#include "resource/_resourceExport.h"
#include "resource/PBresource.h"
#include <algorithm>

POLAR_BEAR_BEGIN

PBnode::PBnode()
	: PBobject()
	, _isDraw(true)
	, _resource(nullptr)
{

}

PBnode::~PBnode()
{
	_resource = nullptr;
}

void PBnode::setResource(PBresource* pResource)
{
	_resource = pResource;
}

void PBnode::addNode(PBnode* node)
{
	PBrefPtr<PBnode> _newNode(node);
	_nodes.push_back(_newNode);
}

void PBnode::removeNode(PBnode* node)
{
	auto itera = std::find(_nodes.begin(), _nodes.end(), node);
	if (itera != _nodes.end())
		itera = _nodes.erase(itera);
}

POLAR_BEAR_END