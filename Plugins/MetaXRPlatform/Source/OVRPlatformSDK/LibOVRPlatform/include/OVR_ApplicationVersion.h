// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONVERSION_H
#define OVR_APPLICATIONVERSION_H

#include "OVR_Platform_Defs.h"

typedef struct ovrApplicationVersion *ovrApplicationVersionHandle;

/// Seconds since epoch when the latest app update was released
OVRP_PUBLIC_FUNCTION(long long) ovr_ApplicationVersion_GetReleaseDate(const ovrApplicationVersionHandle obj);

/// Size of the app update in bytes
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetSize(const ovrApplicationVersionHandle obj);

OVRP_PUBLIC_FUNCTION(int)          ovr_ApplicationVersion_GetCurrentCode(const ovrApplicationVersionHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetCurrentName(const ovrApplicationVersionHandle obj);
OVRP_PUBLIC_FUNCTION(int)          ovr_ApplicationVersion_GetLatestCode(const ovrApplicationVersionHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetLatestName(const ovrApplicationVersionHandle obj);

#endif
