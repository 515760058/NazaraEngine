// Copyright (C) 2017 Jérôme Leclercq
// This file is part of the "Nazara Engine - Graphics module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Graphics/SkeletalModel.hpp>
#include <memory>
#include <Nazara/Graphics/Debug.hpp>

namespace Nz
{
	/*!
	* \brief Creates a new SkeletalModel from the arguments
	* \return A reference to the newly created SkeletalModel
	*
	* \param args Arguments for the skeletal model
	*/
	template<typename... Args>
	SkeletalModelRef SkeletalModel::New(Args&&... args)
	{
		return std::make_shared<SkeletalModel>(std::forward<Args>(args)...);
	}
}

#include <Nazara/Graphics/DebugOff.hpp>
