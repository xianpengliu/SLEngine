// SLEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"
#include "WorldManager.h"
#include "World.h"
#include "Time.h"
#include "Window.h"
#include "VulkanManager.h"
#include "VulkanAgent.h"

NS_SL_BEGIN

Application::Application()
{
	QueryPerformanceFrequency(&m_sFreq);
	m_sInterval.QuadPart = 0;
}

Application::~Application()
{
}

bool Application::init()
{
	// Create window
	if (!m_cWindow.Create(_T("SLEngine")))
	{
		return false;
	}

	// Init vulkan
	if (VulkanManager::GetInstance()->init(m_cWindow.GetParameters()))
	{
		Log::log("vulkan init successfully...");
	}
	else
	{
		return false;
	}

	setAnimationInterval(1.0f / 60.0f);

	World* pWorld = World::Create();
	WorldManager::GetInstance()->replaceWorld(pWorld);

	return true;
}

bool Application::run()
{
	// Rendering loop
	if (!m_cWindow.RenderingLoop(this))
	{
		return false;
	}

	return true;
}

bool Application::OnWindowSizeChanged()
{
	return VulkanManager::GetInstance()->getVulkanAgent()->OnWindowSizeChanged();
}

bool Application::ReadyToDraw()
{
	return VulkanManager::GetInstance()->getVulkanAgent()->IsReadyToRender();
}

bool Application::Draw()
{
	LARGE_INTEGER nLast;
	QueryPerformanceCounter(&nLast);

	LARGE_INTEGER nNow;

	while (true)
	{
		QueryPerformanceCounter(&nNow);

		LONGLONG sInterval = nNow.QuadPart - nLast.QuadPart;
		if (sInterval > m_sInterval.QuadPart)
		{
			nLast.QuadPart = nNow.QuadPart - (nNow.QuadPart % m_sInterval.QuadPart);

			Time::GetInstance()->setDelta((float)sInterval / (float)m_sFreq.QuadPart);

			// Update world
			WorldManager::GetInstance()->getWorldCur()->onUpdate();

			// Draw world
			VulkanManager::GetInstance()->getVulkanAgent()->Draw();
		}
		else
		{
			Sleep(1);
		}
	}

	return true;
}

void Application::setAnimationInterval(float interval)
{
	m_sInterval.QuadPart = (LONGLONG)(interval * m_sFreq.QuadPart);
}

NS_SL_END
