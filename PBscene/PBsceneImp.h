#ifndef POLAR_BEAR_SCENE_IMP_H
#define POLAR_BEAR_SCENE_IMP_H

#include "PBdefine.h"
#include "scene/PBscene.h"

POLAR_BEAR_BEGIN

class PBscene::PBsceneImp
{
public:
	PBsceneImp();
	~PBsceneImp();

	void addNode(PBnode* node);

};


POLAR_BEAR_END


#endif