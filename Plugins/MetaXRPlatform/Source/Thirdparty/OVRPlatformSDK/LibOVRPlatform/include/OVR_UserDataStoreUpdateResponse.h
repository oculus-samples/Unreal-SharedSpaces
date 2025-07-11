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

#ifndef OVR_USERDATASTOREUPDATERESPONSE_H
#define OVR_USERDATASTOREUPDATERESPONSE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// This payload contains information about the result of an update request to
/// the user data store. It includes a success field
/// ovr_UserDataStoreUpdateResponse_GetSuccess() that indicates whether the
/// update was successful or not. See more info about Platform Solutions
/// [here](https://developer.oculus.com/documentation/native/ps-platform-
/// intro/).
typedef struct ovrUserDataStoreUpdateResponse *ovrUserDataStoreUpdateResponseHandle;

/// Indicates whether the update request was successful or not. A value of true
/// indicates that the update was successful, while a value of false indicates
/// that the update failed.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserDataStoreUpdateResponse_GetSuccess(const ovrUserDataStoreUpdateResponseHandle obj);


#endif
