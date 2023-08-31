// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEENTRY_H
#define OVR_CHALLENGEENTRY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_User.h"

typedef struct ovrChallengeEntry *ovrChallengeEntryHandle;

OVRP_PUBLIC_FUNCTION(const char *)       ovr_ChallengeEntry_GetDisplayScore(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(const char *)       ovr_ChallengeEntry_GetExtraData(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned int)       ovr_ChallengeEntry_GetExtraDataLength(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(ovrID)              ovr_ChallengeEntry_GetID(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(int)                ovr_ChallengeEntry_GetRank(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(long long)          ovr_ChallengeEntry_GetScore(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeEntry_GetTimestamp(const ovrChallengeEntryHandle obj);
OVRP_PUBLIC_FUNCTION(ovrUserHandle)      ovr_ChallengeEntry_GetUser(const ovrChallengeEntryHandle obj);

#endif
