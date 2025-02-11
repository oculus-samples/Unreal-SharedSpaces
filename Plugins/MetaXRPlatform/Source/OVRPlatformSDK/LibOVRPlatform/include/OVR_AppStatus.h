// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_STATUS_H
#define OVR_APP_STATUS_H

#include "OVR_Platform_Defs.h"

/// Current status of the app on the device. An app can only check its own
/// status.
typedef enum ovrAppStatus_ {
  ovrAppStatus_Unknown,
  /// User has valid entitlement to the app but it is not currently installed on
  /// the device.
  ovrAppStatus_Entitled,
  /// Download of the app is currently queued.
  ovrAppStatus_DownloadQueued,
  /// Download of the app is currently in progress.
  ovrAppStatus_Downloading,
  /// Install of the app is currently in progress.
  ovrAppStatus_Installing,
  /// App is installed on the device.
  ovrAppStatus_Installed,
  /// App is being uninstalled from the device.
  ovrAppStatus_Uninstalling,
  /// Install of the app is currently queued.
  ovrAppStatus_InstallQueued,
} ovrAppStatus;

/// Converts an ovrAppStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppStatus_ToString(ovrAppStatus value);

/// Converts a string representing an ovrAppStatus enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAppStatus) ovrAppStatus_FromString(const char* str);

#endif
