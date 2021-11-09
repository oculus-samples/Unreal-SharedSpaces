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
				class DirectAllocator : public AllocatorInterface
				{
				public:
					virtual ~DirectAllocator(void);

					virtual void setMaxAllocSize(size_t maxAllocSize);
					virtual void* alloc(size_t size);
					virtual void dealloc(void* p);
					virtual void* resize(void* p, size_t size);
				};
			}
		}
	}
}