// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPDOWNLOADPROGRESSRESULT_H
#define OVR_APPDOWNLOADPROGRESSRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_AppStatus.h"

/// Represents the result of the download of an application. You can retrieve
/// it using CheckAppDownloadProgress API
/// (ovr_Application_CheckAppDownloadProgress()). You can use this to check the
/// progress and the status of an ongoing app download operation.
typedef struct ovrAppDownloadProgressResult *ovrAppDownloadProgressResultHandle;

/// Total number of bytes that need to be downloaded
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadBytes(const ovrAppDownloadProgressResultHandle obj);

/// Number of bytes that have already been downloaded. You can use this and
/// ovr_AppDownloadProgressResult_GetDownloadBytes() to implement the progress
/// bar.
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadedBytes(const ovrAppDownloadProgressResultHandle obj);

/// Status code of the current app status. You can use it to find out whether
/// the app is being downloaded or queued for downloading
OVRP_PUBLIC_FUNCTION(ovrAppStatus) ovr_AppDownloadProgressResult_GetStatusCode(const ovrAppDownloadProgressResultHandle obj);


#endif
