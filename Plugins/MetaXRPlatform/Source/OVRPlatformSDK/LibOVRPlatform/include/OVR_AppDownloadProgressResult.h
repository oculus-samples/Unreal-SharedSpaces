// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPDOWNLOADPROGRESSRESULT_H
#define OVR_APPDOWNLOADPROGRESSRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_AppStatus.h"

typedef struct ovrAppDownloadProgressResult *ovrAppDownloadProgressResultHandle;

/// Total number of bytes that need to be downloaded
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadBytes(const ovrAppDownloadProgressResultHandle obj);

/// Number of bytes that have already been downloaded
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadedBytes(const ovrAppDownloadProgressResultHandle obj);

/// Status code of the current app status. Can be used to find if app is
/// downloading etc.
OVRP_PUBLIC_FUNCTION(ovrAppStatus) ovr_AppDownloadProgressResult_GetStatusCode(const ovrAppDownloadProgressResultHandle obj);


#endif
