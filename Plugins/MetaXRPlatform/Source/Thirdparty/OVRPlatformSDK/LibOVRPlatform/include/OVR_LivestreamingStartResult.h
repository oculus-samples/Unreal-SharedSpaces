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

#ifndef OVR_LIVESTREAMINGSTARTRESULT_H
#define OVR_LIVESTREAMINGSTARTRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_LivestreamingStartStatus.h"

/// \file
/// You will receive this livestreaming start result once you start a
/// livestream to Facebook or to a party in your app. This result will show if
/// the start status is a success or unknown or a failure because of various
/// reasons including no Facebook connection or missing parameters.
typedef struct ovrLivestreamingStartResult *ovrLivestreamingStartResultHandle;

/// This livestreaming result represents the start status of your livestream.
/// You can refer to ovrLivestreamingStartStatus() for possible status info.
OVRP_PUBLIC_FUNCTION(ovrLivestreamingStartStatus) ovr_LivestreamingStartResult_GetStreamingResult(const ovrLivestreamingStartResultHandle obj);


#endif
