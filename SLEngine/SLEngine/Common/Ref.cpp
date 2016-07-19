
#include "stdafx.h"
#include "Ref.h"

NS_SL_BEGIN

Ref::Ref()
:m_nRefCount(0)
{
}

Ref::~Ref()
{
}

void Ref::retain()
{
	m_nRefCount++;
}

void Ref::release()
{
	m_nRefCount--;

	if (m_nRefCount == 0)
	{
		delete this;
	}
}

void Ref::autorelease()
{
}

unsigned int Ref::getRefCount()
{
	return m_nRefCount;
}

NS_SL_END

