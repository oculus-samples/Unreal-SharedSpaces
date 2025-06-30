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

#ifndef OVR_PARTY_UPDATE_ACTION_H
#define OVR_PARTY_UPDATE_ACTION_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enum that specifies the type of action related to the party and the
/// user. For example, ovr_PartyUpdateNotification_GetAction() contains the
/// information about the user joined or left the party or the user was invited
/// or uninvited to the party.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrPartyUpdateAction_ {
  ovrPartyUpdateAction_Unknown,
  /// This `enum` member indicates the user joined the party.
  ovrPartyUpdateAction_Join,
  /// This `enum` member indicates the user left the party.
  ovrPartyUpdateAction_Leave,
  /// This `enum` member indicates the user was invited to the party.
  ovrPartyUpdateAction_Invite,
  /// This `enum` member indicates the user was uninvited to the party.
  ovrPartyUpdateAction_Uninvite,
} ovrPartyUpdateAction;

/// Converts an ::ovrPartyUpdateAction enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrPartyUpdateAction_ToString(ovrPartyUpdateAction value);

/// Converts a string representing an ::ovrPartyUpdateAction to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrPartyUpdateAction) ovrPartyUpdateAction_FromString(const char* str);

#endif
