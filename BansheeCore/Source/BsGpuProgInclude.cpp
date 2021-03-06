//__________________________ Banshee Project - A modern game development toolkit _________________________________//
//_____________________________________ www.banshee-project.com __________________________________________________//
//________________________ Copyright (c) 2014 Marko Pintera. All rights reserved. ________________________________//
#include "BsGpuProgInclude.h"
#include "BsResources.h"

namespace BansheeEngine
{
	GpuProgInclude::GpuProgInclude(const String& includeString)
		:Resource(false), mString(includeString)
	{

	}

	HGpuProgInclude GpuProgInclude::create(const String& includeString)
	{
		return static_resource_cast<GpuProgInclude>(gResources()._createResourceHandle(_createPtr(includeString)));
	}

	GpuProgIncludePtr GpuProgInclude::_createPtr(const String& includeString)
	{
		GpuProgIncludePtr gpuProgIncludePtr = bs_core_ptr<GpuProgInclude, PoolAlloc>(
			new (bs_alloc<GpuProgInclude, PoolAlloc>()) GpuProgInclude(includeString));
		gpuProgIncludePtr->_setThisPtr(gpuProgIncludePtr);
		gpuProgIncludePtr->initialize();

		return gpuProgIncludePtr;
	}
}