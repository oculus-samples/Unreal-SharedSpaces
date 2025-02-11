// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SENDINVITESRESULT_H
#define OVR_SENDINVITESRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ApplicationInviteArray.h"

/// The result of sending an invite to a user or list of users shows invites
/// were sent successfully through the resulting array. This is the model
/// returned in a successful response to the ovr_GroupPresence_SendInvites()
/// api.
typedef struct ovrSendInvitesResult *ovrSendInvitesResultHandle;

/// The list of invites that was sent through ovr_GroupPresence_SendInvites().
/// This invite list can comprise of friends and recently met users.
OVRP_PUBLIC_FUNCTION(ovrApplicationInviteArrayHandle) ovr_SendInvitesResult_GetInvites(const ovrSendInvitesResultHandle obj);


#endif
