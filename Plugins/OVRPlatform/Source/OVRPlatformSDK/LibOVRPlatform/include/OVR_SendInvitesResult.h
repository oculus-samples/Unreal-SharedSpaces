// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SENDINVITESRESULT_H
#define OVR_SENDINVITESRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ApplicationInviteArray.h"

typedef struct ovrSendInvitesResult *ovrSendInvitesResultHandle;

/// The list of invites that was sent
OVRP_PUBLIC_FUNCTION(ovrApplicationInviteArrayHandle) ovr_SendInvitesResult_GetInvites(const ovrSendInvitesResultHandle obj);


#endif
