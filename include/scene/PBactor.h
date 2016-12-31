//!Polar Bear
#ifndef POLAR_BEAR_ACTOR_H
#define POLAR_BEAR_ACTOR_H

#include "PBdefine.h"
#include "scene/_sceneExport.h"
#include "scene/PBnode.h"
#include <string>
using std::string;
POLAR_BEAR_BEGIN

class SCENE_EXT PBactor : public PBnode
{
public:
	PBactor();
	virtual ~PBactor();

	virtual void draw();

protected:
	string _name;

};

POLAR_BEAR_END

#endif