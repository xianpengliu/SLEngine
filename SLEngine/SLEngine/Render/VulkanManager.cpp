#include "stdafx.h"
#include "VulkanManager.h"
#include "Render/VulkanAgent.h"

NS_SL_BEGIN

VulkanManager* VulkanManager::GetInstance()
{
	static VulkanManager s_cVulkanManager;
	return &s_cVulkanManager;
}

VulkanManager::VulkanManager()
{
}

VulkanManager::~VulkanManager()
{	
}

bool VulkanManager::init(WindowParameters parameters)
{
	m_pVulkanAgent = new VulkanAgent();

	return m_pVulkanAgent->init(parameters);
}

TutorialBase* VulkanManager::getVulkanAgent()
{
	return m_pVulkanAgent;
}

NS_SL_END
