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

#ifndef OVR_MANAGEDINFO_H
#define OVR_MANAGEDINFO_H

#include "OVR_Platform_Defs.h"

/// \file
/// If the user is a Meta Managed Account(MMA), the managed account for the
/// user will contain further metadata information. There must be user consent
/// via dialog during installation, your app must have
/// [DUC](https://developer.oculus.com/resources/publish-data-use/) enabled,
/// and the app must be admin-approved.
typedef struct ovrManagedInfo *ovrManagedInfoHandle;

/// A string represents the department name in the organization to which the
/// user blongs to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetDepartment(const ovrManagedInfoHandle obj);

/// The email address of the account user which owns the MMA, i.e., Meta
/// Managed Account.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetEmail(const ovrManagedInfoHandle obj);

/// A string represents the employee number of the person who owns MMA, i.e.,
/// Meta Managed Account.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetEmployeeNumber(const ovrManagedInfoHandle obj);

/// A string which can be used to uniquely identify the user of the MMA, i.e.,
/// Meta Managed Account.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetExternalId(const ovrManagedInfoHandle obj);

/// A string contains the information about the location of the user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetLocation(const ovrManagedInfoHandle obj);

/// A string contains the information about the manager of the user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetManager(const ovrManagedInfoHandle obj);

/// A string contrains the information about the user's name.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetName(const ovrManagedInfoHandle obj);

/// A string which can be used to uniquely identify the organization which owns
/// the MMA, i.e., Meta Managed Account.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetOrganizationId(const ovrManagedInfoHandle obj);

/// The name of the organization to which the MMA(i.e., Meta Managed Account)
/// account user belongs to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetOrganizationName(const ovrManagedInfoHandle obj);

/// A string contains the position information of the user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetPosition(const ovrManagedInfoHandle obj);


#endif
