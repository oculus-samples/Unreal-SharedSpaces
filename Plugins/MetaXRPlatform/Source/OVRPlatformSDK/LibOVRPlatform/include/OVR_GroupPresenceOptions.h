// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_GROUP_PRESENCE_OPTIONS_H
#define OVR_GROUP_PRESENCE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


struct ovrGroupPresenceOptions;
typedef struct ovrGroupPresenceOptions* ovrGroupPresenceOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrGroupPresenceOptionsHandle) ovr_GroupPresenceOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_Destroy(ovrGroupPresenceOptionsHandle handle);
/// Use ovr_GroupPresenceOptions_SetLobbySessionId or
/// ovr_GroupPresenceOptions_SetMatchSessionId to specify the session. Use the
/// deeplink message override for any additional data in whatever format you
/// wish to aid in bringing users together. If not specified, the
/// deeplink_message for the user will default to the one on the destination.
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_SetDeeplinkMessageOverride(ovrGroupPresenceOptionsHandle handle, const char * value);
/// This the unique API Name that refers to an in-app destination
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_SetDestinationApiName(ovrGroupPresenceOptionsHandle handle, const char * value);
/// Set whether or not the person is shown as joinable or not to others. A user
/// that is joinable can invite others to join them. Set this to false if other
/// users would not be able to join this user. For example: the current session
/// is full, or only the host can invite others and the current user is not the
/// host.
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_SetIsJoinable(ovrGroupPresenceOptionsHandle handle, bool value);
/// This is a session that represents a closer group/squad/party of users. It
/// is expected that all users with the same lobby session id can see or hear
/// each other. Users with the same lobby session id in their group presence
/// will show up in the roster and will show up as "Recently Played With" for
/// future invites if they aren't already Oculus friends. This must be set in
/// addition to is_joinable being true for a user to use invites.
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_SetLobbySessionId(ovrGroupPresenceOptionsHandle handle, const char * value);
/// This is a session that represents all the users that are playing a specific
/// instance of a map, game mode, round, etc. This can include users from
/// multiple different lobbies that joined together and the users may or may
/// not remain together after the match is over. Users with the same match
/// session id in their group presence will not show up in the Roster, but will
/// show up as "Recently Played with" for future invites.
OVRP_PUBLIC_FUNCTION(void) ovr_GroupPresenceOptions_SetMatchSessionId(ovrGroupPresenceOptionsHandle handle, const char * value);

#endif
