#pragma once

#include "stdafx.h"
#include "Render/Vulkan/vulkan.h"

NS_SL_BEGIN

struct VulkanTutorial01Parameters
{
	VkInstance  Instance;
	VkDevice    Device;
	uint32_t    QueueFamilyIndex;
	VkQueue     Queue;

	VulkanTutorial01Parameters() :
		Instance(VK_NULL_HANDLE),
		Device(VK_NULL_HANDLE),
		QueueFamilyIndex(0),
		Queue(VK_NULL_HANDLE) {
	}
};

class VulkanManager
{
public:
	static VulkanManager* GetInstance();

	VulkanManager();
	~VulkanManager();

	bool init();

	HINSTANCE		            VulkanLibrary;
	VulkanTutorial01Parameters  Vulkan;

private:
	bool LoadVulkanLibrary();
	bool LoadExportedEntryPoints();
	bool LoadGlobalLevelEntryPoints();
	bool CreateInstance();
	bool LoadInstanceLevelEntryPoints();
	bool CreateDevice();
	bool CheckPhysicalDeviceProperties(VkPhysicalDevice physical_device, uint32_t &queue_family_index);
	bool LoadDeviceLevelEntryPoints();
	bool GetDeviceQueue();
};

NS_SL_END
