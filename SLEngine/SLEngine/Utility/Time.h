#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class Time
{
public:
	static Time* GetInstance();

	Time();
	~Time();

	void setDelta(float fDelta);
	float getDelta();

private:
	float m_fDelta;
};

NS_SL_END
