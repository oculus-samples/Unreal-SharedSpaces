// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERCAPABILITY_H
#define OVR_USERCAPABILITY_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// This object represents a permission or capability for a particular user.
/// You can fetch all the user capabilities for a logged-in ovrUserHandle by
/// using ovr_User_GetUserCapabilities(). There is a unique name for every user
/// capability.
typedef struct ovrUserCapability *ovrUserCapabilityHandle;

/// The human readable description of the capability describing what possessing
/// it entails for a given ovrUserHandle.
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetDescription(const ovrUserCapabilityHandle obj);

/// Whether the capability is currently enabled for the user. When false, this
/// field will gate the ovrUserHandle from the specified services.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserCapability_GetIsEnabled(const ovrUserCapabilityHandle obj);

/// The unique identifier for the capability. An example capability could be
/// "earn_achievements".
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetName(const ovrUserCapabilityHandle obj);

/// This field specifies the reason the capability was enabled or disabled for
/// the given ovrUserHandle.
///
/// List of Reason Codes:
///
/// - REASON_UNKOWN
///
/// - SOCIAL_DISTANCING
///
/// - VERBAL_ABUSE
///
/// - TEXT_ABUSE
///
/// - PARENTAL_CONTROL
///
/// - DEVELOPER_ACTION
///
/// - SALSA_RESTRICTION
///
/// - SOCIAL_SUSPENSION
///
/// - PAYMENT_SUSPENSION
///
/// - PAYMENT_GIFTING_SUSPENSION
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetReasonCode(const ovrUserCapabilityHandle obj);


#endif
