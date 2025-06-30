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

#ifndef OVR_LIVESTREAMING_AUDIENCE_H
#define OVR_LIVESTREAMING_AUDIENCE_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's a enum that represent the different types of audiences that can be
/// selected for a livestreaming. It can be used to specify the audience when a
/// live streaming starts. The livestreaming status change will be notified by
/// #ovrMessage_Notification_Livestreaming_StatusChange

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLivestreamingAudience_ {
  ovrLivestreamingAudience_Unknown,
  /// This value represents a public audience, meaning that anyone can view the
  /// livestream.
  ovrLivestreamingAudience_Public,
  /// This value represents an audience consisting of the user's friends. Only
  /// people who are friends with the user will be able to view the livestream.
  ovrLivestreamingAudience_Friends,
  /// This value represents an audience consisting only of the user themselves.
  /// Only the user who created the livestream will be able to view it.
  ovrLivestreamingAudience_OnlyMe,
} ovrLivestreamingAudience;

/// Converts an ::ovrLivestreamingAudience enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLivestreamingAudience_ToString(ovrLivestreamingAudience value);

/// Converts a string representing an ::ovrLivestreamingAudience to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLivestreamingAudience) ovrLivestreamingAudience_FromString(const char* str);

#endif
