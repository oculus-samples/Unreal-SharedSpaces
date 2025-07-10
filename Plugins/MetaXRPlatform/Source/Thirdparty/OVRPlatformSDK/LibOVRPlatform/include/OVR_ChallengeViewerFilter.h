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

#ifndef OVR_CHALLENGE_VIEWER_FILTER_H
#define OVR_CHALLENGE_VIEWER_FILTER_H

#include "OVR_Platform_Defs.h"

/// \file
/// The available filtering options on the ::ovrChallengeHandle returned by
/// ovr_Challenges_GetList(). These filters allow users to customize their
/// search results and retrieve only the challenges that meet specific
/// criteria. See more details of Challenges in
/// [here](https://developer.oculus.com/documentation/native/ps-challenges/).

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrChallengeViewerFilter_ {
  ovrChallengeViewerFilter_Unknown,
  /// Returns all public ((ovrChallengeVisibility_Public())) and invite-only
  /// (ovrChallengeVisibility_InviteOnly()) ::ovrChallengeHandles in which the
  /// user is a participant or invitee. Excludes private
  /// (ovrChallengeVisibility_Private()) challenges. This filter is useful for
  /// users who want to see all challenges they are involved in, regardless of
  /// their visibility settings.
  ovrChallengeViewerFilter_AllVisible,
  /// Returns challenges in which the user is a participant. This filter is
  /// useful for users who want to see only the challenges they are actively
  /// participating in.
  ovrChallengeViewerFilter_Participating,
  /// Returns challenges that the user has been invited to. This filter is useful
  /// for users who want to see only the challenges they have been explicitly
  /// invited to.
  ovrChallengeViewerFilter_Invited,
  /// Returns challenges the user is either participating in or invited to. This
  /// filter is useful for users who want to see all challenges they are involved
  /// in, whether as a participant or an invitee.
  ovrChallengeViewerFilter_ParticipatingOrInvited,
} ovrChallengeViewerFilter;

/// Converts an ::ovrChallengeViewerFilter enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeViewerFilter_ToString(ovrChallengeViewerFilter value);

/// Converts a string representing an ::ovrChallengeViewerFilter to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrChallengeViewerFilter) ovrChallengeViewerFilter_FromString(const char* str);

#endif
