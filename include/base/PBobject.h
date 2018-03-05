#ifndef POLAR_BEAR_OBJECT_H
#define POLAR_BEAR_OBJECT_H
#include "base/PBunknown.h"

POLAR_BEAR_BEGIN

#define PB_IID_OBJECT 0x00000001

class BASE_EXT PBobject : public IPBunknown
{
public:
	virtual pbresult queryInterface(pbIID iid, void** iObject) override;
	virtual pbulong retain() override;
	virtual pbulong release() override;

public:
	PBobject();
	~PBobject();

private:
	pbulong m_ref;
};

POLAR_BEAR_END

#endif