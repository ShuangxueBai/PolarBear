#include "PBsceneImp.h"

POLAR_BEAR_BEGIN

PBscene::PBscene()
	:_imp(new PBsceneImp())
{

}

PBscene::~PBscene()
{
	PB_DELETE_PTR(_imp)
}

void PBscene::addNode(PBnode* node)
{
	_imp->addNode(node);
}

POLAR_BEAR_END