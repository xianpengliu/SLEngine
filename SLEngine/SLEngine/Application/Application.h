#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class Application
{
public:
	Application();
	~Application();

	void init();

	void run();

	void update();

	void setAnimationInterval(float interval);

private:
	LARGE_INTEGER m_sFreq;
	LARGE_INTEGER m_sInterval;
};

NS_SL_END
