// Copyright (C) 2016 Jérôme Leclercq
// This file is part of the "Nazara Engine - Vulkan"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Vulkan/VkImage.hpp>
#include <Nazara/Vulkan/Debug.hpp>

namespace Nz
{
	namespace Vk
	{
		inline bool Image::BindImageMemory(VkDeviceMemory memory, VkDeviceSize offset)
		{
			m_lastErrorCode = m_device->vkBindImageMemory(*m_device, m_handle, memory, offset);
			if (m_lastErrorCode != VK_SUCCESS)
			{
				NazaraError("Failed to bind buffer memory");
				return false;
			}

			return true;
		}

		inline VkMemoryRequirements Image::GetMemoryRequirements() const
		{
			NazaraAssert(IsValid(), "Invalid image");

			VkMemoryRequirements memoryRequirements;
			m_device->vkGetImageMemoryRequirements(*m_device, m_handle, &memoryRequirements);

			return memoryRequirements;
		}

		inline VkResult Image::CreateHelper(const DeviceHandle& device, const VkImageCreateInfo* createInfo, const VkAllocationCallbacks* allocator, VkImage* handle)
		{
			return device->vkCreateImage(*device, createInfo, allocator, handle);
		}

		inline void Image::DestroyHelper(const DeviceHandle& device, VkImage handle, const VkAllocationCallbacks* allocator)
		{
			return device->vkDestroyImage(*device, handle, allocator);
		}
	}
}

#include <Nazara/Vulkan/DebugOff.hpp>