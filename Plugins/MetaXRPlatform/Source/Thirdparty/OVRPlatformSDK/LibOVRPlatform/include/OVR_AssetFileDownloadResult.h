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

#ifndef OVR_ASSETFILEDOWNLOADRESULT_H
#define OVR_ASSETFILEDOWNLOADRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// An AssetFileDownloadResult represents an asset that has been successfully
/// downloaded. It's used to store information about an asset that has been
/// downloaded, such as its location on the local file system and its unique
/// identifier asset file ID. It can be retrieved using
/// ovr_AssetFile_DownloadByName().
typedef struct ovrAssetFileDownloadResult *ovrAssetFileDownloadResultHandle;

/// ID of the asset file. It can be retrieved using
/// ovr_AssetDetails_GetAssetId(). It can be used to retrieve the
/// AssetFileDownloadResult by ovr_AssetFile_DownloadById().
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetFileDownloadResult_GetAssetId(const ovrAssetFileDownloadResultHandle obj);

/// File path of the asset file.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetFileDownloadResult_GetFilepath(const ovrAssetFileDownloadResultHandle obj);


#endif
