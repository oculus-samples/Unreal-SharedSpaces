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

#ifndef OVR_AVATAREDITORRESULT_H
#define OVR_AVATAREDITORRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// This is the result that can be extracted from message payload when the
/// avatar editor is launched via a call to ovr_Avatar_LaunchAvatarEditor(). It
/// contains information about whether the avatar editor result has
/// successfully been sent.
typedef struct ovrAvatarEditorResult *ovrAvatarEditorResultHandle;

/// This indicates whether the request has been sent successfully. This is an
/// optional `boolean`. If the boolean field isn't there, it indicates that the
/// response is an error and will throw an error message.
OVRP_PUBLIC_FUNCTION(bool) ovr_AvatarEditorResult_GetRequestSent(const ovrAvatarEditorResultHandle obj);


#endif
