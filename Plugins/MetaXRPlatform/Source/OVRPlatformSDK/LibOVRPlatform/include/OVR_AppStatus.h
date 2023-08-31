// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_STATUS_H
#define OVR_APP_STATUS_H

#include "OVR_Platform_Defs.h"

typedef enum ovrAppStatus_ {
  ovrAppStatus_Unknown,
  ovrAppStatus_Entitled,
  ovrAppStatus_DownloadQueued,
  ovrAppStatus_Downloading,
  ovrAppStatus_Installing,
  ovrAppStatus_Installed,
  ovrAppStatus_Uninstalling,
} ovrAppStatus;

/// Converts an ovrAppStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppStatus_ToString(ovrAppStatus value);

/// Converts a string representing an ovrAppStatus enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAppStatus) ovrAppStatus_FromString(const char* str);

#endif
