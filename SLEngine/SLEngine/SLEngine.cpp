// SLEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application/Application.h"
#include "Platform/Window.h"
#include "Render/VulkanManager.h"

using namespace SL;

int _tmain(int argc, _TCHAR* argv[])
{
	LOG("Hello SLEngine");

	//Application cApp;
	//cApp.run();

	// Create window
	Window window;
	if (!window.Create(_T("SLEngine")))
	{
		return -1;
	}

	// Init vulkan
	if (VulkanManager::GetInstance()->init(window.GetParameters()))
	{
		Log::log("vulkan init successfully...");
	}
	else
	{
		return -1;
	}

	// Rendering loop
	if (!window.RenderingLoop(VulkanManager::GetInstance()->getVulkanAgent()))
	{
		return -1;
	}

	return 0;
}
