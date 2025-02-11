// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_VIEWER_FILTER_H
#define OVR_CHALLENGE_VIEWER_FILTER_H

#include "OVR_Platform_Defs.h"

/// The available filtering options on the ovrChallengeHandle returned by
/// ovr_Challenges_GetList().
typedef enum ovrChallengeViewerFilter_ {
  ovrChallengeViewerFilter_Unknown,
  /// Returns all public ((ovrChallengeVisibility_Public)) and invite-only
  /// (ovrChallengeVisibility_InviteOnly) ovrChallengeHandles in which the user
  /// is a participant or invitee. Excludes private
  /// (ovrChallengeVisibility_Private) challenges.
  ovrChallengeViewerFilter_AllVisible,
  /// Returns challenges in which the user is a participant.
  ovrChallengeViewerFilter_Participating,
  /// Returns challenges that the user has been invited to.
  ovrChallengeViewerFilter_Invited,
  /// Returns challenges the user is either participating in or invited to.
  ovrChallengeViewerFilter_ParticipatingOrInvited,
} ovrChallengeViewerFilter;

/// Converts an ovrChallengeViewerFilter enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeViewerFilter_ToString(ovrChallengeViewerFilter value);

/// Converts a string representing an ovrChallengeViewerFilter enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrChallengeViewerFilter) ovrChallengeViewerFilter_FromString(const char* str);

#endif
