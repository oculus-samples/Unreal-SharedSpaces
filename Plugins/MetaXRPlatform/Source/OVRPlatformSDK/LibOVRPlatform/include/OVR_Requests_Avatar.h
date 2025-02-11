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

/// Launches the Avatar Editor. Meta Avatars Editor is a feature that allows
/// users to edit their Meta Avatars appearances within the VR application that
/// they are currently using. This experience is often used by users to switch
/// their outfit and accessories to better suit the VR experience they are
/// experiencing. The result can be retrieved by
/// ovr_AvatarEditorResult_GetRequestSent().
/// \param options A ovr_AvatarEditorOptions_Create contains the options information, including an optional override for the source of the request, which is specified by ovr_AvatarEditorOptions_SetSourceOverride.
///
/// A message with type ::ovrMessage_Avatar_LaunchAvatarEditor will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAvatarEditorResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAvatarEditorResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Avatar_LaunchAvatarEditor(ovrAvatarEditorOptionsHandle options);

#endif
