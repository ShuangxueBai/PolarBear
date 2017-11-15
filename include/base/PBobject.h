#ifndef POLAR_BEAR_OBJECT_H
#define POLAR_BEAR_OBJECT_H
#include "base/PBrefptr.h"
#include "base/PBtypes.h"
POLAR_BEAR_BEGIN

class BASE_EXT PBobject : public PBref
{
public:
	virtual void QueryInterface(int id, void** pInterface) = 0;
};

POLAR_BEAR_END

#endif