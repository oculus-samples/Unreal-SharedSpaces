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

#ifndef OVR_BLOCKEDUSER_H
#define OVR_BLOCKEDUSER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// It contains an array of users who have been blocked by the logged in user.
/// You can't follow, be followed, invited, or searched by a blocked user. It
/// can be retrieved using ovr_User_GetBlockedUsers().
typedef struct ovrBlockedUser *ovrBlockedUserHandle;

/// It represents the user ID that has been blocked by the logged in user. It
/// is a type of ID and can be retrieved using ovr_User_GetID().
OVRP_PUBLIC_FUNCTION(ovrID) ovr_BlockedUser_GetId(const ovrBlockedUserHandle obj);


#endif
