#ifndef POLAR_BEAR_UNKOWN_H
#define POLAR_BEAR_UNKOWN_H
#include "PBdefine.h"
#include "base/_baseExport.h"
#include "base/PBtypes.h"

POLAR_BEAR_BEGIN

PB_INTERFACE IPBunknown
{
	virtual pbresult queryInterface(pbIID iid, void** iObject) = 0;
	virtual pbulong retain() = 0;
	virtual pbulong release() = 0;
};

POLAR_BEAR_END


#endif