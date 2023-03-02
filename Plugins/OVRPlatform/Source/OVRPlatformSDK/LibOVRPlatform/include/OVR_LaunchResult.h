// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCH_RESULT_H
#define OVR_LAUNCH_RESULT_H

#include "OVR_Platform_Defs.h"

typedef enum ovrLaunchResult_ {
  ovrLaunchResult_Unknown,
  ovrLaunchResult_Success,
  ovrLaunchResult_FailedRoomFull,
  ovrLaunchResult_FailedGameAlreadyStarted,
  ovrLaunchResult_FailedRoomNotFound,
  ovrLaunchResult_FailedUserDeclined,
  ovrLaunchResult_FailedOtherReason,
} ovrLaunchResult;

/// Converts an ovrLaunchResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLaunchResult_ToString(ovrLaunchResult value);

/// Converts a string representing an ovrLaunchResult enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLaunchResult) ovrLaunchResult_FromString(const char* str);

#endif
