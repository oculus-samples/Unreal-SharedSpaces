/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/platformLayer.h"
#if defined _EG_WINDOWSSTORE_PLATFORM || defined _EG_XB1_PLATFORM || defined _EG_PSVITA_PLATFORM || defined _EG_SWITCH_PLATFORM || defined _EG_GAMECORE_PLATFORM
#	include <thread>
#else
#	include "Common-cpp/inc/porting.h"
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace Thread
			{
				class ID
				{
				public:
					ID(void);

					bool operator==(const ID& Rhs) const;
					bool operator!=(const ID& Rhs) const;
				private:
#			if defined _EG_UNIX_PLATFORM && !defined _EG_PSVITA_PLATFORM && !defined _EG_SWITCH_PLATFORM
					ID(pthread_t id);
					pthread_t mID;
#			elif defined _EG_WINDOWS_PLATFORM
					ID(unsigned long id);
					unsigned long mID;
#			else
					ID(std::thread::id id);
					std::thread::id mID;
#			endif

					friend ID getLocalThreadID(void);
				};

				typedef void (*callbackSignature)(void* pArg);

				void create(callbackSignature onEnterThread, void* pArg);

				ID getLocalThreadID(void);
			}
		}
	}
}