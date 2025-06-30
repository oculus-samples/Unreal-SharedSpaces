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

#ifndef OVR_AVATAR_EDITOR_OPTIONS_H
#define OVR_AVATAR_EDITOR_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


/// \file
/// The Avatar Editor Option is a feature that allows users to create and
/// customize their avatars. It is launched by the
/// ovr_Avatar_LaunchAvatarEditor() request and provides a way for users to
/// specify the source of the request, allowing for more flexibility and
/// customization in the avatar creation process.
struct ovrAvatarEditorOptions;

typedef struct ovrAvatarEditorOptions* ovrAvatarEditorOptionsHandle;
/// \brief Creates a new instance of ovrAvatarEditorOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrAvatarEditorOptionsHandle) ovr_AvatarEditorOptions_Create();
/// \brief Destroys an existing instance of the ovrAvatarEditorOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_AvatarEditorOptions_Destroy(ovrAvatarEditorOptionsHandle handle);
/// Optional override for where the request is coming from. This field allows
/// you to specify the source of the request in the launched editor by calling
/// ovr_Avatar_LaunchAvatarEditor(), which can be useful in cases where you
/// want to track or identify the origin of the request.
OVRP_PUBLIC_FUNCTION(void) ovr_AvatarEditorOptions_SetSourceOverride(ovrAvatarEditorOptionsHandle handle, const char * value);

#endif
