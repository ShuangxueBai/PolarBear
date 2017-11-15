#ifndef POLAR_BEAR_REF_H
#define POLAR_BEAR_REF_H
#include "PBdefine.h"
#include "base/_baseExport.h"
#include "base/PBtypes.h"

POLAR_BEAR_BEGIN

class BASE_EXT PBref
{
public:
	PBref();
	virtual ~PBref();

	void retain();
	void release();

	pbuint getReferenceCount() const;
private:
	pbuint _ref;
};

POLAR_BEAR_END


#endif