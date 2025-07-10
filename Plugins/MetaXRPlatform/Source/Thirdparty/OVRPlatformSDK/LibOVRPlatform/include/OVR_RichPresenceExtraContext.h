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

#ifndef OVR_RICH_PRESENCE_EXTRA_CONTEXT_H
#define OVR_RICH_PRESENCE_EXTRA_CONTEXT_H

#include "OVR_Platform_Defs.h"

/// \file
/// Display extra information about the user's presence

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrRichPresenceExtraContext_ {
  ovrRichPresenceExtraContext_Unknown,
  /// Display nothing
  ovrRichPresenceExtraContext_None,
  /// Display the current amount with the user over the max
  ovrRichPresenceExtraContext_CurrentCapacity,
  /// Display how long ago the match/game/race/etc started
  ovrRichPresenceExtraContext_StartedAgo,
  /// Display how soon the match/game/race/etc will end
  ovrRichPresenceExtraContext_EndingIn,
  /// Display that this user is looking for a match
  ovrRichPresenceExtraContext_LookingForAMatch,
} ovrRichPresenceExtraContext;

/// Converts an ::ovrRichPresenceExtraContext enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext value);

/// Converts a string representing an ::ovrRichPresenceExtraContext to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrRichPresenceExtraContext) ovrRichPresenceExtraContext_FromString(const char* str);

#endif
