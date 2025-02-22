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

#ifndef OVR_REQUESTS_USERAGECATEGORY_H
#define OVR_REQUESTS_USERAGECATEGORY_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AccountAgeCategory.h"
#include "OVR_AppAgeCategory.h"


/// \file
/// Users are divided into three categories based on their age:
/// -ovrAccountAgeCategory_Ch(): Child age group for users between the ages of
/// 10-12 (or applicable age in user's region). -ovrAccountAgeCategory_Tn():
/// Teenage age group for users between the ages of 13-17 (or applicable age in
/// user's region). -ovrAccountAgeCategory_Ad(): Adult age group for users ages
/// 18 and up (or applicable age in user's region).

/// Retrieve the user age category for the current user. It can be used in
/// ovr_UserAccountAgeCategory_GetAgeCategory()
///
/// A message with type ::ovrMessage_UserAgeCategory_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserAccountAgeCategoryHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserAccountAgeCategory().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserAgeCategory_Get();

/// Report the current user's age category to Meta.
/// \param age_category Age category for developers to send to Meta. There are two members, children age group (ovrAppAgeCategory_Ch()) and non-children age group (ovrAppAgeCategory_Nch()).
///
/// A message with type ::ovrMessage_UserAgeCategory_Report will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserAgeCategory_Report(ovrAppAgeCategory age_category);

#endif
