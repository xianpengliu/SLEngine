#include "stdafx.h"
#include "Time.h"

NS_SL_BEGIN

Time* Time::GetInstance()
{
	static Time s_cTime;
	return &s_cTime;
}

Time::Time()
:m_fDelta(0.0f)
{
}

Time::~Time()
{
}

void Time::setDelta(float fDelta)
{
	m_fDelta = fDelta;
}

float Time::getDelta()
{
	return m_fDelta;
}

NS_SL_END

