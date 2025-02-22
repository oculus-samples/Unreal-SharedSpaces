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

#ifndef OVR_SDKACCOUNT_H
#define OVR_SDKACCOUNT_H

#include "OVR_Platform_Defs.h"
#include "OVR_SdkAccountType.h"
#include "OVR_Types.h"

/// \file
/// A single user can have multiple sdk accounts associated with it. SDK
/// accounts represent the oculus user and x-accounts that are linked to the
/// particular user. Retrieve the SDK accounts by using,
/// ovr_User_GetSdkAccounts().
typedef struct ovrSdkAccount *ovrSdkAccountHandle;

/// The specific type of account that this sdk account represents. The type can
/// be one of the following:
///
/// ovrSdkAccountType_Unknown()
///
/// ovrSdkAccountType_Oculus()
///
/// ovrSdkAccountType_FacebookGameroom()
OVRP_PUBLIC_FUNCTION(ovrSdkAccountType) ovr_SdkAccount_GetAccountType(const ovrSdkAccountHandle obj);

/// The ID of the user, ovr_User_GetID(), of the sdk account. This is a unique
/// value for every ::ovrUserHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_SdkAccount_GetUserId(const ovrSdkAccountHandle obj);


#endif
