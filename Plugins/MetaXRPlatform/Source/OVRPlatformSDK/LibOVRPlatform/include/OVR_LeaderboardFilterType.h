// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARD_FILTER_TYPE_H
#define OVR_LEADERBOARD_FILTER_TYPE_H

#include "OVR_Platform_Defs.h"

/// Describe the filter type that can be enabled on the leaderboard.
typedef enum ovrLeaderboardFilterType_ {
  /// No filter enabled on the leaderboard.
  ovrLeaderboard_FilterNone,
  /// Filter the leaderboard to include only friends of the current user.
  ovrLeaderboard_FilterFriends,
  ovrLeaderboard_FilterUnknown,
  /// Filter the leaderboard to include specific user IDs. Use this filter to get
  /// rankings for users that are competing against each other. You specify the
  /// leaderboard name and whether to start at the top, or for the results to
  /// center on the (client) user. Note that if you specify the results to center
  /// on the client user, their leaderboard entry will be included in the
  /// returned array, regardless of whether their ID is explicitly specified in
  /// the list of IDs.
  ovrLeaderboard_FilterUserIds,
} ovrLeaderboardFilterType;

/// Converts an ovrLeaderboardFilterType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLeaderboardFilterType_ToString(ovrLeaderboardFilterType value);

/// Converts a string representing an ovrLeaderboardFilterType enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLeaderboardFilterType) ovrLeaderboardFilterType_FromString(const char* str);

#endif
