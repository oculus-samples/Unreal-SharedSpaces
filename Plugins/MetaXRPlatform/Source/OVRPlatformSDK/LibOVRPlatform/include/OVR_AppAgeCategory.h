// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_AGE_CATEGORY_H
#define OVR_APP_AGE_CATEGORY_H

#include "OVR_Platform_Defs.h"

typedef enum ovrAppAgeCategory_ {
  ovrAppAgeCategory_Unknown,
  ovrAppAgeCategory_Ch,
  ovrAppAgeCategory_Nch,
} ovrAppAgeCategory;

/// Converts an ovrAppAgeCategory enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppAgeCategory_ToString(ovrAppAgeCategory value);

/// Converts a string representing an ovrAppAgeCategory enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAppAgeCategory) ovrAppAgeCategory_FromString(const char* str);

#endif
