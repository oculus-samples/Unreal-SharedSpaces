/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/ToString.h"
//#error TODO: add CPP03 implementations for Windows/Unix via WinAPI Event objects / POSIX mutexes and condition variables
#ifdef EG_PLATFORM_SUPPORTS_CPP11
#	include <condition_variable>

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class AutoResetEvent : public ToString
			{
			public:
				using ToString::toString;

				AutoResetEvent(bool signaled=false);

				void set(void);
				void reset(void);
				bool waitOne(int maxWaitTime=-1);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			private:
				AutoResetEvent(const AutoResetEvent& toCopy);
				AutoResetEvent& operator=(const AutoResetEvent& toCopy);

				bool mSignaled;
				std::mutex mMutex;
				std::condition_variable mSignal;
			};
		}
	}
}
#endif