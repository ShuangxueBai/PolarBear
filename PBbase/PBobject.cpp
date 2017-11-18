#include "base/PBobject.h"
#include "base/PBerrorCode.h"
#include <assert.h>

POLAR_BEAR_BEGIN

//////////////////////////////////////////////////////////////////////////
PBobject::PBobject()
	: m_ref(1)
{

}

PBobject::~PBobject()
{

}

pbresult PBobject::queryInterface(pbIID iid, void** iObject)
{
	if (iid == PB_IID_OBJECT)
	{
		*iObject = reinterpret_cast<void*>(this);
		retain();
	}
	return PB_ErrorCode::OK;
}

pbulong PBobject::retain()
{
	assert(m_ref > 0);
	++m_ref;
	return m_ref;
}

pbulong PBobject::release()
{
	assert(m_ref > 0);
	--m_ref;
	if (0 == m_ref)
	{
		delete this;
	}
	return m_ref;
}

POLAR_BEAR_END
