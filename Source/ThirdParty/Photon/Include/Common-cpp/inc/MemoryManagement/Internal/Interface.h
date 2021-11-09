/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/MemoryManagement/AllocatorInterface.h"

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			namespace Internal
			{
				class Interface
				{
				public:
					static void setMaxAllocSize(size_t maxAllocSize);
					static void setMaxSizeForAllocatorUsage(size_t maxSizeForAllocatorUsage);
					static void setAllocator(AllocatorInterface& allocator);
					static void setAllocatorToDefault(void);
					static void* malloc(size_t size);
					static void free(void* p);
					static void* realloc(void* p, size_t size);
					static void* calloc(size_t num, size_t size);
					static AllocatorInterface* getAllocator(size_t size);
				private:
					static size_t mMaxSizeForAllocatorUsage;
					static AllocatorInterface* mpAllocator;
				};
			}
		}
	}
}