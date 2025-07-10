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

#ifndef OVR_LEADERBOARD_H
#define OVR_LEADERBOARD_H

#include "OVR_Platform_Defs.h"
#include "OVR_Destination.h"
#include "OVR_Types.h"

/// \file
/// Leaderboards provide a way for a game to keep track of players and their
/// scores in relation to other. The leaderboard object contains information
/// about this leaderboard ID, API name and destination. Lean more about
/// [leaderboard](https://developer.oculus.com/documentation/native/ps-
/// leaderboards/) on our website.
typedef struct ovrLeaderboard *ovrLeaderboardHandle;

/// The API name of this leaderboard. This is a unique string that your
/// application will refer to this leaderboard in your app code.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Leaderboard_GetApiName(const ovrLeaderboardHandle obj);

/// An optional deep link ::ovrDestinationHandle, which means when a user
/// clicks on the leaderboard, they will be taken to this in-app destination.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrDestinationHandle) ovr_Leaderboard_GetDestination(const ovrLeaderboardHandle obj);

/// The generated GUID of this leaderboard.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Leaderboard_GetID(const ovrLeaderboardHandle obj);


#endif
