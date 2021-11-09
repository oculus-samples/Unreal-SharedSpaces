/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Thread.h"
#ifdef EG_PLATFORM_SUPPORTS_ATOMICS
#	include <atomic>
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class Spinlock
			{
			public:
				Spinlock(void);
				void lock(void);
				void unlock(void);
#ifdef EG_PLATFORM_SUPPORTS_ATOMICS
			private:
				Spinlock(const Spinlock& notCopyable);
				Spinlock& operator=(const Spinlock& notCopyable);

				std::atomic<Thread::ID> mLockOwner;
				nByte mLockCount;
#endif
			};
		}
	}
}