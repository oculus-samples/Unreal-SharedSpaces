// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACHIEVEMENTDEFINITIONARRAY_H
#define OVR_ACHIEVEMENTDEFINITIONARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AchievementDefinition.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrAchievementDefinitionHandle elements
typedef struct ovrAchievementDefinitionArray *ovrAchievementDefinitionArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrAchievementDefinitionHandle) ovr_AchievementDefinitionArray_GetElement(const ovrAchievementDefinitionArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementDefinitionArray_GetNextUrl(const ovrAchievementDefinitionArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_AchievementDefinitionArray_GetSize(const ovrAchievementDefinitionArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_AchievementDefinitionArray_HasNextPage(const ovrAchievementDefinitionArrayHandle obj);


#endif
