#pragma once

#ifdef __clang__
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#endif

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#pragma warning (disable: 4263)
#pragma warning (disable: 4264)

#include "LoadBalancing-cpp/inc/Client.h"

#if PLATFORM_WINDOWS
#pragma warning (default: 4263)
#pragma warning (default: 4264)
#include "Windows/HideWindowsPlatformTypes.h"
#endif