
#include "stdafx.h"
#include "WorldManager.h"
#include "World.h"

NS_SL_BEGIN

WorldManager* WorldManager::GetInstance()
{
	static WorldManager s_cWorldManager;
	return &s_cWorldManager;
}

WorldManager::WorldManager()
:m_pWorldCur(nullptr)
{
}

WorldManager::~WorldManager()
{
}

void WorldManager::replaceWorld(World* pWorldNew)
{
	if (pWorldNew == nullptr || pWorldNew == m_pWorldCur)
	{
		return;
	}

	if (m_pWorldCur != nullptr)
	{
		m_pWorldCur->onExit();
		CC_SAFE_RELEASE(m_pWorldCur);
	}

	m_pWorldCur = pWorldNew;
	m_pWorldCur->onEnter();
	CC_SAFE_RETAIN(m_pWorldCur);
}

World* WorldManager::getWorldCur()
{
	return m_pWorldCur;
}

NS_SL_END
