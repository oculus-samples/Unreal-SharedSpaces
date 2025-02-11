// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_INVITEPANELRESULTINFO_H
#define OVR_INVITEPANELRESULTINFO_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// The information about the user's invitation to others to join their current
/// session. It can be retrieved using ovr_GroupPresence_LaunchInvitePanel()}.
typedef struct ovrInvitePanelResultInfo *ovrInvitePanelResultInfoHandle;

/// A boolean for whether or not any invites have been sent.
OVRP_PUBLIC_FUNCTION(bool) ovr_InvitePanelResultInfo_GetInvitesSent(const ovrInvitePanelResultInfoHandle obj);


#endif
