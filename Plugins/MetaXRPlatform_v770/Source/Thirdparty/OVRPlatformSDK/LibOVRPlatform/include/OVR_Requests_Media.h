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

#ifndef OVR_REQUESTS_MEDIA_H
#define OVR_REQUESTS_MEDIA_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// # Media Overview
///
/// Sharing a screenshot or other media to Facebook is a great way to increase visibility of your
/// application to people that might not have a VR Headset.
///
/// ## Using Share Media to Facebook
///
/// Oculus currently supports sharing photos to Facebook. You can pass us the path to a screenshot
/// or other photo on the user's phone, and we'll launch a share-to-facebook modal, allowing
/// the user to share that photo to Facebook from VR. You can also pass us a default comment to
/// prepopulate the user's facebook status for the post.


/// \file
/// The media API provides a convenient and seamless way to share local media
/// files, such as photos (currently the only supported type), directly to
/// Facebook from within your application. This allows users to easily share
/// their favorite moments and memories with their friends and family on the
/// world's largest social media platform. With just a few simple steps, you
/// can enable your users to share their media files to Facebook, making it
/// easy for them to spread the word about your app and increase its
/// visibility. The payload returned for the sharing result is defined as
/// ::ovrShareMediaResultHandle.

/// Launch the Share to Facebook modal, allowing users to share local media
/// files to Facebook. Accepts a postTextSuggestion string for the default text
/// of the Facebook post. Requires a filePath string as the path to the image
/// to be shared to Facebook. This image should be located in your app's
/// internal storage directory. Requires a contentType indicating the type of
/// media to be shared (only 'photo' is currently supported). The payload for
/// the result is defined as ::ovrShareMediaResultHandle.
/// \param postTextSuggestion this text will prepopulate the facebook status text-input box within the share modal
/// \param filePath path to the file to be shared to facebook
/// \param contentType content type of the media to be shared
///
/// A message with type ::ovrMessage_Media_ShareToFacebook will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrShareMediaResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetShareMediaResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Media_ShareToFacebook(const char *postTextSuggestion, const char *filePath, ovrMediaContentType contentType);

#endif
