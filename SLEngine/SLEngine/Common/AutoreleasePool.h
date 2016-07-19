#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class Ref;

class AutoreleasePool
{
public:
	static AutoreleasePool* GetInstance();

	AutoreleasePool();
	~AutoreleasePool();

	void add(Ref* pRef);
	void clear();

private:
	std::vector<Ref*> m_cRefVector;
};

NS_SL_END
