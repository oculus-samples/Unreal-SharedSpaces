// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCH_TYPE_H
#define OVR_LAUNCH_TYPE_H

#include "OVR_Platform_Defs.h"

typedef enum ovrLaunchType_ {
  ovrLaunchType_Unknown,
  /// Normal launch from the user's library
  ovrLaunchType_Normal,
  /// Launch from the user accepting an invite. Check
  /// ovr_LaunchDetails_GetLobbySessionID(),
  /// ovr_LaunchDetails_GetMatchSessionID(),
  /// ovr_LaunchDetails_GetDestinationApiName() and
  /// ovr_LaunchDetails_GetDeeplinkMessage().
  ovrLaunchType_Invite,
  /// DEPRECATED
  ovrLaunchType_Coordinated,
  /// Launched from ovr_Application_LaunchOtherApp(). Check
  /// ovr_LaunchDetails_GetLaunchSource() and
  /// ovr_LaunchDetails_GetDeeplinkMessage().
  ovrLaunchType_Deeplink,
} ovrLaunchType;

/// Converts an ovrLaunchType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLaunchType_ToString(ovrLaunchType value);

/// Converts a string representing an ovrLaunchType enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLaunchType) ovrLaunchType_FromString(const char* str);

#endif
