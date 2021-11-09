/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			namespace Internal
			{
				struct RawStorage
				{
					RawStorage* mpNext;
#if defined _EG_EMSCRIPTEN_PLATFORM || defined __arm___ || defined _M_ARM
					// Emscripten requires arrays of objects that have member variables of type double to be 8 byte aligned
					// 32bit ARM architectures require 64bit std::atomic types to be 8 byte aligned for access to them to actually be atomic
					// both is only the case for data that is stored in memory that was allocated by MemoryPool, when we add padding bytes to RawStorage
					nByte mPadding[4];
#endif
				};
			}
		}
	}
}