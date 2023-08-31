// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_VISIBILITY_H
#define OVR_CHALLENGE_VISIBILITY_H

#include "OVR_Platform_Defs.h"

typedef enum ovrChallengeVisibility_ {
  ovrChallengeVisibility_Unknown,
  /// Only those invited can participate in it. Everyone can see it
  ovrChallengeVisibility_InviteOnly,
  /// Everyone can participate and see this challenge
  ovrChallengeVisibility_Public,
  /// Only those invited can participate and see this challenge
  ovrChallengeVisibility_Private,
} ovrChallengeVisibility;

/// Converts an ovrChallengeVisibility enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeVisibility_ToString(ovrChallengeVisibility value);

/// Converts a string representing an ovrChallengeVisibility enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrChallengeVisibility) ovrChallengeVisibility_FromString(const char* str);

#endif
