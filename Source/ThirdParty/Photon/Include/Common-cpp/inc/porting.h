/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"

#if defined _EG_MICROSOFT_PLATFORM
#	include <process.h>
#	include <mbstring.h>
#	include <winsock2.h>
#	include <time.h>
#	include <ws2tcpip.h>
#	if defined _EG_WINDOWS_PLATFORM || defined _EG_GAMECORE_PLATFORM
#		include <winhttp.h>
#	endif
#	include <urlmon.h>
#	include <string.h>
#elif defined _EG_SWITCH_PLATFORM
#	include <nn/time.h>
#elif defined _EG_PSVITA_PLATFORM
#	include <kernel.h>
#elif defined _EG_UNIX_PLATFORM
#	include <pthread.h>
#endif

#if defined _EG_SWITCH_PLATFORM || defined _EG_ANDROID_PLATFORM || defined _EG_LINUX_PLATFORM
#	include <math.h>
#endif

#if defined _EG_ANDROID_PLATFORM
#	include <stdlib.h>
#endif

#if defined _EG_MICROSOFT_PLATFORM
#	define SLEEP(ms) Sleep(ms)
#elif defined _EG_PSVITA_PLATFORM || defined _EG_SWITCH_PLATFORM
#	if defined __cplusplus
#		include <chrono>
#		define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#	endif
#else
#	if defined _EG_LINUX_PLATFORM || defined _EG_MARMALADE_PLATFORM || defined _EG_ANDROID_PLATFORM || defined _EG_BLACKBERRY_PLATFORM || defined _EG_SONY_PLATFORM
#		include "unistd.h"
#	endif
#	define SLEEP(ms) usleep(ms*1000)
#endif