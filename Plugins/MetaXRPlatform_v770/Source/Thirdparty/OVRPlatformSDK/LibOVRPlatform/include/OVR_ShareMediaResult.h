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

#ifndef OVR_SHAREMEDIARESULT_H
#define OVR_SHAREMEDIARESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ShareMediaStatus.h"

/// \file
/// The result from users launching the Share to Facebook modal which enables
/// them to share local media files through ovr_Media_ShareToFacebook(). The
/// result will contain a status field, ovrShareMediaStatus().
typedef struct ovrShareMediaResult *ovrShareMediaResultHandle;

/// The status of the share media result. The status can be of the following
/// types:
///
/// ovrShareMediaStatus_Unknown()
///
/// ovrShareMediaStatus_Shared()
///
/// ovrShareMediaStatus_Canceled()
OVRP_PUBLIC_FUNCTION(ovrShareMediaStatus) ovr_ShareMediaResult_GetStatus(const ovrShareMediaResultHandle obj);


#endif
