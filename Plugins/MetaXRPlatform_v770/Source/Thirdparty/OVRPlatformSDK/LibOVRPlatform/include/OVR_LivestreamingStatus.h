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

#ifndef OVR_LIVESTREAMINGSTATUS_H
#define OVR_LIVESTREAMINGSTATUS_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// The livestreaming status represents the status of a livestreaming event in
/// your app. You will receive a notification by
/// #ovrMessage_Notification_Livestreaming_StatusChange whenever your
/// livestreaming session gets updated. The status contains info about your
/// livestream type, whether your mic is enabled, whether the comments are
/// visible and etc.
typedef struct ovrLivestreamingStatus *ovrLivestreamingStatusHandle;

/// This boolean field indicates if the comments from the audience in your
/// livestreaming are visible.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingStatus_GetCommentsVisible(const ovrLivestreamingStatusHandle obj);

/// This boolean field indicates if your livestreaming in the app is paused or
/// not.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingStatus_GetIsPaused(const ovrLivestreamingStatusHandle obj);

/// This boolean field indicates if your app is livestreaming enabled. If your
/// app is enabled, you will receive a notification by
/// #ovrMessage_Notification_Livestreaming_StatusChange when the livestreaming
/// session gets updated.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingStatus_GetLivestreamingEnabled(const ovrLivestreamingStatusHandle obj);

/// This field indicates the type of your livestreaming.
OVRP_PUBLIC_FUNCTION(int) ovr_LivestreamingStatus_GetLivestreamingType(const ovrLivestreamingStatusHandle obj);

/// This boolean field indicates if your connected mic is enabled. The speaker
/// will be muted if the field is false.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingStatus_GetMicEnabled(const ovrLivestreamingStatusHandle obj);


#endif
