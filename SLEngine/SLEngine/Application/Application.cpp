// SLEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"
#include "Common/Macros.h"
#include "World/WorldManager.h"
#include "World/World.h"
#include "Utility/Time.h"

NS_SL_BEGIN

Application::Application()
{
	QueryPerformanceFrequency(&m_sFreq);
	m_sInterval.QuadPart = 0;
}

Application::~Application()
{
}

void Application::init()
{
	setAnimationInterval(1.0f / 60.0f);

	World* pWorld = World::Create();
	WorldManager::GetInstance()->replaceWorld(pWorld);
}

void Application::run()
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

			update();
		}
		else
		{
			Sleep(1);
		}
	}
}

void Application::update()
{
	World* pWorldCur = WorldManager::GetInstance()->getWorldCur();
	pWorldCur->onUpdate();
}

void Application::setAnimationInterval(float interval)
{
	m_sInterval.QuadPart = (LONGLONG)(interval * m_sFreq.QuadPart);
}

NS_SL_END
