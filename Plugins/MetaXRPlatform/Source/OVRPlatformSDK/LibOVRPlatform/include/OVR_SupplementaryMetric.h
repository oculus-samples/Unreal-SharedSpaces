// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SUPPLEMENTARYMETRIC_H
#define OVR_SUPPLEMENTARYMETRIC_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// This is a supplemental piece of data that is used for a single write to
/// leaderboard entries. This metric is used for tiebreaker scenarios. You can
/// make such an entry by using
/// ovr_Leaderboard_WriteEntryWithSupplementaryMetric()
typedef struct ovrSupplementaryMetric *ovrSupplementaryMetricHandle;

/// The ID of the leaderboard that this supplementary metric belongs to. This
/// is the unique value for every ovrLeaderboardHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_SupplementaryMetric_GetID(const ovrSupplementaryMetricHandle obj);

/// This is the metric that is used to determine tiebreaks.
OVRP_PUBLIC_FUNCTION(long long) ovr_SupplementaryMetric_GetMetric(const ovrSupplementaryMetricHandle obj);


#endif
