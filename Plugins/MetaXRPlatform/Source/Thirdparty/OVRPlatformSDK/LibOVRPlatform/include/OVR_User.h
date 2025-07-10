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

#ifndef OVR_USER_H
#define OVR_USER_H

#include "OVR_Platform_Defs.h"
#include "OVR_ManagedInfo.h"
#include "OVR_Types.h"
#include "OVR_UserPresenceStatus.h"

/// \file
/// This is the class that represents the individual users who use your
/// application. Use the User object to retrieve information about your users,
/// help them interact with your application, and customize their experience.
/// You can query for information about a particular user using their user id,
/// ovr_User_GetID(). To learn more, read our
/// [docs](https://developer.oculus.com/documentation/native/ps-presence/#user-
/// and-friends) about users. Note: You must complete a Data Use Checkup(DUC)
/// in order to gain access to user platform features. Read more about DUC
/// [here](https://developer.oculus.com/resources/publish-data-use/).
typedef struct ovrUser *ovrUserHandle;

/// A potentially non unique displayable name chosen by the user. Could also be
/// the same as the oculus_ID. This is often the name shown to other users.
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetDisplayName(const ovrUserHandle obj);

/// The ID of the user, ovr_User_GetID(). This is a unique value for every
/// individual user.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_User_GetID(const ovrUserHandle obj);

/// The url of the profile picture that is chosen by the user. Retrieve this
/// url by using ovr_User_GetLoggedInUser().
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetImageUrl(const ovrUserHandle obj);

/// Managed account info, ::ovrManagedInfoHandle, for the user which contains
/// further metadata that is only available if the user is a Meta Managed
/// Account(MMA). There must be user consent via dialog during installation,
/// your app must have DUC enabled, and the app must be admin-approved.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrManagedInfoHandle) ovr_User_GetManagedInfo(const ovrUserHandle obj);

/// The oculus ID of the user. This is used across the developer dashboard and
/// is unique to oculus.
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetOculusID(const ovrUserHandle obj);

/// Human readable string of what the user is currently doing. Not intended to
/// be parsed as it might change at anytime or be translated.
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresence(const ovrUserHandle obj);

/// Intended to be parsed and used to deeplink to parts of the app. Read more
/// about deeplinking
/// [here](https://developer.oculus.com/documentation/native/ps-deep-linking/).
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceDeeplinkMessage(const ovrUserHandle obj);

/// If provided, this is the unique API Name that refers to the
/// ::ovrDestinationHandle this user is currently at in the app. Read more
/// about destinations
/// [here](https://developer.oculus.com/documentation/native/ps-destinations-
/// overview/)
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceDestinationApiName(const ovrUserHandle obj);

/// If provided, the lobby session this user is currently at in the
/// application. If the ApplicationInvite is generated from rich presence, the
/// lobby session id will be auto populated by calling
/// ovr_User_GetPresenceLobbySessionId() from the inviters' viewer context.
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceLobbySessionId(const ovrUserHandle obj);

/// If provided, the match session this user is currently at in the
/// application. If the ApplicationInvite is generated from rich presence, the
/// match session id will be auto populated by calling
/// ovr_User_GetPresenceMatchSessionId() from the inviters' viewer context.
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceMatchSessionId(const ovrUserHandle obj);

/// An enum value for the different statuses representing what the user is
/// currently doing. The different statuses can be
/// ovrUserPresenceStatus_Unknown(), ovrUserPresenceStatus_Offline(),
/// ovrUserPresenceStatus_Online().
OVRP_PUBLIC_FUNCTION(ovrUserPresenceStatus) ovr_User_GetPresenceStatus(const ovrUserHandle obj);

/// The url of the smaller/secondary profile picture that is chosen by the
/// user. Retrieve this url by using ovr_User_GetSmallImageUrl().
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetSmallImageUrl(const ovrUserHandle obj);


#endif
