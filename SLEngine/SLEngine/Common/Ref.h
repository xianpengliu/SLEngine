#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class Ref
{
public:
	Ref();
	virtual ~Ref();

	void retain();
	void release();
	void autorelease();

	unsigned int getRefCount();

private:
	unsigned int m_nRefCount;
};

NS_SL_END
