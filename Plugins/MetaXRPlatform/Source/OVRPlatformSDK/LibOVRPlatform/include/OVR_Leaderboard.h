// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARD_H
#define OVR_LEADERBOARD_H

#include "OVR_Platform_Defs.h"
#include "OVR_Destination.h"
#include "OVR_Types.h"

/// Leaderboards provide a way for a game to keep track of players and their
/// scores in relation to other. The leaderboard object contains information
/// about this leaderboard ID, API name and destination. Lean more about
/// [leaderboard](https://developer.oculus.com/documentation/native/ps-
/// leaderboards/) on our website.
typedef struct ovrLeaderboard *ovrLeaderboardHandle;

/// The API name of this leaderboard. This is a unique string that your
/// application will refer to this leaderboard in your app code.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Leaderboard_GetApiName(const ovrLeaderboardHandle obj);

/// An optional deep link ovrDestinationHandle, which means when a user clicks
/// on the leaderboard, they will be taken to this in-app destination.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrDestinationHandle) ovr_Leaderboard_GetDestination(const ovrLeaderboardHandle obj);

/// The generated GUID of this leaderboard.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Leaderboard_GetID(const ovrLeaderboardHandle obj);


#endif
