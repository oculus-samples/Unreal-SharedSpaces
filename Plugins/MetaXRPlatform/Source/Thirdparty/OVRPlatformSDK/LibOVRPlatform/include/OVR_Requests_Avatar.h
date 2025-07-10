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

#ifndef OVR_REQUESTS_AVATAR_H
#define OVR_REQUESTS_AVATAR_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AvatarEditorOptions.h"

/// \file
/// # Avatar Overview.
///
/// Currently this is an internal-only subsystem, used as a helper by the
/// AvatarSDK team to upload new updateMetaData for avatar information because
/// writing multi-part upload is a pain in the butt.
///
/// ovr_UpdateMetaData() is a helper method used for providing a
/// metadata JSON string and path to a valid file on disk and uploading
/// those to a GraphAPI endpoint.


/// \file
/// The Avatars API allows developers to create highly expressive, diverse, and
/// customizable avatar identities for the Meta ecosystem, Unity VR apps, and
/// other multiplayer experiences. The ovr_Avatar_LaunchAvatarEditor() method
/// launches the Avatar Editor, where users can create and customize their
/// avatars, the result can be retrieved by
/// ovr_AvatarEditorResult_GetRequestSent().

/// Launches the Avatar Editor. Meta Avatars Editor is a feature that allows
/// users to edit their Meta Avatars appearances within the VR application that
/// they are currently using. This experience is often used by users to switch
/// their outfit and accessories to better suit the VR experience they are
/// experiencing. The result can be retrieved by
/// ovr_AvatarEditorResult_GetRequestSent().
/// \param options A ovr_AvatarEditorOptions_Create() contains the options information, including an optional override for the source of the request, which is specified by ovr_AvatarEditorOptions_SetSourceOverride().
///
/// A message with type ::ovrMessage_Avatar_LaunchAvatarEditor will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAvatarEditorResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAvatarEditorResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Avatar_LaunchAvatarEditor(ovrAvatarEditorOptionsHandle options);

#endif
