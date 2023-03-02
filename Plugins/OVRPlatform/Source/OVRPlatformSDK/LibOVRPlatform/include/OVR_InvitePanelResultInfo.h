// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_INVITEPANELRESULTINFO_H
#define OVR_INVITEPANELRESULTINFO_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

typedef struct ovrInvitePanelResultInfo *ovrInvitePanelResultInfoHandle;

/// A boolean for whether or not any invites has been sent.
OVRP_PUBLIC_FUNCTION(bool) ovr_InvitePanelResultInfo_GetInvitesSent(const ovrInvitePanelResultInfoHandle obj);


#endif
