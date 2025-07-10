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

#ifndef OVR_LIVESTREAMINGAPPLICATIONSTATUS_H
#define OVR_LIVESTREAMINGAPPLICATIONSTATUS_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// The livestreaming application status represents the status result of
/// whether the livestreaming is enabled for an app. If your app is enabled,
/// you will receive a notification by
/// #ovrMessage_Notification_Livestreaming_StatusChange when the livestreaming
/// session gets updated.
typedef struct ovrLivestreamingApplicationStatus *ovrLivestreamingApplicationStatusHandle;

/// This is a boolean field and represents whether the app is allowed to do the
/// livestreaming or not.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingApplicationStatus_GetStreamingEnabled(const ovrLivestreamingApplicationStatusHandle obj);


#endif
