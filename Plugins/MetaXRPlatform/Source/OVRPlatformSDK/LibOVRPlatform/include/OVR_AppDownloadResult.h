// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPDOWNLOADRESULT_H
#define OVR_APPDOWNLOADRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_AppInstallResult.h"

/// Represents the result of an app download. You will use it when you start an
/// app download, cancel an app download or install an app update which was
/// previous downloaded. In those scenarios, the app download result will be
/// the payload of ovr_Application_StartAppDownload(),
/// ovr_Application_CancelAppDownload() or
/// ovr_Application_InstallAppUpdateAndRelaunch() API calls.
typedef struct ovrAppDownloadResult *ovrAppDownloadResultHandle;

/// Result of the install operation returned by the installer. You can find
/// more information about possible members from
/// ovrAppInstallResult_AppInstallResult. In case of an error during install
/// process, the error message contains the string representation of this
/// result.
OVRP_PUBLIC_FUNCTION(ovrAppInstallResult) ovr_AppDownloadResult_GetAppInstallResult(const ovrAppDownloadResultHandle obj);

/// Timestamp in milliseconds when the operation finished.
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadResult_GetTimestamp(const ovrAppDownloadResultHandle obj);


#endif
