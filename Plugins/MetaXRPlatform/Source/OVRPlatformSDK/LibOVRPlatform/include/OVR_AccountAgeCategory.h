// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACCOUNT_AGE_CATEGORY_H
#define OVR_ACCOUNT_AGE_CATEGORY_H

#include "OVR_Platform_Defs.h"

/// Age category in Meta account. The values are used in
/// ovr_UserAgeCategory_Get() API.
typedef enum ovrAccountAgeCategory_ {
  ovrAccountAgeCategory_Unknown,
  /// Child age group for users between the ages of 10-12 (or applicable age in
  /// user's region)
  ovrAccountAgeCategory_Ch,
  /// Teenage age group for users between the ages of 13-17 (or applicable age in
  /// user's region)
  ovrAccountAgeCategory_Tn,
  /// Adult age group for users ages 18 and up (or applicable age in user's
  /// region)
  ovrAccountAgeCategory_Ad,
} ovrAccountAgeCategory;

/// Converts an ovrAccountAgeCategory enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAccountAgeCategory_ToString(ovrAccountAgeCategory value);

/// Converts a string representing an ovrAccountAgeCategory enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAccountAgeCategory) ovrAccountAgeCategory_FromString(const char* str);

#endif
