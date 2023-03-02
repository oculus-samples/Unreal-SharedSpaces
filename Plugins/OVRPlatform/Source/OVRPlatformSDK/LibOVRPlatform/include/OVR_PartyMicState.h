// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTY_MIC_STATE_H
#define OVR_PARTY_MIC_STATE_H

#include "OVR_Platform_Defs.h"

typedef enum ovrPartyMicState_ {
  ovrPartyMicState_Unknown,
  ovrPartyMicState_Party,
  ovrPartyMicState_App,
  ovrPartyMicState_Mute,
  ovrPartyMicState_Inactive,
  ovrPartyMicState_InputShared,
} ovrPartyMicState;

/// Converts an ovrPartyMicState enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrPartyMicState_ToString(ovrPartyMicState value);

/// Converts a string representing an ovrPartyMicState enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrPartyMicState) ovrPartyMicState_FromString(const char* str);

#endif
