// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_AGE_CATEGORY_H
#define OVR_APP_AGE_CATEGORY_H

#include "OVR_Platform_Defs.h"

/// Age category for developers to send to Meta. The values are used in
/// ovr_UserAgeCategory_Report() API.
typedef enum ovrAppAgeCategory_ {
  ovrAppAgeCategory_Unknown,
  /// Child age group for users between the ages of 10-12 (or applicable age in
  /// user's region)
  ovrAppAgeCategory_Ch,
  /// Non-child age group for users ages 13 and up (or applicable age in user's
  /// region)
  ovrAppAgeCategory_Nch,
} ovrAppAgeCategory;

/// Converts an ovrAppAgeCategory enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppAgeCategory_ToString(ovrAppAgeCategory value);

/// Converts a string representing an ovrAppAgeCategory enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAppAgeCategory) ovrAppAgeCategory_FromString(const char* str);

#endif
