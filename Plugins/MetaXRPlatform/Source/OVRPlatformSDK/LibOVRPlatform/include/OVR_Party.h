// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTY_H
#define OVR_PARTY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_User.h"
#include "OVR_UserArray.h"

/// Parties allow users to start a voice chat with other members of the party.
/// Party voice chats persist across apps in VR and users can continue to
/// interact while navigating between apps. You can load a user's party by
/// using ovr_Party_GetCurrent().
typedef struct ovrParty *ovrPartyHandle;

/// A unique identifier of this party. It can be used by ovr_Party_Join(),
/// ovr_Party_Leave(), and ovr_Party_Invite().
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Party_GetID(const ovrPartyHandle obj);

/// An array of users who are invited to this party. These users are not a part
/// of the party yet but have been invited.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Party_GetInvitedUsers(const ovrPartyHandle obj);

/// The user who initialized this party. It's also the first user who joined
/// the party. The leader can invite and kick other users.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_Party_GetLeader(const ovrPartyHandle obj);

/// An array that contains the users who are currently in this party. These
/// users will remain in the party while navigating between apps.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Party_GetUsers(const ovrPartyHandle obj);


#endif
