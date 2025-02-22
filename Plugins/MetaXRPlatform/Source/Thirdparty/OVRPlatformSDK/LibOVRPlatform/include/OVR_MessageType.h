/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MESSAGETYPE_H
#define OVR_MESSAGETYPE_H

#include <stdbool.h>

#include "OVR_Platform_Defs.h"

/// \file 
/// It's an enum that represents the different types of ::ovrMessageHandle that can be exchanged. The enumeration contains several values, each representing a specific message type.
/// Some of these message types are used in responses to specific API functions called by the application, while others are notifications sent by the platform to the application.

typedef enum ovrMessageType_ {
  /// This value should never appear on the message queue. If it does,
  /// it indicates that something has gone horribly, horribly wrong.
  ovrMessage_Unknown,

  ovrMessage_AbuseReport_ReportRequestHandled                   = 0x4B8EFC86, ///< Generated in response to ovr_AbuseReport_ReportRequestHandled()
  ovrMessage_Achievements_AddCount                              = 0x03E76231, ///< Generated in response to ovr_Achievements_AddCount()
  ovrMessage_Achievements_AddFields                             = 0x14AA2129, ///< Generated in response to ovr_Achievements_AddFields()
  ovrMessage_Achievements_GetAllDefinitions                     = 0x03D3458D, ///< Generated in response to ovr_Achievements_GetAllDefinitions()
  ovrMessage_Achievements_GetAllProgress                        = 0x4F9FDE1D, ///< Generated in response to ovr_Achievements_GetAllProgress()
  ovrMessage_Achievements_GetDefinitionsByName                  = 0x629101BC, ///< Generated in response to ovr_Achievements_GetDefinitionsByName()
  ovrMessage_Achievements_GetNextAchievementDefinitionArrayPage = 0x2A7DD255, ///< Generated in response to ovr_Achievements_GetNextAchievementDefinitionArrayPage()
  ovrMessage_Achievements_GetNextAchievementProgressArrayPage   = 0x2F42E727, ///< Generated in response to ovr_Achievements_GetNextAchievementProgressArrayPage()
  ovrMessage_Achievements_GetProgressByName                     = 0x152663B1, ///< Generated in response to ovr_Achievements_GetProgressByName()
  ovrMessage_Achievements_Unlock                                = 0x593CCBDD, ///< Generated in response to ovr_Achievements_Unlock()
  ovrMessage_ApplicationLifecycle_GetRegisteredPIDs             = 0x04E5CF62, ///< Generated in response to ovr_ApplicationLifecycle_GetRegisteredPIDs()
  ovrMessage_ApplicationLifecycle_GetSessionKey                 = 0x3AAF591D, ///< Generated in response to ovr_ApplicationLifecycle_GetSessionKey()
  ovrMessage_ApplicationLifecycle_RegisterSessionKey            = 0x4DB6AFF8, ///< Generated in response to ovr_ApplicationLifecycle_RegisterSessionKey()
  ovrMessage_Application_CancelAppDownload                      = 0x7C2060DE, ///< Generated in response to ovr_Application_CancelAppDownload()
  ovrMessage_Application_CheckAppDownloadProgress               = 0x5534A924, ///< Generated in response to ovr_Application_CheckAppDownloadProgress()
  ovrMessage_Application_GetVersion                             = 0x68670A0E, ///< Generated in response to ovr_Application_GetVersion()
  ovrMessage_Application_InstallAppUpdateAndRelaunch            = 0x14806B85, ///< Generated in response to ovr_Application_InstallAppUpdateAndRelaunch()
  ovrMessage_Application_LaunchOtherApp                         = 0x54E2D1F8, ///< Generated in response to ovr_Application_LaunchOtherApp()
  ovrMessage_Application_StartAppDownload                       = 0x44FC006E, ///< Generated in response to ovr_Application_StartAppDownload()
  ovrMessage_AssetFile_Delete                                   = 0x6D5D7886, ///< Generated in response to ovr_AssetFile_Delete()
  ovrMessage_AssetFile_DeleteById                               = 0x5AE8CD52, ///< Generated in response to ovr_AssetFile_DeleteById()
  ovrMessage_AssetFile_DeleteByName                             = 0x420AC1CF, ///< Generated in response to ovr_AssetFile_DeleteByName()
  ovrMessage_AssetFile_Download                                 = 0x11449FC5, ///< Generated in response to ovr_AssetFile_Download()
  ovrMessage_AssetFile_DownloadById                             = 0x2D008992, ///< Generated in response to ovr_AssetFile_DownloadById()
  ovrMessage_AssetFile_DownloadByName                           = 0x6336CEFA, ///< Generated in response to ovr_AssetFile_DownloadByName()
  ovrMessage_AssetFile_DownloadCancel                           = 0x080AD3C7, ///< Generated in response to ovr_AssetFile_DownloadCancel()
  ovrMessage_AssetFile_DownloadCancelById                       = 0x51659514, ///< Generated in response to ovr_AssetFile_DownloadCancelById()
  ovrMessage_AssetFile_DownloadCancelByName                     = 0x446AECFA, ///< Generated in response to ovr_AssetFile_DownloadCancelByName()
  ovrMessage_AssetFile_GetList                                  = 0x4AFC6F74, ///< Generated in response to ovr_AssetFile_GetList()
  ovrMessage_AssetFile_Status                                   = 0x02D32F60, ///< Generated in response to ovr_AssetFile_Status()
  ovrMessage_AssetFile_StatusById                               = 0x5D955D38, ///< Generated in response to ovr_AssetFile_StatusById()
  ovrMessage_AssetFile_StatusByName                             = 0x41CFDA50, ///< Generated in response to ovr_AssetFile_StatusByName()
  ovrMessage_Avatar_LaunchAvatarEditor                          = 0x05F1E153, ///< Generated in response to ovr_Avatar_LaunchAvatarEditor()
  ovrMessage_Challenges_Create                                  = 0x6859D641, ///< Generated in response to ovr_Challenges_Create()
  ovrMessage_Challenges_DeclineInvite                           = 0x568E76C0, ///< Generated in response to ovr_Challenges_DeclineInvite()
  ovrMessage_Challenges_Delete                                  = 0x264885CA, ///< Generated in response to ovr_Challenges_Delete()
  ovrMessage_Challenges_Get                                     = 0x77584EF3, ///< Generated in response to ovr_Challenges_Get()
  ovrMessage_Challenges_GetEntries                              = 0x121AB45F, ///< Generated in response to ovr_Challenges_GetEntries()
  ovrMessage_Challenges_GetEntriesAfterRank                     = 0x08891A7F, ///< Generated in response to ovr_Challenges_GetEntriesAfterRank()
  ovrMessage_Challenges_GetEntriesByIds                         = 0x316509DC, ///< Generated in response to ovr_Challenges_GetEntriesByIds()
  ovrMessage_Challenges_GetList                                 = 0x43264356, ///< Generated in response to ovr_Challenges_GetList()
  ovrMessage_Challenges_GetNextChallenges                       = 0x5B7CA1B6, ///< Generated in response to ovr_Challenges_GetNextChallenges()
  ovrMessage_Challenges_GetNextEntries                          = 0x7F4CA0C6, ///< Generated in response to ovr_Challenges_GetNextEntries()
  ovrMessage_Challenges_GetPreviousChallenges                   = 0x0EB4040D, ///< Generated in response to ovr_Challenges_GetPreviousChallenges()
  ovrMessage_Challenges_GetPreviousEntries                      = 0x78C90470, ///< Generated in response to ovr_Challenges_GetPreviousEntries()
  ovrMessage_Challenges_Join                                    = 0x21248069, ///< Generated in response to ovr_Challenges_Join()
  ovrMessage_Challenges_Leave                                   = 0x296116E5, ///< Generated in response to ovr_Challenges_Leave()
  ovrMessage_Challenges_UpdateInfo                              = 0x1175BE60, ///< Generated in response to ovr_Challenges_UpdateInfo()
  ovrMessage_Cowatching_GetNextCowatchViewerArrayPage           = 0x1D403932, ///< Generated in response to ovr_Cowatching_GetNextCowatchViewerArrayPage()
  ovrMessage_Cowatching_GetPresenterData                        = 0x49864735, ///< Generated in response to ovr_Cowatching_GetPresenterData()
  ovrMessage_Cowatching_GetViewersData                          = 0x5CD7A24F, ///< Generated in response to ovr_Cowatching_GetViewersData()
  ovrMessage_Cowatching_IsInSession                             = 0x651B4884, ///< Generated in response to ovr_Cowatching_IsInSession()
  ovrMessage_Cowatching_JoinSession                             = 0x6388A554, ///< Generated in response to ovr_Cowatching_JoinSession()
  ovrMessage_Cowatching_LaunchInviteDialog                      = 0x22933297, ///< Generated in response to ovr_Cowatching_LaunchInviteDialog()
  ovrMessage_Cowatching_LeaveSession                            = 0x3C9E46CD, ///< Generated in response to ovr_Cowatching_LeaveSession()
  ovrMessage_Cowatching_RequestToPresent                        = 0x7F79BCAA, ///< Generated in response to ovr_Cowatching_RequestToPresent()
  ovrMessage_Cowatching_ResignFromPresenting                    = 0x4B49C202, ///< Generated in response to ovr_Cowatching_ResignFromPresenting()
  ovrMessage_Cowatching_SetPresenterData                        = 0x6D1C8906, ///< Generated in response to ovr_Cowatching_SetPresenterData()
  ovrMessage_Cowatching_SetViewerData                           = 0x3CDBE826, ///< Generated in response to ovr_Cowatching_SetViewerData()
  ovrMessage_DeviceApplicationIntegrity_GetIntegrityToken       = 0x3271ABDA, ///< Generated in response to ovr_DeviceApplicationIntegrity_GetIntegrityToken()
  ovrMessage_Entitlement_GetIsViewerEntitled                    = 0x186B58B1, ///< Generated in response to ovr_Entitlement_GetIsViewerEntitled()
  ovrMessage_GroupPresence_Clear                                = 0x6DAA9CC3, ///< Generated in response to ovr_GroupPresence_Clear()
  ovrMessage_GroupPresence_GetInvitableUsers                    = 0x234BC3F1, ///< Generated in response to ovr_GroupPresence_GetInvitableUsers()
  ovrMessage_GroupPresence_GetNextApplicationInviteArrayPage    = 0x04F8C0F2, ///< Generated in response to ovr_GroupPresence_GetNextApplicationInviteArrayPage()
  ovrMessage_GroupPresence_GetSentInvites                       = 0x08260AB1, ///< Generated in response to ovr_GroupPresence_GetSentInvites()
  ovrMessage_GroupPresence_LaunchInvitePanel                    = 0x0F9ECF9F, ///< Generated in response to ovr_GroupPresence_LaunchInvitePanel()
  ovrMessage_GroupPresence_LaunchMultiplayerErrorDialog         = 0x2955AF24, ///< Generated in response to ovr_GroupPresence_LaunchMultiplayerErrorDialog()
  ovrMessage_GroupPresence_LaunchRejoinDialog                   = 0x1577036F, ///< Generated in response to ovr_GroupPresence_LaunchRejoinDialog()
  ovrMessage_GroupPresence_LaunchRosterPanel                    = 0x35728882, ///< Generated in response to ovr_GroupPresence_LaunchRosterPanel()
  ovrMessage_GroupPresence_SendInvites                          = 0x0DCBD364, ///< Generated in response to ovr_GroupPresence_SendInvites()
  ovrMessage_GroupPresence_Set                                  = 0x675F5C24, ///< Generated in response to ovr_GroupPresence_Set()
  ovrMessage_GroupPresence_SetDeeplinkMessageOverride           = 0x521ADF0D, ///< Generated in response to ovr_GroupPresence_SetDeeplinkMessageOverride()
  ovrMessage_GroupPresence_SetDestination                       = 0x4C5B268A, ///< Generated in response to ovr_GroupPresence_SetDestination()
  ovrMessage_GroupPresence_SetIsJoinable                        = 0x2A8F1055, ///< Generated in response to ovr_GroupPresence_SetIsJoinable()
  ovrMessage_GroupPresence_SetLobbySession                      = 0x48FF55BE, ///< Generated in response to ovr_GroupPresence_SetLobbySession()
  ovrMessage_GroupPresence_SetMatchSession                      = 0x314C84B8, ///< Generated in response to ovr_GroupPresence_SetMatchSession()
  ovrMessage_IAP_ConsumePurchase                                = 0x1FBB72D9, ///< Generated in response to ovr_IAP_ConsumePurchase()
  ovrMessage_IAP_GetNextProductArrayPage                        = 0x1BD94AAF, ///< Generated in response to ovr_IAP_GetNextProductArrayPage()
  ovrMessage_IAP_GetNextPurchaseArrayPage                       = 0x47570A95, ///< Generated in response to ovr_IAP_GetNextPurchaseArrayPage()
  ovrMessage_IAP_GetProductsBySKU                               = 0x7E9ACAF5, ///< Generated in response to ovr_IAP_GetProductsBySKU()
  ovrMessage_IAP_GetViewerPurchases                             = 0x3A0F8419, ///< Generated in response to ovr_IAP_GetViewerPurchases()
  ovrMessage_IAP_GetViewerPurchasesDurableCache                 = 0x63599E2B, ///< Generated in response to ovr_IAP_GetViewerPurchasesDurableCache()
  ovrMessage_IAP_LaunchCheckoutFlow                             = 0x3F9B0D0D, ///< Generated in response to ovr_IAP_LaunchCheckoutFlow()
  ovrMessage_LanguagePack_GetCurrent                            = 0x1F90F0D5, ///< Generated in response to ovr_LanguagePack_GetCurrent()
  ovrMessage_LanguagePack_SetCurrent                            = 0x5B4FBBE0, ///< Generated in response to ovr_LanguagePack_SetCurrent()
  ovrMessage_Leaderboard_Get                                    = 0x6AD44EF8, ///< Generated in response to ovr_Leaderboard_Get()
  ovrMessage_Leaderboard_GetEntries                             = 0x5DB3474C, ///< Generated in response to ovr_Leaderboard_GetEntries()
  ovrMessage_Leaderboard_GetEntriesAfterRank                    = 0x18378BEF, ///< Generated in response to ovr_Leaderboard_GetEntriesAfterRank()
  ovrMessage_Leaderboard_GetEntriesByIds                        = 0x39607BFC, ///< Generated in response to ovr_Leaderboard_GetEntriesByIds()
  ovrMessage_Leaderboard_GetNextEntries                         = 0x4E207CD9, ///< Generated in response to ovr_Leaderboard_GetNextEntries()
  ovrMessage_Leaderboard_GetNextLeaderboardArrayPage            = 0x35F6769B, ///< Generated in response to ovr_Leaderboard_GetNextLeaderboardArrayPage()
  ovrMessage_Leaderboard_GetPreviousEntries                     = 0x4901DAC0, ///< Generated in response to ovr_Leaderboard_GetPreviousEntries()
  ovrMessage_Leaderboard_WriteEntry                             = 0x117FC8FE, ///< Generated in response to ovr_Leaderboard_WriteEntry()
  ovrMessage_Leaderboard_WriteEntryWithSupplementaryMetric      = 0x72C692FA, ///< Generated in response to ovr_Leaderboard_WriteEntryWithSupplementaryMetric()
  ovrMessage_Media_ShareToFacebook                              = 0x00E38AEF, ///< Generated in response to ovr_Media_ShareToFacebook()
  ovrMessage_Notification_MarkAsRead                            = 0x717259E3, ///< Generated in response to ovr_Notification_MarkAsRead()
  ovrMessage_Party_GetCurrent                                   = 0x47933760, ///< Generated in response to ovr_Party_GetCurrent()
  ovrMessage_RichPresence_Clear                                 = 0x57B752B3, ///< Generated in response to ovr_RichPresence_Clear()
  ovrMessage_RichPresence_GetDestinations                       = 0x586F2D14, ///< Generated in response to ovr_RichPresence_GetDestinations()
  ovrMessage_RichPresence_GetNextDestinationArrayPage           = 0x67367F45, ///< Generated in response to ovr_RichPresence_GetNextDestinationArrayPage()
  ovrMessage_RichPresence_Set                                   = 0x3C147509, ///< Generated in response to ovr_RichPresence_Set()
  ovrMessage_UserAgeCategory_Get                                = 0x21CBE0C0, ///< Generated in response to ovr_UserAgeCategory_Get()
  ovrMessage_UserAgeCategory_Report                             = 0x2E4DD8D6, ///< Generated in response to ovr_UserAgeCategory_Report()
  ovrMessage_User_Get                                           = 0x6BCF9E47, ///< Generated in response to ovr_User_Get()
  ovrMessage_User_GetAccessToken                                = 0x06A85ABE, ///< Generated in response to ovr_User_GetAccessToken()
  ovrMessage_User_GetBlockedUsers                               = 0x7D201556, ///< Generated in response to ovr_User_GetBlockedUsers()
  ovrMessage_User_GetLoggedInUser                               = 0x436F345D, ///< Generated in response to ovr_User_GetLoggedInUser()
  ovrMessage_User_GetLoggedInUserFriends                        = 0x587C2A8D, ///< Generated in response to ovr_User_GetLoggedInUserFriends()
  ovrMessage_User_GetLoggedInUserManagedInfo                    = 0x70BA3AEE, ///< Generated in response to ovr_User_GetLoggedInUserManagedInfo()
  ovrMessage_User_GetNextBlockedUserArrayPage                   = 0x7C2AFDCB, ///< Generated in response to ovr_User_GetNextBlockedUserArrayPage()
  ovrMessage_User_GetNextUserArrayPage                          = 0x267CF743, ///< Generated in response to ovr_User_GetNextUserArrayPage()
  ovrMessage_User_GetNextUserCapabilityArrayPage                = 0x2309F399, ///< Generated in response to ovr_User_GetNextUserCapabilityArrayPage()
  ovrMessage_User_GetOrgScopedID                                = 0x18F0B01B, ///< Generated in response to ovr_User_GetOrgScopedID()
  ovrMessage_User_GetSdkAccounts                                = 0x67526A83, ///< Generated in response to ovr_User_GetSdkAccounts()
  ovrMessage_User_GetUserProof                                  = 0x22810483, ///< Generated in response to ovr_User_GetUserProof()
  ovrMessage_User_LaunchBlockFlow                               = 0x6FD62528, ///< Generated in response to ovr_User_LaunchBlockFlow()
  ovrMessage_User_LaunchFriendRequestFlow                       = 0x0904B598, ///< Generated in response to ovr_User_LaunchFriendRequestFlow()
  ovrMessage_User_LaunchUnblockFlow                             = 0x14A22A97, ///< Generated in response to ovr_User_LaunchUnblockFlow()
  ovrMessage_Voip_GetMicrophoneAvailability                     = 0x744CE345, ///< Generated in response to ovr_Voip_GetMicrophoneAvailability()
  ovrMessage_Voip_SetSystemVoipSuppressed                       = 0x453FC9AA, ///< Generated in response to ovr_Voip_SetSystemVoipSuppressed()

  /// The user has tapped the report button in the panel that appears after
  /// pressing the Oculus button.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_AbuseReport_ReportButtonPressed = 0x24472F6C,

  /// This event is triggered when a launch intent is received, whether it's a
  /// cold or warm start. The payload contains the type of intent that was
  /// received. To obtain additional details, you should call the
  /// ovr_ApplicationLifecycle_GetLaunchDetails() function.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged = 0x04B34CA3,

  /// Sent to indicate download progress for asset files.
  ///
  /// The message will contain a payload of type ::ovrAssetFileDownloadUpdateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetAssetFileDownloadUpdate().
  ovrMessage_Notification_AssetFile_DownloadUpdate = 0x2FDD0CCD,

  /// Sets a callback function that will be triggered when the user is no longer
  /// in a copresent state and cowatching actions should not be performed.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_ApiNotReady = 0x66093981,

  /// Sets a callback function that will be triggered when the user is in a
  /// copresent state and cowatching is ready to begin.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_ApiReady = 0x09956693,

  /// Sets a callback function that will be triggered when the current user
  /// joins/leaves the cowatching session.
  ///
  /// The message will contain a payload of type ::ovrCowatchingStateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetCowatchingState().
  ovrMessage_Notification_Cowatching_InSessionChanged = 0x0DF93113,

  /// Sets a callback function that will be triggered when the cowatching API has
  /// been initialized. At this stage, the API is not yet ready for use.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_Initialized = 0x74D948F3,

  /// Sets a callback function that will be triggered when the presenter updates
  /// the presenter data.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_PresenterDataChanged = 0x4E078EEE,

  /// Sets a callback function that will be triggered when a user has started a
  /// cowatching session, and the ID of the session is reflected in the payload.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_SessionStarted = 0x7321939C,

  /// Sets a callback function that will be triggered when a cowatching session
  /// has ended.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Cowatching_SessionStopped = 0x49E6DBFA,

  /// Sets a callback function that will be triggered when a user joins or
  /// updates their viewer data.
  ///
  /// The message will contain a payload of type ::ovrCowatchViewerUpdateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetCowatchViewerUpdate().
  ovrMessage_Notification_Cowatching_ViewersDataChanged = 0x68F2F1FF,

  /// Sent when the user is finished using the invite panel to send out
  /// invitations. Contains a list of invitees. Parameter: Callback is a function
  /// that will be called when the invitation sent status changes.
  /// ::ovrLaunchInvitePanelFlowResultHandle has 1 member: UserList
  /// ovr_LaunchInvitePanelFlowResult_GetInvitedUsers() - A list of users that
  /// were sent an invitation to the session.
  ///
  /// The message will contain a payload of type ::ovrLaunchInvitePanelFlowResultHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetLaunchInvitePanelFlowResult().
  ovrMessage_Notification_GroupPresence_InvitationsSent = 0x679A84B6,

  /// Sent when a user has chosen to join the destination/lobby/match. Read all
  /// the fields to figure out where the user wants to go and take the
  /// appropriate actions to bring them there. If the user is unable to go there,
  /// provide adequate messaging to the user on why they cannot go there. These
  /// notifications should be responded to immediately. Parameter: Callback is a
  /// function that will be called when a user has chosen to join the
  /// destination/lobby/match. ::ovrGroupPresenceJoinIntentHandle has 4 members:
  /// string ovr_GroupPresenceJoinIntent_GetDeeplinkMessage() - An opaque string
  /// provided by the developer to help them deeplink to content. string
  /// ovr_GroupPresenceJoinIntent_GetDestinationApiName() - The destination the
  /// current user wants to go to. string
  /// ovr_GroupPresenceJoinIntent_GetLobbySessionId() - The lobby session the
  /// current user wants to go to. string
  /// ovr_GroupPresenceJoinIntent_GetMatchSessionId() - The match session the
  /// current user wants to go to.
  ///
  /// The message will contain a payload of type ::ovrGroupPresenceJoinIntentHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetGroupPresenceJoinIntent().
  ovrMessage_Notification_GroupPresence_JoinIntentReceived = 0x773889F6,

  /// Sent when the user has chosen to leave the destination/lobby/match from the
  /// Oculus menu. Read the specific fields to check the user is currently from
  /// the destination/lobby/match and take the appropriate actions to remove
  /// them. Update the user's presence clearing the appropriate fields to
  /// indicate the user has left. Parameter: Callback is a function that will be
  /// called when the user has chosen to leave the destination/lobby/match.
  /// ::ovrGroupPresenceLeaveIntentHandle has 3 members: string
  /// ovr_GroupPresenceLeaveIntent_GetDestinationApiName() - The destination the
  /// current user wants to leave. string
  /// ovr_GroupPresenceLeaveIntent_GetLobbySessionId() - The lobby session the
  /// current user wants to leave. string
  /// ovr_GroupPresenceLeaveIntent_GetMatchSessionId() - The match session the
  /// current user wants to leave.
  ///
  /// The message will contain a payload of type ::ovrGroupPresenceLeaveIntentHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetGroupPresenceLeaveIntent().
  ovrMessage_Notification_GroupPresence_LeaveIntentReceived = 0x4737EA1D,

  /// Sent to indicate that more data has been read or an error occured.
  ///
  /// The message will contain a payload of type ::ovrHttpTransferUpdateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetHttpTransferUpdate().
  ovrMessage_Notification_HTTP_Transfer = 0x7DD46E2F,

  /// Indicates that the livestreaming session has been updated. You can use this
  /// information to throttle your game performance or increase CPU/GPU
  /// performance. Use ::ovrLivestreamingStatusHandle to extract the updated
  /// livestreaming status.
  ///
  /// The message will contain a payload of type ::ovrLivestreamingStatusHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetLivestreamingStatus().
  ovrMessage_Notification_Livestreaming_StatusChange = 0x2247596E,

  /// Sent when the status of a connection has changed. The payload will be a
  /// type of ::ovrNetSyncConnectionHandle.
  ///
  /// The message will contain a payload of type ::ovrNetSyncConnectionHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetSyncConnection().
  ovrMessage_Notification_NetSync_ConnectionStatusChanged = 0x073484CA,

  /// Sent when the list of known connected sessions has changed. Contains the
  /// new list of sessions. The payload will be a type of
  /// ::ovrNetSyncSessionsChangedNotificationHandle.
  ///
  /// The message will contain a payload of type ::ovrNetSyncSessionsChangedNotificationHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetSyncSessionsChangedNotification().
  ovrMessage_Notification_NetSync_SessionsChanged = 0x387E7F36,

  /// Indicates that party has been updated. This will return a
  /// ::ovrPartyUpdateNotificationHandle object.
  ///
  /// The message will contain a payload of type ::ovrPartyUpdateNotificationHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetPartyUpdateNotification().
  ovrMessage_Notification_Party_PartyUpdate = 0x1D118AB2,

  /// Indicates that the current microphone availability state has been updated.
  /// Use ovr_Voip_GetMicrophoneAvailability() to extract the microphone
  /// availability state.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate = 0x3E20CB57,

  /// Sent to indicate that some part of the overall state of SystemVoip has
  /// changed. Use ovr_SystemVoipState_GetStatus() and the properties of
  /// ::ovrSystemVoipStateHandle to extract the state that triggered the
  /// notification. Note that the state may have changed further since the
  /// notification was generated, and that you may call the `GetSystemVoip...()`
  /// family of functions at any time to get the current state directly.
  ///
  /// The message will contain a payload of type ::ovrSystemVoipStateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetSystemVoipState().
  ovrMessage_Notification_Voip_SystemVoipState = 0x58D254A5,

  /// Gets VR camera related WebRTC data channel messages for update. This method
  /// is used to retrieve messages that are sent over the WebRTC data channel,
  /// which can include information about the VR camera system, such as its
  /// current state or any errors that may have occurred.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Vrcamera_GetDataChannelMessageUpdate = 0x6EE4F33C,

  /// Gets the surface and update action from the platform WebRTC for update.
  /// This method is used to retrieve information about the current state of the
  /// VR camera system, including any updates that may be required. See more info
  /// about Platform Solutions
  /// [here](https://developer.oculus.com/documentation/native/ps-platform-
  /// intro/).
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Vrcamera_GetSurfaceUpdate = 0x37F21084,

  ovrMessage_PlatformInitializeWithAccessToken = 0x35692F2B,
  ovrMessage_Platform_InitializeStandaloneOculus = 0x51F8CE0C,
  ovrMessage_PlatformInitializeAndroidAsynchronous = 0x1AD307B4,
  ovrMessage_PlatformInitializeWindowsAsynchronous = 0x6DA7BA8F,
} ovrMessageType;

/// This function can be used to converts an ::ovrMessageType value to a human readable string.
OVRPL_PUBLIC_FUNCTION(const char*) ovrMessageType_ToString(ovrMessageType value);

/// It can be used to determine whether a given ::ovrMessageType value represents a notification or not. 
OVRPL_PUBLIC_FUNCTION(bool) ovrMessageType_IsNotification(ovrMessageType value);

#endif
