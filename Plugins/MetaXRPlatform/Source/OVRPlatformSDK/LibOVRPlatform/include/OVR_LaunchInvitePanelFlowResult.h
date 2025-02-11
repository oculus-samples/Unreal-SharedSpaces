// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCHINVITEPANELFLOWRESULT_H
#define OVR_LAUNCHINVITEPANELFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_UserArray.h"

/// Sent when the user is finished using the invite panel to send out
/// invitations. Contains a list of invitees. It can be retrieved using
/// ovrNotification_GroupPresence_InvitationsSent.
typedef struct ovrLaunchInvitePanelFlowResult *ovrLaunchInvitePanelFlowResultHandle;

/// A list of users that were sent an invitation to the session.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_LaunchInvitePanelFlowResult_GetInvitedUsers(const ovrLaunchInvitePanelFlowResultHandle obj);


#endif
