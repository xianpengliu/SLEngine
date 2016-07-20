#pragma once

#include "stdafx.h"
#include "Render/Vulkan/vulkan.h"
#include "Render/VulkanCommon.h"
#include "Render/Tools.h"

NS_SL_BEGIN

class VulkanAgent;

class VulkanManager
{
public:
	static VulkanManager* GetInstance();

	VulkanManager();
	~VulkanManager();

	bool init(WindowParameters parameters);

	TutorialBase* getVulkanAgent();

private:
	VulkanAgent* m_pVulkanAgent;
};

NS_SL_END
