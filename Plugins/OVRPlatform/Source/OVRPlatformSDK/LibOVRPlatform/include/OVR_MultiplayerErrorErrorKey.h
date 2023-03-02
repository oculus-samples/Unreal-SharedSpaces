// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MULTIPLAYER_ERROR_ERROR_KEY_H
#define OVR_MULTIPLAYER_ERROR_ERROR_KEY_H

#include "OVR_Platform_Defs.h"

typedef enum ovrMultiplayerErrorErrorKey_ {
  ovrMultiplayerErrorErrorKey_Unknown,
  ovrMultiplayerErrorErrorKey_DestinationUnavailable,
  ovrMultiplayerErrorErrorKey_DlcRequired,
  ovrMultiplayerErrorErrorKey_General,
  ovrMultiplayerErrorErrorKey_GroupFull,
  ovrMultiplayerErrorErrorKey_InviterNotJoinable,
  ovrMultiplayerErrorErrorKey_LevelNotHighEnough,
  ovrMultiplayerErrorErrorKey_LevelNotUnlocked,
  ovrMultiplayerErrorErrorKey_NetworkTimeout,
  ovrMultiplayerErrorErrorKey_NoLongerAvailable,
  ovrMultiplayerErrorErrorKey_UpdateRequired,
  ovrMultiplayerErrorErrorKey_TutorialRequired,
} ovrMultiplayerErrorErrorKey;

/// Converts an ovrMultiplayerErrorErrorKey enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrMultiplayerErrorErrorKey_ToString(ovrMultiplayerErrorErrorKey value);

/// Converts a string representing an ovrMultiplayerErrorErrorKey enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrMultiplayerErrorErrorKey) ovrMultiplayerErrorErrorKey_FromString(const char* str);

#endif
