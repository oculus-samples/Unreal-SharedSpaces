// Copyright (c) Facebook, Inc. and its affiliates.

#include "OVRPlatformSDK.h"

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/OVR_PlatformLoader.cpp"
#include "Windows/HideWindowsPlatformTypes.h"
#endif