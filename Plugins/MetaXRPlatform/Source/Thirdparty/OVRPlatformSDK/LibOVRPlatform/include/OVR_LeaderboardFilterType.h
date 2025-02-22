/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARD_FILTER_TYPE_H
#define OVR_LEADERBOARD_FILTER_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enum that defines the different types of filters that can be applied to
/// a leaderboard. It can be used in ovr_Leaderboard_GetEntries() to filter the
/// leaderboard entries, such as only friends or specific user IDs.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLeaderboardFilterType_ {
  /// No filter enabled on the leaderboard.
  ovrLeaderboard_FilterNone,
  /// This value indicates that the leaderboard should be filtered to include
  /// only friends (bidirectional followers) of the current user.
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

/// Converts an ::ovrLeaderboardFilterType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLeaderboardFilterType_ToString(ovrLeaderboardFilterType value);

/// Converts a string representing an ::ovrLeaderboardFilterType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLeaderboardFilterType) ovrLeaderboardFilterType_FromString(const char* str);

#endif
