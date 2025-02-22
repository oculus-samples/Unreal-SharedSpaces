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

#ifndef OVR_ASSETFILEDOWNLOADCANCELRESULT_H
#define OVR_ASSETFILEDOWNLOADCANCELRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// \file
/// An AssetFileDownloadCancelResult represents the result of a canceled
/// download action of an asset file. You can cancel a download of an asset
/// file by using ovr_AssetFile_DownloadCancelById() or
/// ovr_AssetFile_DownloadCancelByName(). The result contains three fields
/// which are the asset file ID(use
/// ovr_AssetFileDownloadCancelResult_GetAssetId() to access), the file path,
/// and success status of the canceled download.
typedef struct ovrAssetFileDownloadCancelResult *ovrAssetFileDownloadCancelResultHandle;

/// \deprecated You can use ovr_AssetFileDownloadCancelResult_GetAssetId() to retrieve the ID of the asset file instead.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetFileDownloadCancelResult_GetAssetFileId(const ovrAssetFileDownloadCancelResultHandle obj);

/// ID of the asset file. NOTE: this does not represent the ID of the asset.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetFileDownloadCancelResult_GetAssetId(const ovrAssetFileDownloadCancelResultHandle obj);

/// File path of the asset file.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetFileDownloadCancelResult_GetFilepath(const ovrAssetFileDownloadCancelResultHandle obj);

/// You can use this to determine whether the cancel request of downloading an
/// asset file has succeeded.
OVRP_PUBLIC_FUNCTION(bool) ovr_AssetFileDownloadCancelResult_GetSuccess(const ovrAssetFileDownloadCancelResultHandle obj);


#endif
