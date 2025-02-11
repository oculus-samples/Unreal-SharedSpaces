// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_COWATCHINGSTATE_H
#define OVR_COWATCHINGSTATE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// It's designed to manage cowatching sessions within a shared virtual home
/// environment. This state primarily focuses on tracking whether a user is
/// currently participating in a cowatching session. If there is any change in
/// the cowatching state, it can be retrieved using
/// ovrNotification_Cowatching_InSessionChanged.
typedef struct ovrCowatchingState *ovrCowatchingStateHandle;

/// A `boolean` indicates if the current user is in a cowatching session. It
/// can be retrieved using ovr_Cowatching_IsInSession().
OVRP_PUBLIC_FUNCTION(bool) ovr_CowatchingState_GetInSession(const ovrCowatchingStateHandle obj);


#endif
