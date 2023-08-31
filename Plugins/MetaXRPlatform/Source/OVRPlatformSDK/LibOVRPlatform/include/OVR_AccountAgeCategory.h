// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACCOUNT_AGE_CATEGORY_H
#define OVR_ACCOUNT_AGE_CATEGORY_H

#include "OVR_Platform_Defs.h"

typedef enum ovrAccountAgeCategory_ {
  ovrAccountAgeCategory_Unknown,
  ovrAccountAgeCategory_Ch,
  ovrAccountAgeCategory_Tn,
  ovrAccountAgeCategory_Ad,
} ovrAccountAgeCategory;

/// Converts an ovrAccountAgeCategory enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAccountAgeCategory_ToString(ovrAccountAgeCategory value);

/// Converts a string representing an ovrAccountAgeCategory enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAccountAgeCategory) ovrAccountAgeCategory_FromString(const char* str);

#endif
