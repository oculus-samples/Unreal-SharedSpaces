// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ORGSCOPEDID_H
#define OVR_ORGSCOPEDID_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// An ID for a ovrUserHandle which is unique per Developer Center
/// organization. It can be retrieved using ovr_User_GetOrgScopedID().
typedef struct ovrOrgScopedID *ovrOrgScopedIDHandle;

/// The unique id of the user, allowing different apps within the same
/// Developer Center organization to have a consistent id for the same user.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_OrgScopedID_GetID(const ovrOrgScopedIDHandle obj);


#endif
