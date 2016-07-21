#pragma once

#include "stdafx.h"
#include "vulkan.h"
#include "VulkanCommon.h"
#include "Tools.h"

NS_SL_BEGIN

class VulkanAgent;

class VulkanManager
{
public:
	static VulkanManager* GetInstance();

	VulkanManager();
	~VulkanManager();

	bool init(WindowParameters parameters);

	VulkanAgent* getVulkanAgent();

private:
	VulkanAgent* m_pVulkanAgent;
};

NS_SL_END
