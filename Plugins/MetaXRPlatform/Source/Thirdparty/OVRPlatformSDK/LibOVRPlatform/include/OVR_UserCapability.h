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

#ifndef OVR_USERCAPABILITY_H
#define OVR_USERCAPABILITY_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// This object represents a permission or capability for the logged in user,
/// which can be retrieved by ovr_User_GetLoggedInUser(). It's a type of array
/// and there is a unique name for every user capability.
typedef struct ovrUserCapability *ovrUserCapabilityHandle;

/// The human readable description of the capability describing what possessing
/// it entails for a given ::ovrUserHandle.
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetDescription(const ovrUserCapabilityHandle obj);

/// Whether the capability is currently enabled for the user. When false, this
/// field will gate the ::ovrUserHandle from the specified services.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserCapability_GetIsEnabled(const ovrUserCapabilityHandle obj);

/// The unique identifier for the capability. An example capability could be
/// "earn_achievements".
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetName(const ovrUserCapabilityHandle obj);

/// This field specifies the reason the capability was enabled or disabled for
/// the given ::ovrUserHandle.
///
/// List of Reason Codes:
///
/// - REASON_UNKOWN
///
/// - SOCIAL_DISTANCING
///
/// - VERBAL_ABUSE
///
/// - TEXT_ABUSE
///
/// - PARENTAL_CONTROL
///
/// - DEVELOPER_ACTION
///
/// - SALSA_RESTRICTION
///
/// - SOCIAL_SUSPENSION
///
/// - PAYMENT_SUSPENSION
///
/// - PAYMENT_GIFTING_SUSPENSION
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetReasonCode(const ovrUserCapabilityHandle obj);


#endif
