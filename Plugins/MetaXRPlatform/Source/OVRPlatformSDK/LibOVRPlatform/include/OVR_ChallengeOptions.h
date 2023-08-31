// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_OPTIONS_H
#define OVR_CHALLENGE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_ChallengeViewerFilter.h"
#include "OVR_ChallengeVisibility.h"

struct ovrChallengeOptions;
typedef struct ovrChallengeOptions* ovrChallengeOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrChallengeOptionsHandle) ovr_ChallengeOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_Destroy(ovrChallengeOptionsHandle handle);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetDescription(ovrChallengeOptionsHandle handle, const char * value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetEndDate(ovrChallengeOptionsHandle handle, unsigned long long value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludeActiveChallenges(ovrChallengeOptionsHandle handle, bool value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludeFutureChallenges(ovrChallengeOptionsHandle handle, bool value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludePastChallenges(ovrChallengeOptionsHandle handle, bool value);
/// Optional: Only find challenges belonging to this leaderboard.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetLeaderboardName(ovrChallengeOptionsHandle handle, const char * value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetStartDate(ovrChallengeOptionsHandle handle, unsigned long long value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetTitle(ovrChallengeOptionsHandle handle, const char * value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle handle, ovrChallengeViewerFilter value);
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle handle, ovrChallengeVisibility value);

#endif
