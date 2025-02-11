// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACHIEVEMENTPROGRESSARRAY_H
#define OVR_ACHIEVEMENTPROGRESSARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AchievementProgress.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrAchievementProgressHandle elements
typedef struct ovrAchievementProgressArray *ovrAchievementProgressArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrAchievementProgressHandle) ovr_AchievementProgressArray_GetElement(const ovrAchievementProgressArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementProgressArray_GetNextUrl(const ovrAchievementProgressArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_AchievementProgressArray_GetSize(const ovrAchievementProgressArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_AchievementProgressArray_HasNextPage(const ovrAchievementProgressArrayHandle obj);


#endif
