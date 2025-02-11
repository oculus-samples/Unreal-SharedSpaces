// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_COWATCHVIEWERUPDATE_H
#define OVR_COWATCHVIEWERUPDATE_H

#include "OVR_Platform_Defs.h"
#include "OVR_CowatchViewerArray.h"
#include "OVR_Types.h"

/// CowatchWiewerUpdate is used to represent updates to viewer data within a
/// cowatching session. It's essential for managing and synchronizing viewer
/// data in real-time during cowatching sessions. It can be retrieved using
/// ovrNotification_Cowatching_ViewersDataChanged when a user joins or updates
/// their viewer data.
typedef struct ovrCowatchViewerUpdate *ovrCowatchViewerUpdateHandle;

/// List of viewer data of all cowatch participants who is in a cowatching
/// session. It can be retrieved using ovr_Cowatching_GetViewersData().
OVRP_PUBLIC_FUNCTION(ovrCowatchViewerArrayHandle) ovr_CowatchViewerUpdate_GetDataList(const ovrCowatchViewerUpdateHandle obj);

/// A unique user ID of the user whose viewer data has been updated.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_CowatchViewerUpdate_GetId(const ovrCowatchViewerUpdateHandle obj);


#endif
