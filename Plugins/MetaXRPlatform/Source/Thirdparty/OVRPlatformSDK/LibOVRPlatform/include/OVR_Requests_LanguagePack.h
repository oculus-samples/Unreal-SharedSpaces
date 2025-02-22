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

#ifndef OVR_REQUESTS_LANGUAGEPACK_H
#define OVR_REQUESTS_LANGUAGEPACK_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"



/// \file
/// The LanguagePack API provides a way to manage language packs for an
/// application. A language pack is a collection of assets that are specific to
/// a particular language, such as translations of text, audio files, and
/// images. For more information, see
/// [here](https://developer.oculus.com/documentation/native/ps-language-
/// packs/).

/// Returns currently installed and selected language pack for an app in the
/// view of the ::ovrAssetDetailsHandle. Use ovr_AssetDetails_GetLanguage()
/// field to extract needed language info. A particular language can be
/// download and installed by a user from the Oculus app on the application
/// page.
///
/// A message with type ::ovrMessage_LanguagePack_GetCurrent will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAssetDetailsHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAssetDetails().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_LanguagePack_GetCurrent();

/// Sets the current language to specified. The parameter is the BCP47 language
/// tag. If a language pack is not downloaded yet, spawns automatically the
/// ovr_AssetFile_DownloadByName() request, and sends periodic
/// #ovrMessage_Notification_AssetFile_DownloadUpdate to track the downloads.
/// Once the language asset file is downloaded, call
/// ovr_LanguagePack_GetCurrent() to retrieve the data, and use the language at
/// runtime.
/// \param tag The BCP47 language tag that identifies the language to be set as the current language.
///
/// A message with type ::ovrMessage_LanguagePack_SetCurrent will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAssetFileDownloadResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAssetFileDownloadResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_LanguagePack_SetCurrent(const char *tag);

#endif
