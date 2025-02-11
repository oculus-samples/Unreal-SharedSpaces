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

/// Clears the current group presence settings for your app. Use this when a
/// user’s group presence setting in your app needs to be changed when moving
/// to new destinations in your app.
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

/// Launches the system invite dialog with a roster of eligible users for the
/// current user to invite to the app. It is recommended that you surface a
/// button in your UI that triggers this dialog when a user is joinable.
/// \param options It contains two methods. 1. Add ovr_InviteOptions_SetSuggestedUsers - Takes the userID as a parameter and adds it to the inevitable users list. 2. Clear ovr_InviteOptions_SetSuggestedUsers - Clears the inevitable users list.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchInvitePanel will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrInvitePanelResultInfoHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetInvitePanelResultInfo().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchInvitePanel(ovrInviteOptionsHandle options);

/// Launch an error dialog window with predefined messages for commonly
/// occurring multiplayer errors. Check the Invokable Error Dialogs
/// documentation for more information about these error messages and their
/// values.
/// \param options It contains a ovr_MultiplayerErrorOptions_SetErrorKey associated with the predefined error message to be shown to users.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchMultiplayerErrorDialog will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchMultiplayerErrorDialog(ovrMultiplayerErrorOptionsHandle options);

/// Launch the dialog allowing users to rejoin a previous lobby or match.
/// Either the user’s ovr_GroupPresenceOptions_SetLobbySessionId, their
/// ovr_GroupPresenceOptions_SetMatchSessionId, or both must be populated as
/// valid rejoinable destinations. Check the Rejoin documentation for use cases
/// and information on this feature.
/// \param lobby_session_id The unique identifier of the lobby session to rejoin.
/// \param match_session_id The unique identifier of the match session to rejoin.
/// \param destination_api_name The unique name of the in-app destination to rejoin.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchRejoinDialog will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrRejoinDialogResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetRejoinDialogResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchRejoinDialog(const char *lobby_session_id, const char *match_session_id, const char *destination_api_name);

/// Launch the panel displaying the current users in the roster. We do not
/// recommend using this API because the list current users is surfaced in the
/// Destination UI when the Meta Quest button is pressed.
/// \param options It contains 2 methods. 1. Add ovr_RosterOptions_SetSuggestedUsers - it takes userID as a parameter and adds it to the inevitable users list. 2.Clear ovr_RosterOptions_SetSuggestedUsers - it clears the inevitable users list.
///
/// A message with type ::ovrMessage_GroupPresence_LaunchRosterPanel will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_LaunchRosterPanel(ovrRosterOptionsHandle options);

/// Sends invites to the current application to the list of userIDs passed in.
/// You can fetch a list of users to pass in via the
/// ovr_GroupPresence_GetInvitableUsers(). This API works as an alternative to
/// ovr_GroupPresence_LaunchInvitePanel() which delegates the invite flow to
/// the system invite module. ovr_GroupPresence_LaunchInvitePanel() is the
/// recommended approach.
/// \param userIDs userIDs is a list of users’ ids to send invites to.
/// \param userIDLength The number of user IDs provided.
///
/// A message with type ::ovrMessage_GroupPresence_SendInvites will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSendInvitesResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSendInvitesResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SendInvites(ovrID *userIDs, unsigned int userIDLength);

/// Sets group presence information for your current app. It is recommended
/// that you use this parameter and its methods to set group presence
/// information for your app. An example of using this parameter can be found
/// on the Group Presence overview page where the methods to set
/// ovr_GroupPresenceOptions_SetDestinationApiName,
/// ovr_GroupPresenceOptions_SetMatchSessionId, and
/// ovr_GroupPresenceOptions_SetLobbySessionId are used.
/// \param groupPresenceOptions The groupPresenceOptions parameter contains five methods. 1. ovr_GroupPresenceOptions_SetDeeplinkMessageOverride - Use ovr_GroupPresenceOptions_SetLobbySessionId or ovr_GroupPresenceOptions_SetMatchSessionId to specify the session. Use the ovr_GroupPresenceOptions_SetDeeplinkMessageOverride for any additional data in whatever format you wish to aid in bringing users together. If not specified, the deeplink_message for the user will default to the one on the destination. 2.ovr_GroupPresenceOptions_SetDestinationApiName - This the unique API Name that refers to an in-app destination. 3.ovr_GroupPresenceOptions_SetIsJoinable - Set whether or not the person is shown as joinable or not to others. A user that is joinable can invite others to join them. Set this to false if other users would not be able to join this user. For example, the current session is full, or only the host can invite others and the current user is not the host. 4.ovr_GroupPresenceOptions_SetLobbySessionId - This is a session that represents a closer group/squad/party of users. It is expected that all users with the same lobby session id can see or hear each other. Users with the same lobby session id in their group presence will show up in the roster and will show up as "Recently Played With" for future invites if they aren't already Oculus friends. This must be set in addition to ovr_GroupPresenceOptions_SetIsJoinable being true for a user to use invites. 5.ovr_GroupPresenceOptions_SetMatchSessionId - This is a session that represents all the users that are playing a specific instance of a map, game mode, round, etc. This can include users from multiple different lobbies that joined together and the users may or may not remain together after the match is over. Users with the same match session id in their group presence will not show up in the Roster, but will show up as "Recently Played with" for future invites.
///
/// A message with type ::ovrMessage_GroupPresence_Set will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_Set(ovrGroupPresenceOptionsHandle groupPresenceOptions);

