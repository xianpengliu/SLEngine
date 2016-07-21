
#include "stdafx.h"
#include "AutoreleasePool.h"
#include "Ref.h"

NS_SL_BEGIN

AutoreleasePool* AutoreleasePool::GetInstance()
{
	static AutoreleasePool s_cAutoreleasePool;
	return &s_cAutoreleasePool;
}

AutoreleasePool::AutoreleasePool()
{
	m_cRefVector.reserve(128);
}

AutoreleasePool::~AutoreleasePool()
{
}

void AutoreleasePool::add(Ref* pRef)
{
	m_cRefVector.push_back(pRef);
}

void AutoreleasePool::clear()
{
	for (Ref* pRef : m_cRefVector)
	{
		pRef->release();
	}
}

NS_SL_END

