// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_VIEWER_FILTER_H
#define OVR_CHALLENGE_VIEWER_FILTER_H

#include "OVR_Platform_Defs.h"

typedef enum ovrChallengeViewerFilter_ {
  ovrChallengeViewerFilter_Unknown,
  ovrChallengeViewerFilter_AllVisible,
  ovrChallengeViewerFilter_Participating,
  ovrChallengeViewerFilter_Invited,
  ovrChallengeViewerFilter_ParticipatingOrInvited,
} ovrChallengeViewerFilter;

/// Converts an ovrChallengeViewerFilter enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeViewerFilter_ToString(ovrChallengeViewerFilter value);

/// Converts a string representing an ovrChallengeViewerFilter enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrChallengeViewerFilter) ovrChallengeViewerFilter_FromString(const char* str);

#endif
