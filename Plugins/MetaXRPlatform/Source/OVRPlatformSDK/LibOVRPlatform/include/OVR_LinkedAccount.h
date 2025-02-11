// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LINKEDACCOUNT_H
#define OVR_LINKEDACCOUNT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ServiceProvider.h"

/// Represents a linked account that is associated with the ovrUserHandle's
/// account in the system. It provides a way to store and manage information
/// about linked accounts in the system, allowing users to easily access and
/// manage their data or services from multiple platforms in one place
typedef struct ovrLinkedAccount *ovrLinkedAccountHandle;

/// Access token of the linked account. This token is used to authenticate the
/// user on the service provider's platform and grant access to their data or
/// services.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LinkedAccount_GetAccessToken(const ovrLinkedAccountHandle obj);

/// Service provider with which the linked account is associated. There are
/// several possible service providers that can be found in
/// ovrServiceProvider_ServiceProvider.
OVRP_PUBLIC_FUNCTION(ovrServiceProvider) ovr_LinkedAccount_GetServiceProvider(const ovrLinkedAccountHandle obj);

/// A unique identifier represents the user ID of the linked account. It can be
/// retrieved using ovr_User_GetID()
OVRP_PUBLIC_FUNCTION(const char *) ovr_LinkedAccount_GetUserId(const ovrLinkedAccountHandle obj);


#endif
