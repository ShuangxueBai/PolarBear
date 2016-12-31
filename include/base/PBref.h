#ifndef POLAR_BEAR_REF_H
#define POLAR_BEAR_REF_H
#include "base/_baseExport.h"
#include "PBdefine.h"

POLAR_BEAR_BEGIN

class BASE_EXT PBref
{
public:
	PBref();
	virtual ~PBref();

	void retain();
	void release();

	unsigned int getReferenceCount() const;
private:
	int _ref;
};

POLAR_BEAR_END


#endif