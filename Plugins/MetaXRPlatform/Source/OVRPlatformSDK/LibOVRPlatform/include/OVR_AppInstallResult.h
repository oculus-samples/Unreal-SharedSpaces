// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_INSTALL_RESULT_H
#define OVR_APP_INSTALL_RESULT_H

#include "OVR_Platform_Defs.h"

/// Result of installing an app. In case of an error during install process,
/// the error message contains the string representation of this result. This
/// is returned from ovr_Application_StartAppDownload(),
/// ovr_Application_CancelAppDownload() and
/// ovr_Application_InstallAppUpdateAndRelaunch() APIs.
typedef enum ovrAppInstallResult_ {
  ovrAppInstallResult_Unknown,
  /// Install of the app failed due to low storage on the device
  ovrAppInstallResult_LowStorage,
  /// Install of the app failed due to a network error
  ovrAppInstallResult_NetworkError,
  /// Install of the app failed as another install request for this application
  /// is already being processed by the installer
  ovrAppInstallResult_DuplicateRequest,
  /// Install of the app failed due to an internal installer error
  ovrAppInstallResult_InstallerError,
  /// Install of the app failed because the user canceled the install operation
  ovrAppInstallResult_UserCancelled,
  /// Install of the app failed due to a user authorization error
  ovrAppInstallResult_AuthorizationError,
  /// Install of the app succeeded
  ovrAppInstallResult_Success,
} ovrAppInstallResult;

/// Converts an ovrAppInstallResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppInstallResult_ToString(ovrAppInstallResult value);

/// Converts a string representing an ovrAppInstallResult enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAppInstallResult) ovrAppInstallResult_FromString(const char* str);

#endif
