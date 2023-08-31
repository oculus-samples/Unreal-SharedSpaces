// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_USERAGECATEGORY_H
#define OVR_REQUESTS_USERAGECATEGORY_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AccountAgeCategory.h"
#include "OVR_AppAgeCategory.h"

/// Retrieve the user age category for the current user.
///
/// A message with type ::ovrMessage_UserAgeCategory_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserAccountAgeCategoryHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserAccountAgeCategory().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserAgeCategory_Get();

/// Report the current user's age category to Meta.
///
/// A message with type ::ovrMessage_UserAgeCategory_Report will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserAgeCategory_Report(ovrAppAgeCategory age_category);

#endif
