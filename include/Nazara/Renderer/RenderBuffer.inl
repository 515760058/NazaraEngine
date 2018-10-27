// Copyright (C) 2017 Jérôme Leclercq
// This file is part of the "Nazara Engine - Renderer module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <memory>
#include <Nazara/Renderer/Debug.hpp>

namespace Nz
{
	template<typename... Args>
	RenderBufferRef RenderBuffer::New(Args&&... args)
	{
		return std::make_shared<RenderBuffer>(std::forward<Args>(args)...);
	}
}

#include <Nazara/Renderer/DebugOff.hpp>
