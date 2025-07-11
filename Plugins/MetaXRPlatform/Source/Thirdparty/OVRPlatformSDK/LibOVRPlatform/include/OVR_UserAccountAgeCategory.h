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

#ifndef OVR_USERACCOUNTAGECATEGORY_H
#define OVR_USERACCOUNTAGECATEGORY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AccountAgeCategory.h"

/// \file
/// A UserAccountAgeCategory represents the age category of a Meta user. This
/// object contains information about the user's age group, which can be used
/// for various purposes such as targeted advertising or content restriction.
/// The possible values for the age category are defined in the
/// ovrAccountAgeCategory().
typedef struct ovrUserAccountAgeCategory *ovrUserAccountAgeCategoryHandle;

/// Age category of the user in Meta account. This field represents the age
/// group that the user falls into, and the possible values for this field are
/// defined in the ovrAccountAgeCategory().
OVRP_PUBLIC_FUNCTION(ovrAccountAgeCategory) ovr_UserAccountAgeCategory_GetAgeCategory(const ovrUserAccountAgeCategoryHandle obj);


#endif
