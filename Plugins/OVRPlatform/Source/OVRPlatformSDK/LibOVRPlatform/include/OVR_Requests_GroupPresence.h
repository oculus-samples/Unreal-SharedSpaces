// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_GROUPPRESENCE_H
#define OVR_REQUESTS_GROUPPRESENCE_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_ApplicationInviteArray.h"
#include "OVR_ApplicationInviteArray.h"
#include "OVR_GroupPresenceOptions.h"
#include "OVR_InviteOptions.h"
#include "OVR_MultiplayerErrorOptions.h"
#include "OVR_RosterOptions.h"

/// Clear group presence for running app
///
/// A message with type ::ovrMessage_GroupPresence_Clear will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_Clear();

/// Returns a list of users that can be invited to your current lobby. These
/// are pulled from your bidirectional followers and recently met lists.
///
/// A message with type ::ovrMessage_GroupPresence_GetInvitableUsers will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_GetInvitableUsers(ovrInviteOptionsHandle options);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_GroupPresence_GetNextApplicationInviteArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrApplicationInviteArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetApplicationInviteArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_GetNextApplicationInviteArrayPage(ovrApplicationInviteArrayHandle handle);

/// Get the application invites which have been sent by the user.
///
/// A message with type ::ovrMessage_GroupPresence_GetSentInvites will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrApplicationInviteArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetApplicationInviteArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_GetSentInvites();

/// Launch the flow to allow the user to invite others to their current
/// session. This can only be used if the user is in a joinable session.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchInvitePanel will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrInvitePanelResultInfoHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetInvitePanelResultInfo().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchInvitePanel(ovrInviteOptionsHandle options);

/// Launch an error dialog with predefined messages for common multiplayer
/// errors.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchMultiplayerErrorDialog will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchMultiplayerErrorDialog(ovrMultiplayerErrorOptionsHandle options);

/// Launch the dialog which will allow the user to rejoin a previous
/// lobby/match. Either the lobby_session_id or the match_session_id, or both,
/// must be populated.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchRejoinDialog will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrRejoinDialogResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetRejoinDialogResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchRejoinDialog(const char *lobby_session_id, const char *match_session_id, const char *destination_api_name);

/// Launch the panel which displays the current users in the roster. Users with
/// the same lobby and match session id as part of their presence will show up
/// here.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchRosterPanel will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchRosterPanel(ovrRosterOptionsHandle options);

/// Send application invites to the passed in userIDs.
///
/// A message with type ::ovrMessage_GroupPresence_SendInvites will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSendInvitesResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSendInvitesResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SendInvites(ovrID *userIDs, unsigned int userIDLength);

/// Set group presence for running app
///
/// A message with type ::ovrMessage_GroupPresence_Set will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_Set(ovrGroupPresenceOptionsHandle groupPresenceOptions);

/// Set the user's deeplink message while keeping the other group presence
/// parameters the same. If the destination of the user is not set, the
/// deeplink message cannot be set as there's no deeplink message to override.
///
/// A message with type ::ovrMessage_GroupPresence_SetDeeplinkMessageOverride will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetDeeplinkMessageOverride(const char *deeplink_message);

/// Replaces the user's current destination for the provided one. All other
/// existing group presence parameters will remain the same.
///
/// A message with type ::ovrMessage_GroupPresence_SetDestination will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetDestination(const char *api_name);

/// Set if the current user's destination and session is joinable while keeping
/// the other group presence parameters the same. If the destination or session
/// ids of the user is not set, they cannot be set to joinable.
///
/// A message with type ::ovrMessage_GroupPresence_SetIsJoinable will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetIsJoinable(bool is_joinable);

/// Replaces the user's current lobby session id for the provided one. All
/// other existing group presence parameters will remain the same.
///
/// A message with type ::ovrMessage_GroupPresence_SetLobbySession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetLobbySession(const char *id);

/// Replaces the user's current match session id for the provided one. All
/// other existing group presence parameters will remain the same.
///
/// A message with type ::ovrMessage_GroupPresence_SetMatchSession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetMatchSession(const char *id);

#endif
