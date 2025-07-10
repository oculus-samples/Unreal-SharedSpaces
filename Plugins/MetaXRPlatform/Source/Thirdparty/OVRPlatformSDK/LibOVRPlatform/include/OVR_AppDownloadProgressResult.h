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

#ifndef OVR_APPDOWNLOADPROGRESSRESULT_H
#define OVR_APPDOWNLOADPROGRESSRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_AppStatus.h"

/// \file
/// Represents the result of the download of an application. You can retrieve
/// it using CheckAppDownloadProgress API
/// (ovr_Application_CheckAppDownloadProgress()). You can use this to check the
/// progress and the status of an ongoing app download operation.
typedef struct ovrAppDownloadProgressResult *ovrAppDownloadProgressResultHandle;

/// Total number of bytes that need to be downloaded
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadBytes(const ovrAppDownloadProgressResultHandle obj);

/// Number of bytes that have already been downloaded. You can use this and
/// ovr_AppDownloadProgressResult_GetDownloadBytes() to implement the progress
/// bar.
OVRP_PUBLIC_FUNCTION(long long) ovr_AppDownloadProgressResult_GetDownloadedBytes(const ovrAppDownloadProgressResultHandle obj);

/// Status code of the current app status. You can use it to find out whether
/// the app is being downloaded or queued for downloading
OVRP_PUBLIC_FUNCTION(ovrAppStatus) ovr_AppDownloadProgressResult_GetStatusCode(const ovrAppDownloadProgressResultHandle obj);


#endif
