#ifndef POLAR_BEAR_OBJECT_H
#define POLAR_BEAR_OBJECT_H
#include "base/PBrefptr.h"
POLAR_BEAR_BEGIN

class BASE_EXT PBobject : public PBref
{
public:
	PBobject();
	virtual ~PBobject();

protected:

	//some property
};

POLAR_BEAR_END

#endif