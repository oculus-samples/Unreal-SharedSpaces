/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"
#if defined _EG_APPLE_PLATFORM || defined _EG_SONY_PLATFORM
#	include <stdlib.h>
#else
#	include <malloc.h>
#endif
#include "Common-cpp/inc/MemoryManagement/Internal/Entry.h"
#include "Common-cpp/inc/MemoryManagement/Internal/RawStorage.h"

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			namespace Internal
			{
				class MemoryPool
				{
				public:
					MemoryPool(void);
					~MemoryPool(void);
					void init(size_t blockSize, size_t initialCapacity=1, size_t maxCapacityIncrement=0);
					Entry* alloc(void);
					void dealloc(void* p);
					size_t getBlockSize(void) const;
					void setMaxCapacityIncrement(size_t maxCapacityIncrement=0);
				private:
					void allocateBlocks(size_t amount);
					void increaseCapacity(void);

					Entry* mMemory;
					size_t mBlockSize;
					size_t mCapacity;
					size_t mMaxCapacityIncrement;
					RawStorage mRaw;
#ifdef EG_DEBUGGER
					void* mLastAlloc;
					void* mLastDealloc;
#endif
				};
			}
		}
	}
}