// Copyright (C) 2016 Jérôme Leclercq
// This file is part of the "Nazara Engine - Vulkan Renderer"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/VulkanRenderer/VulkanShaderStage.hpp>
#include <Nazara/VulkanRenderer/Debug.hpp>

namespace Nz
{
	inline const Vk::ShaderModule& VulkanShaderStage::GetHandle() const
	{
		return m_shaderModule;
	}
}

#include <Nazara/VulkanRenderer/DebugOff.hpp>