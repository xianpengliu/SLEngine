// SLEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"
#include "Window.h"
#include "VulkanManager.h"

using namespace SL;

int _tmain(int argc, _TCHAR* argv[])
{
	Application cApp;
	if (cApp.init())
	{
		cApp.run();

		return 0;
	}
	else
	{
		return -1;
	}
}
