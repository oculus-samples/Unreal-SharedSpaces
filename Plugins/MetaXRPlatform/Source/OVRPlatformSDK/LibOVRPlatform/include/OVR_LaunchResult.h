// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCH_RESULT_H
#define OVR_LAUNCH_RESULT_H

#include "OVR_Platform_Defs.h"

/// An enum that specifies the whether the attempt to launch this application
/// via a deeplink was successful. The value is meant to be reported after a
/// deeplink by calling ovr_ApplicationLifecycle_LogDeeplinkResult()
typedef enum ovrLaunchResult_ {
  ovrLaunchResult_Unknown,
  /// The application launched successfully.
  ovrLaunchResult_Success,
  /// The application launch failed because the room was full.
  ovrLaunchResult_FailedRoomFull,
  /// The application launch failed because the game has already started.
  ovrLaunchResult_FailedGameAlreadyStarted,
  /// The appplicatin launch failed because the room couldn't be found.
  ovrLaunchResult_FailedRoomNotFound,
  /// The application launch failed because the user declined the invitation.
  ovrLaunchResult_FailedUserDeclined,
  /// The application launch failed due to some other reason.
  ovrLaunchResult_FailedOtherReason,
} ovrLaunchResult;

/// Converts an ovrLaunchResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLaunchResult_ToString(ovrLaunchResult value);

/// Converts a string representing an ovrLaunchResult enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLaunchResult) ovrLaunchResult_FromString(const char* str);

#endif
