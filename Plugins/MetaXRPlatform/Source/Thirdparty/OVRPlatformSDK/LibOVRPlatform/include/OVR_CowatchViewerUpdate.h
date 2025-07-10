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

#ifndef OVR_COWATCHVIEWERUPDATE_H
#define OVR_COWATCHVIEWERUPDATE_H

#include "OVR_Platform_Defs.h"
#include "OVR_CowatchViewerArray.h"
#include "OVR_Types.h"

/// \file
/// CowatchWiewerUpdate is used to represent updates to viewer data within a
/// cowatching session. It's essential for managing and synchronizing viewer
/// data in real-time during cowatching sessions. It can be retrieved using
/// #ovrMessage_Notification_Cowatching_ViewersDataChanged when a user joins or
/// updates their viewer data.
typedef struct ovrCowatchViewerUpdate *ovrCowatchViewerUpdateHandle;

/// List of viewer data of all cowatch participants who is in a cowatching
/// session. It can be retrieved using ovr_Cowatching_GetViewersData().
OVRP_PUBLIC_FUNCTION(ovrCowatchViewerArrayHandle) ovr_CowatchViewerUpdate_GetDataList(const ovrCowatchViewerUpdateHandle obj);

/// A unique user ID of the user whose viewer data has been updated.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_CowatchViewerUpdate_GetId(const ovrCowatchViewerUpdateHandle obj);


#endif
