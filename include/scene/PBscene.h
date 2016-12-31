//! Polar Bear
#ifndef POLAR_BEAR_SCENE_H
#define POLAR_BEAR_SCENE_H

#include "PBdefine.h"
#include "base/PBbase.h"
#include "scene/_sceneExport.h"
#include "scene/PBnode.h"

POLAR_BEAR_BEGIN

class SCENE_EXT PBscene : public PBobject
{
public:
	PBscene();
	virtual ~PBscene();

	virtual void addNode(PBnode* node);
	

private:
	class PBsceneImp;
	PBsceneImp* _imp;
};

POLAR_BEAR_END

#endif

