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

#ifndef OVR_USER_ORDERING_H
#define OVR_USER_ORDERING_H

#include "OVR_Platform_Defs.h"

/// \file
/// The ordering that is used when returning a list of users.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrUserOrdering_ {
  ovrUserOrdering_Unknown,
  /// No preference for ordering (could be in any or no order)
  ovrUserOrdering_None,
  /// Orders by online users first and then offline users. Within each group the
  /// users are ordered alphabetically by display name
  ovrUserOrdering_PresenceAlphabetical,
} ovrUserOrdering;

/// Converts an ::ovrUserOrdering enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrUserOrdering_ToString(ovrUserOrdering value);

/// Converts a string representing an ::ovrUserOrdering to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrUserOrdering) ovrUserOrdering_FromString(const char* str);

#endif