/// Sets the user's ovr_GroupPresenceOptions_SetDeeplinkMessageOverride while
/// keeping the other group presence parameters the same. If the destination of
/// the user is not set, the deeplink message cannot be set as there's no
/// deeplink message to override. This method does not power travel from the
/// Meta Quest platform to your app. You must set a user’s
/// ovr_GroupPresenceOptions_SetDestinationApiName,
/// ovr_GroupPresenceOptions_SetIsJoinable status, and
/// ovr_GroupPresenceOptions_SetLobbySessionId to enable travel to your app.
/// Check Group Presence overview for more information about these values.
/// Note: Instead of using this standalone API, we recommend setting all
/// GroupPresence parameters in one call to ovr_GroupPresence_Set().
/// \param deeplink_message deeplink_message is the new ovr_GroupPresenceOptions_SetDeeplinkMessageOverride to set for the user, overriding the current deeplink message.
///
/// A message with type ::ovrMessage_GroupPresence_SetDeeplinkMessageOverride will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetDeeplinkMessageOverride(const char *deeplink_message);

/// Replaces the user's current ovr_GroupPresenceOptions_SetDestinationApiName
/// with the provided one. Use this to set a user's current destination while
/// keeping all the other Group Presence parameters the same. Setting a user's
/// destination is required to enable travel from the Meta Quest Platform to
/// your app. NOTE instead of using the standalone API, we recommend setting
/// all GroupPresence parameters in one call to ovr_GroupPresence_Set(). This
/// helps ensure that all relevant presence information is singularly updated
/// and helps reduce presence errors.
/// \param api_name api_name is the unique name of the in-app desination to set, replacing the user's current ovr_GroupPresenceOptions_SetDestinationApiName.
///
/// A message with type ::ovrMessage_GroupPresence_SetDestination will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetDestination(const char *api_name);

/// Sets a user’s current presence as joinable. Use this method to update a
/// user’s joinability as it changes. For example, when the game starts, the
/// lobby becomes full, the user moves to a private, non joinable instance
/// while keeping all other GroupPresence parameters (i.e
/// ovr_GroupPresenceOptions_SetDestinationApiName,
/// ovr_GroupPresenceOptions_SetLobbySessionId,
/// ovr_GroupPresenceOptions_SetMatchSessionId) the same. Setting a user’s
/// destination is required to enable travel from the Meta Quest Platform to
/// your app. Note: Instead of using this individual API, we recommend setting
/// all GroupPresence information with the ovr_GroupPresence_Set() method and
/// its associated parameters to simply managing all presence information. This
/// helps ensure that all relevant presence information is singularly updated
/// and helps reduce presence errors.
/// \param is_joinable If ovr_GroupPresenceOptions_SetIsJoinable is true, the user can invite others to join them. If false, other users cannot join this user, for example, if the current session is full or only the host can invite others and the current user is not the host.
///
/// A message with type ::ovrMessage_GroupPresence_SetIsJoinable will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetIsJoinable(bool is_joinable);

/// Replaces the user's current ovr_GroupPresenceOptions_SetLobbySessionId for
/// the provided string. Use this to set a user's current lobby session id
/// while keeping all other GroupPresence parameters the same. Setting a user's
/// lobby session id is required to enable travel from the Meta Quest Platform
/// to your app. Check Group presence overview for more information. NOTE
/// instead of using the standalone API, we recommend setting all GroupPresence
/// parameters in one call to ovr_GroupPresence_Set(). This helps ensure that
/// all relevant presence information is singularly updated and helps reduce
/// presence errors.
/// \param id id is the unique identifier of the lobby session to set, replacing the user's current ovr_GroupPresenceOptions_SetLobbySessionId.
///
/// A message with type ::ovrMessage_GroupPresence_SetLobbySession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetLobbySession(const char *id);

/// Replaces the user's current ovr_GroupPresenceOptions_SetMatchSessionId for
/// the provided one. Use this to update the user's current match session id
/// while keeping all other GroupPresence parameters the same.
/// ovr_GroupPresenceOptions_SetMatchSessionId works in conjuction with
/// ovr_GroupPresenceOptions_SetLobbySessionId to determine if users are
/// playing together. If a user's match and lobby session ids are the same,
/// they should be in the same multiplayer instance together. Users with the
/// same lobby session id but different match session ids may be in the same
/// lobby for things like voice chat while in different instances in your app.
/// WARNING match session id is often treated the same as lobby session id, but
/// this is in fact a distinct parameter and is not used for travel from the
/// Meta Quest Platform. NOTE instead of using the standalone API, we recommend
/// setting all GroupPresence parameters in one call to
/// ovr_GroupPresence_Set().
/// \param id id is the unique identifier of the match session to set, replacing the user's current ovr_GroupPresenceOptions_SetMatchSessionId.
///
/// A message with type ::ovrMessage_GroupPresence_SetMatchSession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_GroupPresence_SetMatchSession(const char *id);

#endif
