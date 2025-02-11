// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_CREATION_TYPE_H
#define OVR_CHALLENGE_CREATION_TYPE_H

#include "OVR_Platform_Defs.h"

/// Describes the creator of the associated challenge.
typedef enum ovrChallengeCreationType_ {
  ovrChallengeCreationType_Unknown,
  /// The challenge was created by a User.
  ovrChallengeCreationType_UserCreated,
  /// The challenge was created by the app developer.
  ovrChallengeCreationType_DeveloperCreated,
} ovrChallengeCreationType;

/// Converts an ovrChallengeCreationType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeCreationType_ToString(ovrChallengeCreationType value);

/// Converts a string representing an ovrChallengeCreationType enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrChallengeCreationType) ovrChallengeCreationType_FromString(const char* str);

#endif
