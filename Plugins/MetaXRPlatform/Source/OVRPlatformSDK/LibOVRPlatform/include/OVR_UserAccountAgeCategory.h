// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERACCOUNTAGECATEGORY_H
#define OVR_USERACCOUNTAGECATEGORY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AccountAgeCategory.h"

/// A UserAccountAgeCategory represents the age category of a Meta user. This
/// object contains information about the user's age group, which can be used
/// for various purposes such as targeted advertising or content restriction.
/// The possible values for the age category are defined in the
/// ovrAccountAgeCategory_AccountAgeCategory.
typedef struct ovrUserAccountAgeCategory *ovrUserAccountAgeCategoryHandle;

/// Age category of the user in Meta account. This field represents the age
/// group that the user falls into, and the possible values for this field are
/// defined in the ovrAccountAgeCategory_AccountAgeCategory.
OVRP_PUBLIC_FUNCTION(ovrAccountAgeCategory) ovr_UserAccountAgeCategory_GetAgeCategory(const ovrUserAccountAgeCategoryHandle obj);


#endif
