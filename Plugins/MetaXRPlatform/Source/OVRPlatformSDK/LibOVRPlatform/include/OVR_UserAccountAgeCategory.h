// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERACCOUNTAGECATEGORY_H
#define OVR_USERACCOUNTAGECATEGORY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AccountAgeCategory.h"

typedef struct ovrUserAccountAgeCategory *ovrUserAccountAgeCategoryHandle;

/// Age category of the user in Meta account.
OVRP_PUBLIC_FUNCTION(ovrAccountAgeCategory) ovr_UserAccountAgeCategory_GetAgeCategory(const ovrUserAccountAgeCategoryHandle obj);


#endif
