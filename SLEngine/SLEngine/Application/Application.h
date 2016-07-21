#pragma once

#include "stdafx.h"
#include "Window.h"

NS_SL_BEGIN

class Application
{
public:
	Application();
	~Application();

	bool init();
	bool run();

	bool OnWindowSizeChanged();
	bool ReadyToDraw();
	bool Draw();

	void setAnimationInterval(float interval);

private:
	LARGE_INTEGER m_sFreq;
	LARGE_INTEGER m_sInterval;

	Window m_cWindow;
};

NS_SL_END
