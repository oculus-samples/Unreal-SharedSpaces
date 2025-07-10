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

#ifndef OVR_ASSETDETAILS_H
#define OVR_ASSETDETAILS_H

#include "OVR_Platform_Defs.h"
#include "OVR_LanguagePackInfo.h"
#include "OVR_Types.h"

/// \file
/// An AssetDetails object contains detailed metadata for an asset file,
/// including the asset file ID, file path, asset type, and additional metadata
/// that characterizes the asset. You can retrieve the asset details using
/// ovr_AssetFile_GetList()
typedef struct ovrAssetDetails *ovrAssetDetailsHandle;

/// ID of the asset file. You can use this ID to uniquely identify a single
/// asset. You can find more details from ovr_AssetFile_StatusById()
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetDetails_GetAssetId(const ovrAssetDetailsHandle obj);

/// One of 'default', 'store', or 'language_pack'. The 'default' type denotes
/// this Asset File is used purely as an implementation detail (to download
/// extra content post-installation). The 'store' type shows, that the Asset
/// File should be shown in Store. The 'language_pack' is a special type used
/// to manage different languages and translation data, which can be downloaded
/// post-installation.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetDetails_GetAssetType(const ovrAssetDetailsHandle obj);

/// One of 'installed', 'available', or 'in-progress'
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetDetails_GetDownloadStatus(const ovrAssetDetailsHandle obj);

/// File path of the asset file
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetDetails_GetFilepath(const ovrAssetDetailsHandle obj);

/// The status of in app purchases which are some extra content that users can
/// buy right from apps. The value could be one of 'free', 'entitled', or 'not-
/// entitled'.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetDetails_GetIapStatus(const ovrAssetDetailsHandle obj);

/// This field gives information about currently selected and installed
/// language for the asset. The language info contains language name and tag in
/// BCP47 format.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrLanguagePackInfoHandle) ovr_AssetDetails_GetLanguage(const ovrAssetDetailsHandle obj);

/// Extra metadata associated with this asset file
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetDetails_GetMetadata(const ovrAssetDetailsHandle obj);


#endif
