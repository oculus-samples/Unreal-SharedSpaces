/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include <limits.h>
#include "Common-cpp/inc/Helpers/Spinlock.h"
#include "Common-cpp/inc/MemoryManagement/AllocatorInterface.h"
#include "Common-cpp/inc/MemoryManagement/Internal/MemoryPool.h"

#if defined _EG_MARMALADE_PLATFORM && (defined EG_DEBUGGER || !defined _EG_MS_COMPILER) && defined I3D_ARCH_X86
#	define EG_DEACTIVATE_MEMORY_MANAGER
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			namespace Internal
			{
				class MemoryPoolManager : public AllocatorInterface
				{
				public:
					MemoryPoolManager(void);
					void setMaxAllocSize(size_t maxAllocSize);
					void setCapacityIncrements(unsigned char count, size_t* capacityIncrements);
					void* alloc(size_t s);
					void dealloc(void* p);
					void* resize(void* p, size_t size);

					static MemoryPoolManager& get(void);

#ifdef EG_DEBUGGER
					long long mCtrAllocs;
					long long mCtrDeallocs;
					long long mCtrBytes;
#endif
				private:
#ifndef EG_DEACTIVATE_MEMORY_MANAGER
					static const unsigned char M_POOL_COUNT = sizeof(size_t)*CHAR_BIT;
					MemoryPool mpPool[M_POOL_COUNT];
#endif
					Helpers::Spinlock mLock;
				};
			}
		}
	}
}