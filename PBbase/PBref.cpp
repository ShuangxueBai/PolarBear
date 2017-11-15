#include <assert.h>
#include <iostream>
#include "base/PBref.h"

POLAR_BEAR_BEGIN

PBref::PBref()
	:_ref(1)
{

}

PBref::~PBref()
{

}

void PBref::retain()
{
	assert(_ref > 0);
	++_ref;
}

void PBref::release()
{
	assert(_ref > 0);
	--_ref;
	if (0 == _ref)
	{
		delete this;
		std::cout << "this is release !" << std::endl;
	}
}

pbuint PBref::getReferenceCount() const
{
	return _ref;
}

POLAR_BEAR_END
