// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USER_PRESENCE_STATUS_H
#define OVR_USER_PRESENCE_STATUS_H

#include "OVR_Platform_Defs.h"

/// Describe the current status of the user and it can be retrieved with
/// ovr_User_GetPresenceStatus().
typedef enum ovrUserPresenceStatus_ {
  ovrUserPresenceStatus_Unknown,
  /// The user status is currently online.
  ovrUserPresenceStatus_Online,
  /// The user status is currently offline.
  ovrUserPresenceStatus_Offline,
} ovrUserPresenceStatus;

/// Converts an ovrUserPresenceStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrUserPresenceStatus_ToString(ovrUserPresenceStatus value);

/// Converts a string representing an ovrUserPresenceStatus enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrUserPresenceStatus) ovrUserPresenceStatus_FromString(const char* str);

#endif
