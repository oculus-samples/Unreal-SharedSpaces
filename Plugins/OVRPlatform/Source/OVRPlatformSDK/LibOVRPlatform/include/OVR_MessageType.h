// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MESSAGETYPE_H
#define OVR_MESSAGETYPE_H

#include <stdbool.h>

#include "OVR_Platform_Defs.h"

typedef enum ovrMessageType_ {
  /// This value should never appear on the message queue. If it does,
  /// it indicates that something has gone horribly, horribly wrong.
  ovrMessage_Unknown,

  ovrMessage_AbuseReport_ReportRequestHandled                    = 0x4B8EFC86, ///< Generated in response to ovr_AbuseReport_ReportRequestHandled()
  ovrMessage_Achievements_AddCount                               = 0x03E76231, ///< Generated in response to ovr_Achievements_AddCount()
  ovrMessage_Achievements_AddFields                              = 0x14AA2129, ///< Generated in response to ovr_Achievements_AddFields()
  ovrMessage_Achievements_GetAllDefinitions                      = 0x03D3458D, ///< Generated in response to ovr_Achievements_GetAllDefinitions()
  ovrMessage_Achievements_GetAllProgress                         = 0x4F9FDE1D, ///< Generated in response to ovr_Achievements_GetAllProgress()
  ovrMessage_Achievements_GetDefinitionsByName                   = 0x629101BC, ///< Generated in response to ovr_Achievements_GetDefinitionsByName()
  ovrMessage_Achievements_GetNextAchievementDefinitionArrayPage  = 0x2A7DD255, ///< Generated in response to ovr_Achievements_GetNextAchievementDefinitionArrayPage()
  ovrMessage_Achievements_GetNextAchievementProgressArrayPage    = 0x2F42E727, ///< Generated in response to ovr_Achievements_GetNextAchievementProgressArrayPage()
  ovrMessage_Achievements_GetProgressByName                      = 0x152663B1, ///< Generated in response to ovr_Achievements_GetProgressByName()
  ovrMessage_Achievements_Unlock                                 = 0x593CCBDD, ///< Generated in response to ovr_Achievements_Unlock()
  ovrMessage_ApplicationLifecycle_GetRegisteredPIDs              = 0x04E5CF62, ///< Generated in response to ovr_ApplicationLifecycle_GetRegisteredPIDs()
  ovrMessage_ApplicationLifecycle_GetSessionKey                  = 0x3AAF591D, ///< Generated in response to ovr_ApplicationLifecycle_GetSessionKey()
  ovrMessage_ApplicationLifecycle_RegisterSessionKey             = 0x4DB6AFF8, ///< Generated in response to ovr_ApplicationLifecycle_RegisterSessionKey()
  ovrMessage_Application_GetVersion                              = 0x68670A0E, ///< Generated in response to ovr_Application_GetVersion()
  ovrMessage_Application_LaunchOtherApp                          = 0x54E2D1F8, ///< Generated in response to ovr_Application_LaunchOtherApp()
  ovrMessage_AssetFile_Delete                                    = 0x6D5D7886, ///< Generated in response to ovr_AssetFile_Delete()
  ovrMessage_AssetFile_DeleteById                                = 0x5AE8CD52, ///< Generated in response to ovr_AssetFile_DeleteById()
  ovrMessage_AssetFile_DeleteByName                              = 0x420AC1CF, ///< Generated in response to ovr_AssetFile_DeleteByName()
  ovrMessage_AssetFile_Download                                  = 0x11449FC5, ///< Generated in response to ovr_AssetFile_Download()
  ovrMessage_AssetFile_DownloadById                              = 0x2D008992, ///< Generated in response to ovr_AssetFile_DownloadById()
  ovrMessage_AssetFile_DownloadByName                            = 0x6336CEFA, ///< Generated in response to ovr_AssetFile_DownloadByName()
  ovrMessage_AssetFile_DownloadCancel                            = 0x080AD3C7, ///< Generated in response to ovr_AssetFile_DownloadCancel()
  ovrMessage_AssetFile_DownloadCancelById                        = 0x51659514, ///< Generated in response to ovr_AssetFile_DownloadCancelById()
  ovrMessage_AssetFile_DownloadCancelByName                      = 0x446AECFA, ///< Generated in response to ovr_AssetFile_DownloadCancelByName()
  ovrMessage_AssetFile_GetList                                   = 0x4AFC6F74, ///< Generated in response to ovr_AssetFile_GetList()
  ovrMessage_AssetFile_Status                                    = 0x02D32F60, ///< Generated in response to ovr_AssetFile_Status()
  ovrMessage_AssetFile_StatusById                                = 0x5D955D38, ///< Generated in response to ovr_AssetFile_StatusById()
  ovrMessage_AssetFile_StatusByName                              = 0x41CFDA50, ///< Generated in response to ovr_AssetFile_StatusByName()
  ovrMessage_Avatar_LaunchAvatarEditor                           = 0x05F1E153, ///< Generated in response to ovr_Avatar_LaunchAvatarEditor()
  ovrMessage_Challenges_Create                                   = 0x6859D641, ///< Generated in response to ovr_Challenges_Create()
  ovrMessage_Challenges_DeclineInvite                            = 0x568E76C0, ///< Generated in response to ovr_Challenges_DeclineInvite()
  ovrMessage_Challenges_Delete                                   = 0x264885CA, ///< Generated in response to ovr_Challenges_Delete()
  ovrMessage_Challenges_Get                                      = 0x77584EF3, ///< Generated in response to ovr_Challenges_Get()
  ovrMessage_Challenges_GetEntries                               = 0x121AB45F, ///< Generated in response to ovr_Challenges_GetEntries()
  ovrMessage_Challenges_GetEntriesAfterRank                      = 0x08891A7F, ///< Generated in response to ovr_Challenges_GetEntriesAfterRank()
  ovrMessage_Challenges_GetEntriesByIds                          = 0x316509DC, ///< Generated in response to ovr_Challenges_GetEntriesByIds()
  ovrMessage_Challenges_GetList                                  = 0x43264356, ///< Generated in response to ovr_Challenges_GetList()
  ovrMessage_Challenges_GetNextChallenges                        = 0x5B7CA1B6, ///< Generated in response to ovr_Challenges_GetNextChallenges()
  ovrMessage_Challenges_GetNextEntries                           = 0x7F4CA0C6, ///< Generated in response to ovr_Challenges_GetNextEntries()
  ovrMessage_Challenges_GetPreviousChallenges                    = 0x0EB4040D, ///< Generated in response to ovr_Challenges_GetPreviousChallenges()
  ovrMessage_Challenges_GetPreviousEntries                       = 0x78C90470, ///< Generated in response to ovr_Challenges_GetPreviousEntries()
  ovrMessage_Challenges_Join                                     = 0x21248069, ///< Generated in response to ovr_Challenges_Join()
  ovrMessage_Challenges_Leave                                    = 0x296116E5, ///< Generated in response to ovr_Challenges_Leave()
  ovrMessage_Challenges_UpdateInfo                               = 0x1175BE60, ///< Generated in response to ovr_Challenges_UpdateInfo()
  ovrMessage_CloudStorage2_GetUserDirectoryPath                  = 0x76A42EEE, ///< Generated in response to ovr_CloudStorage2_GetUserDirectoryPath()
  ovrMessage_CloudStorage_Delete                                 = 0x28DA456D, ///< Generated in response to ovr_CloudStorage_Delete()
  ovrMessage_CloudStorage_GetNextCloudStorageMetadataArrayPage   = 0x5C07A2EF, ///< Generated in response to ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage()
  ovrMessage_CloudStorage_Load                                   = 0x40846B41, ///< Generated in response to ovr_CloudStorage_Load()
  ovrMessage_CloudStorage_LoadBucketMetadata                     = 0x7327A50D, ///< Generated in response to ovr_CloudStorage_LoadBucketMetadata()
  ovrMessage_CloudStorage_LoadConflictMetadata                   = 0x445A52F2, ///< Generated in response to ovr_CloudStorage_LoadConflictMetadata()
  ovrMessage_CloudStorage_LoadHandle                             = 0x326ADA36, ///< Generated in response to ovr_CloudStorage_LoadHandle()
  ovrMessage_CloudStorage_LoadMetadata                           = 0x03E6A292, ///< Generated in response to ovr_CloudStorage_LoadMetadata()
  ovrMessage_CloudStorage_ResolveKeepLocal                       = 0x30588D05, ///< Generated in response to ovr_CloudStorage_ResolveKeepLocal()
  ovrMessage_CloudStorage_ResolveKeepRemote                      = 0x7525A306, ///< Generated in response to ovr_CloudStorage_ResolveKeepRemote()
  ovrMessage_CloudStorage_Save                                   = 0x4BBB5C2E, ///< Generated in response to ovr_CloudStorage_Save()
  ovrMessage_Entitlement_GetIsViewerEntitled                     = 0x186B58B1, ///< Generated in response to ovr_Entitlement_GetIsViewerEntitled()
  ovrMessage_GroupPresence_Clear                                 = 0x6DAA9CC3, ///< Generated in response to ovr_GroupPresence_Clear()
  ovrMessage_GroupPresence_GetInvitableUsers                     = 0x234BC3F1, ///< Generated in response to ovr_GroupPresence_GetInvitableUsers()
  ovrMessage_GroupPresence_GetNextApplicationInviteArrayPage     = 0x04F8C0F2, ///< Generated in response to ovr_GroupPresence_GetNextApplicationInviteArrayPage()
  ovrMessage_GroupPresence_GetSentInvites                        = 0x08260AB1, ///< Generated in response to ovr_GroupPresence_GetSentInvites()
  ovrMessage_GroupPresence_LaunchInvitePanel                     = 0x0F9ECF9F, ///< Generated in response to ovr_GroupPresence_LaunchInvitePanel()
  ovrMessage_GroupPresence_LaunchMultiplayerErrorDialog          = 0x2955AF24, ///< Generated in response to ovr_GroupPresence_LaunchMultiplayerErrorDialog()
  ovrMessage_GroupPresence_LaunchRejoinDialog                    = 0x1577036F, ///< Generated in response to ovr_GroupPresence_LaunchRejoinDialog()
  ovrMessage_GroupPresence_LaunchRosterPanel                     = 0x35728882, ///< Generated in response to ovr_GroupPresence_LaunchRosterPanel()
  ovrMessage_GroupPresence_SendInvites                           = 0x0DCBD364, ///< Generated in response to ovr_GroupPresence_SendInvites()
  ovrMessage_GroupPresence_Set                                   = 0x675F5C24, ///< Generated in response to ovr_GroupPresence_Set()
  ovrMessage_GroupPresence_SetDeeplinkMessageOverride            = 0x521ADF0D, ///< Generated in response to ovr_GroupPresence_SetDeeplinkMessageOverride()
  ovrMessage_GroupPresence_SetDestination                        = 0x4C5B268A, ///< Generated in response to ovr_GroupPresence_SetDestination()
  ovrMessage_GroupPresence_SetIsJoinable                         = 0x2A8F1055, ///< Generated in response to ovr_GroupPresence_SetIsJoinable()
  ovrMessage_GroupPresence_SetLobbySession                       = 0x48FF55BE, ///< Generated in response to ovr_GroupPresence_SetLobbySession()
  ovrMessage_GroupPresence_SetMatchSession                       = 0x314C84B8, ///< Generated in response to ovr_GroupPresence_SetMatchSession()
  ovrMessage_IAP_ConsumePurchase                                 = 0x1FBB72D9, ///< Generated in response to ovr_IAP_ConsumePurchase()
  ovrMessage_IAP_GetNextProductArrayPage                         = 0x1BD94AAF, ///< Generated in response to ovr_IAP_GetNextProductArrayPage()
  ovrMessage_IAP_GetNextPurchaseArrayPage                        = 0x47570A95, ///< Generated in response to ovr_IAP_GetNextPurchaseArrayPage()
  ovrMessage_IAP_GetProductsBySKU                                = 0x7E9ACAF5, ///< Generated in response to ovr_IAP_GetProductsBySKU()
  ovrMessage_IAP_GetViewerPurchases                              = 0x3A0F8419, ///< Generated in response to ovr_IAP_GetViewerPurchases()
  ovrMessage_IAP_GetViewerPurchasesDurableCache                  = 0x63599E2B, ///< Generated in response to ovr_IAP_GetViewerPurchasesDurableCache()
  ovrMessage_IAP_LaunchCheckoutFlow                              = 0x3F9B0D0D, ///< Generated in response to ovr_IAP_LaunchCheckoutFlow()
  ovrMessage_LanguagePack_GetCurrent                             = 0x1F90F0D5, ///< Generated in response to ovr_LanguagePack_GetCurrent()
  ovrMessage_LanguagePack_SetCurrent                             = 0x5B4FBBE0, ///< Generated in response to ovr_LanguagePack_SetCurrent()
  ovrMessage_Leaderboard_Get                                     = 0x6AD44EF8, ///< Generated in response to ovr_Leaderboard_Get()
  ovrMessage_Leaderboard_GetEntries                              = 0x5DB3474C, ///< Generated in response to ovr_Leaderboard_GetEntries()
  ovrMessage_Leaderboard_GetEntriesAfterRank                     = 0x18378BEF, ///< Generated in response to ovr_Leaderboard_GetEntriesAfterRank()
  ovrMessage_Leaderboard_GetEntriesByIds                         = 0x39607BFC, ///< Generated in response to ovr_Leaderboard_GetEntriesByIds()
  ovrMessage_Leaderboard_GetNextEntries                          = 0x4E207CD9, ///< Generated in response to ovr_Leaderboard_GetNextEntries()
  ovrMessage_Leaderboard_GetNextLeaderboardArrayPage             = 0x35F6769B, ///< Generated in response to ovr_Leaderboard_GetNextLeaderboardArrayPage()
  ovrMessage_Leaderboard_GetPreviousEntries                      = 0x4901DAC0, ///< Generated in response to ovr_Leaderboard_GetPreviousEntries()
  ovrMessage_Leaderboard_WriteEntry                              = 0x117FC8FE, ///< Generated in response to ovr_Leaderboard_WriteEntry()
  ovrMessage_Leaderboard_WriteEntryWithSupplementaryMetric       = 0x72C692FA, ///< Generated in response to ovr_Leaderboard_WriteEntryWithSupplementaryMetric()
  ovrMessage_Matchmaking_Browse                                  = 0x1E6532C8, ///< Generated in response to ovr_Matchmaking_Browse()
  ovrMessage_Matchmaking_Browse2                                 = 0x66429E5B, ///< Generated in response to ovr_Matchmaking_Browse2()
  ovrMessage_Matchmaking_Cancel                                  = 0x206849AF, ///< Generated in response to ovr_Matchmaking_Cancel()
  ovrMessage_Matchmaking_Cancel2                                 = 0x10FE8DD4, ///< Generated in response to ovr_Matchmaking_Cancel2()
  ovrMessage_Matchmaking_CreateAndEnqueueRoom                    = 0x604C5DC8, ///< Generated in response to ovr_Matchmaking_CreateAndEnqueueRoom()
  ovrMessage_Matchmaking_CreateAndEnqueueRoom2                   = 0x295BEADB, ///< Generated in response to ovr_Matchmaking_CreateAndEnqueueRoom2()
  ovrMessage_Matchmaking_CreateRoom                              = 0x033B132A, ///< Generated in response to ovr_Matchmaking_CreateRoom()
  ovrMessage_Matchmaking_CreateRoom2                             = 0x496DA384, ///< Generated in response to ovr_Matchmaking_CreateRoom2()
  ovrMessage_Matchmaking_Enqueue                                 = 0x40C16C71, ///< Generated in response to ovr_Matchmaking_Enqueue()
  ovrMessage_Matchmaking_Enqueue2                                = 0x121212B5, ///< Generated in response to ovr_Matchmaking_Enqueue2()
  ovrMessage_Matchmaking_EnqueueRoom                             = 0x708A4064, ///< Generated in response to ovr_Matchmaking_EnqueueRoom()
  ovrMessage_Matchmaking_EnqueueRoom2                            = 0x5528DBA4, ///< Generated in response to ovr_Matchmaking_EnqueueRoom2()
  ovrMessage_Matchmaking_GetAdminSnapshot                        = 0x3C215F94, ///< Generated in response to ovr_Matchmaking_GetAdminSnapshot()
  ovrMessage_Matchmaking_GetStats                                = 0x42FC9438, ///< Generated in response to ovr_Matchmaking_GetStats()
  ovrMessage_Matchmaking_JoinRoom                                = 0x4D32D7FD, ///< Generated in response to ovr_Matchmaking_JoinRoom()
  ovrMessage_Matchmaking_ReportResultInsecure                    = 0x1A36D18D, ///< Generated in response to ovr_Matchmaking_ReportResultInsecure()
  ovrMessage_Matchmaking_StartMatch                              = 0x44D40945, ///< Generated in response to ovr_Matchmaking_StartMatch()
  ovrMessage_Media_ShareToFacebook                               = 0x00E38AEF, ///< Generated in response to ovr_Media_ShareToFacebook()
  ovrMessage_Notification_GetNextRoomInviteNotificationArrayPage = 0x0621FB77, ///< Generated in response to ovr_Notification_GetNextRoomInviteNotificationArrayPage()
  ovrMessage_Notification_GetRoomInvites                         = 0x6F916B92, ///< Generated in response to ovr_Notification_GetRoomInvites()
  ovrMessage_Notification_MarkAsRead                             = 0x717259E3, ///< Generated in response to ovr_Notification_MarkAsRead()
  ovrMessage_Party_GetCurrent                                    = 0x47933760, ///< Generated in response to ovr_Party_GetCurrent()
  ovrMessage_RichPresence_Clear                                  = 0x57B752B3, ///< Generated in response to ovr_RichPresence_Clear()
  ovrMessage_RichPresence_GetDestinations                        = 0x586F2D14, ///< Generated in response to ovr_RichPresence_GetDestinations()
  ovrMessage_RichPresence_GetNextDestinationArrayPage            = 0x67367F45, ///< Generated in response to ovr_RichPresence_GetNextDestinationArrayPage()
  ovrMessage_RichPresence_Set                                    = 0x3C147509, ///< Generated in response to ovr_RichPresence_Set()
  ovrMessage_Room_CreateAndJoinPrivate                           = 0x75D6E377, ///< Generated in response to ovr_Room_CreateAndJoinPrivate()
  ovrMessage_Room_CreateAndJoinPrivate2                          = 0x5A3A6243, ///< Generated in response to ovr_Room_CreateAndJoinPrivate2()
  ovrMessage_Room_Get                                            = 0x659A8FB8, ///< Generated in response to ovr_Room_Get()
  ovrMessage_Room_GetCurrent                                     = 0x09A6A504, ///< Generated in response to ovr_Room_GetCurrent()
  ovrMessage_Room_GetCurrentForUser                              = 0x0E0017E5, ///< Generated in response to ovr_Room_GetCurrentForUser()
  ovrMessage_Room_GetInvitableUsers                              = 0x1E325792, ///< Generated in response to ovr_Room_GetInvitableUsers()
  ovrMessage_Room_GetInvitableUsers2                             = 0x4F53E8B0, ///< Generated in response to ovr_Room_GetInvitableUsers2()
  ovrMessage_Room_GetModeratedRooms                              = 0x0983FD77, ///< Generated in response to ovr_Room_GetModeratedRooms()
  ovrMessage_Room_GetNextRoomArrayPage                           = 0x4E8379C6, ///< Generated in response to ovr_Room_GetNextRoomArrayPage()
  ovrMessage_Room_InviteUser                                     = 0x4129EC13, ///< Generated in response to ovr_Room_InviteUser()
  ovrMessage_Room_Join                                           = 0x16CA8F09, ///< Generated in response to ovr_Room_Join()
  ovrMessage_Room_Join2                                          = 0x4DAB1C42, ///< Generated in response to ovr_Room_Join2()
  ovrMessage_Room_KickUser                                       = 0x49835736, ///< Generated in response to ovr_Room_KickUser()
  ovrMessage_Room_LaunchInvitableUserFlow                        = 0x323FE273, ///< Generated in response to ovr_Room_LaunchInvitableUserFlow()
  ovrMessage_Room_Leave                                          = 0x72382475, ///< Generated in response to ovr_Room_Leave()
  ovrMessage_Room_SetDescription                                 = 0x3044852F, ///< Generated in response to ovr_Room_SetDescription()
  ovrMessage_Room_UpdateDataStore                                = 0x026E4028, ///< Generated in response to ovr_Room_UpdateDataStore()
  ovrMessage_Room_UpdateMembershipLockStatus                     = 0x370BB7AC, ///< Generated in response to ovr_Room_UpdateMembershipLockStatus()
  ovrMessage_Room_UpdateOwner                                    = 0x32B63D1D, ///< Generated in response to ovr_Room_UpdateOwner()
  ovrMessage_Room_UpdatePrivateRoomJoinPolicy                    = 0x1141029B, ///< Generated in response to ovr_Room_UpdatePrivateRoomJoinPolicy()
  ovrMessage_UserDataStore_PrivateDeleteEntryByKey               = 0x5C896F3E, ///< Generated in response to ovr_UserDataStore_PrivateDeleteEntryByKey()
  ovrMessage_UserDataStore_PrivateGetEntries                     = 0x6C8A8228, ///< Generated in response to ovr_UserDataStore_PrivateGetEntries()
  ovrMessage_UserDataStore_PrivateGetEntryByKey                  = 0x1C068319, ///< Generated in response to ovr_UserDataStore_PrivateGetEntryByKey()
  ovrMessage_UserDataStore_PrivateWriteEntry                     = 0x41D2828B, ///< Generated in response to ovr_UserDataStore_PrivateWriteEntry()
  ovrMessage_UserDataStore_PublicDeleteEntryByKey                = 0x1DD5E5FB, ///< Generated in response to ovr_UserDataStore_PublicDeleteEntryByKey()
  ovrMessage_UserDataStore_PublicGetEntries                      = 0x167D4BC2, ///< Generated in response to ovr_UserDataStore_PublicGetEntries()
  ovrMessage_UserDataStore_PublicGetEntryByKey                   = 0x195C66C6, ///< Generated in response to ovr_UserDataStore_PublicGetEntryByKey()
  ovrMessage_UserDataStore_PublicWriteEntry                      = 0x34364A0A, ///< Generated in response to ovr_UserDataStore_PublicWriteEntry()
  ovrMessage_User_Get                                            = 0x6BCF9E47, ///< Generated in response to ovr_User_Get()
  ovrMessage_User_GetAccessToken                                 = 0x06A85ABE, ///< Generated in response to ovr_User_GetAccessToken()
  ovrMessage_User_GetBlockedUsers                                = 0x7D201556, ///< Generated in response to ovr_User_GetBlockedUsers()
  ovrMessage_User_GetLoggedInUser                                = 0x436F345D, ///< Generated in response to ovr_User_GetLoggedInUser()
  ovrMessage_User_GetLoggedInUserFriends                         = 0x587C2A8D, ///< Generated in response to ovr_User_GetLoggedInUserFriends()
  ovrMessage_User_GetLoggedInUserFriendsAndRooms                 = 0x5E870B87, ///< Generated in response to ovr_User_GetLoggedInUserFriendsAndRooms()
  ovrMessage_User_GetLoggedInUserRecentlyMetUsersAndRooms        = 0x295FBA30, ///< Generated in response to ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms()
  ovrMessage_User_GetNextBlockedUserArrayPage                    = 0x7C2AFDCB, ///< Generated in response to ovr_User_GetNextBlockedUserArrayPage()
  ovrMessage_User_GetNextUserAndRoomArrayPage                    = 0x7FBDD2DF, ///< Generated in response to ovr_User_GetNextUserAndRoomArrayPage()
  ovrMessage_User_GetNextUserArrayPage                           = 0x267CF743, ///< Generated in response to ovr_User_GetNextUserArrayPage()
  ovrMessage_User_GetNextUserCapabilityArrayPage                 = 0x2309F399, ///< Generated in response to ovr_User_GetNextUserCapabilityArrayPage()
  ovrMessage_User_GetOrgScopedID                                 = 0x18F0B01B, ///< Generated in response to ovr_User_GetOrgScopedID()
  ovrMessage_User_GetSdkAccounts                                 = 0x67526A83, ///< Generated in response to ovr_User_GetSdkAccounts()
  ovrMessage_User_GetUserProof                                   = 0x22810483, ///< Generated in response to ovr_User_GetUserProof()
  ovrMessage_User_LaunchBlockFlow                                = 0x6FD62528, ///< Generated in response to ovr_User_LaunchBlockFlow()
  ovrMessage_User_LaunchFriendRequestFlow                        = 0x0904B598, ///< Generated in response to ovr_User_LaunchFriendRequestFlow()
  ovrMessage_User_LaunchUnblockFlow                              = 0x14A22A97, ///< Generated in response to ovr_User_LaunchUnblockFlow()
  ovrMessage_Voip_GetMicrophoneAvailability                      = 0x744CE345, ///< Generated in response to ovr_Voip_GetMicrophoneAvailability()
  ovrMessage_Voip_SetSystemVoipSuppressed                        = 0x453FC9AA, ///< Generated in response to ovr_Voip_SetSystemVoipSuppressed()

  /// The user has tapped the report button in the panel that appears after
  /// pressing the Oculus button.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_AbuseReport_ReportButtonPressed = 0x24472F6C,

  /// Sent when a launch intent is received (for both cold and warm starts). The
  /// payload is the type of the intent.
  /// ovr_ApplicationLifecycle_GetLaunchDetails() should be called to get the
  /// other details.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_ApplicationLifecycle_LaunchIntentChanged = 0x04B34CA3,

  /// Sent to indicate download progress for asset files.
  ///
  /// The message will contain a payload of type ::ovrAssetFileDownloadUpdateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetAssetFileDownloadUpdate().
  ovrMessage_Notification_AssetFile_DownloadUpdate = 0x2FDD0CCD,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Result of a leader picking an application for CAL launch.
  ///
  /// The message will contain a payload of type ::ovrCalApplicationFinalizedHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetCalApplicationFinalized().
  ovrMessage_Notification_Cal_FinalizeApplication = 0x750C5099,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Application that the group leader has proposed for a CAL launch.
  ///
  /// The message will contain a payload of type ::ovrCalApplicationProposedHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetCalApplicationProposed().
  ovrMessage_Notification_Cal_ProposeApplication = 0x2E7451F5,

  /// Sent when the user is finished using the invite panel to send out
  /// invitations. Contains a list of invitees.
  ///
  /// The message will contain a payload of type ::ovrLaunchInvitePanelFlowResultHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetLaunchInvitePanelFlowResult().
  ovrMessage_Notification_GroupPresence_InvitationsSent = 0x679A84B6,

  /// Sent when a user has chosen to join the destination/lobby/match. Read all
  /// the fields to figure out where the user wants to go and take the
  /// appropriate actions to bring them there. If the user is unable to go there,
  /// provide adequate messaging to the user on why they cannot go there. These
  /// notifications should be responded to immediately.
  ///
  /// The message will contain a payload of type ::ovrGroupPresenceJoinIntentHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetGroupPresenceJoinIntent().
  ovrMessage_Notification_GroupPresence_JoinIntentReceived = 0x773889F6,

  /// Sent when the user has chosen to leave the destination/lobby/match from the
  /// Oculus menu. Read the specific fields to check the user is currently from
  /// the destination/lobby/match and take the appropriate actions to remove
  /// them. Update the user's presence clearing the appropriate fields to
  /// indicate the user has left.
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
  /// performance. Use ovr_Message_GetLivestreamingStatus() to extract the
  /// updated livestreaming status.
  ///
  /// The message will contain a payload of type ::ovrLivestreamingStatusHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetLivestreamingStatus().
  ovrMessage_Notification_Livestreaming_StatusChange = 0x2247596E,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Indicates that a match has been found, for example after calling
  /// ovr_Matchmaking_Enqueue(). Use ovr_Message_GetRoom() to extract the
  /// matchmaking room.
  ovrMessage_Notification_Matchmaking_MatchFound = 0x0BC3FCD7,

  /// Sent when the status of a connection has changed.
  ///
  /// The message will contain a payload of type ::ovrNetSyncConnectionHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetSyncConnection().
  ovrMessage_Notification_NetSync_ConnectionStatusChanged = 0x073484CA,

  /// Sent when the list of known connected sessions has changed. Contains the
  /// new list of sessions.
  ///
  /// The message will contain a payload of type ::ovrNetSyncSessionsChangedNotificationHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetSyncSessionsChangedNotification().
  ovrMessage_Notification_NetSync_SessionsChanged = 0x387E7F36,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Indicates that a connection has been established or there's been an error.
  /// Use ovr_NetworkingPeer_GetState() to get the result; as above,
  /// ovr_NetworkingPeer_GetID() returns the ID of the peer this message is for.
  ///
  /// The message will contain a payload of type ::ovrNetworkingPeerHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetworkingPeer().
  ovrMessage_Notification_Networking_ConnectionStateChange = 0x5E02D49A,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Indicates that another user is attempting to establish a P2P connection
  /// with us. Use ovr_NetworkingPeer_GetID() to extract the ID of the peer.
  ///
  /// The message will contain a payload of type ::ovrNetworkingPeerHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetworkingPeer().
  ovrMessage_Notification_Networking_PeerConnectRequest = 0x4D31E2CF,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Generated in response to ovr_Net_Ping(). Either contains ping time in
  /// microseconds or indicates that there was a timeout.
  ///
  /// The message will contain a payload of type ::ovrPingResultHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetPingResult().
  ovrMessage_Notification_Networking_PingResult = 0x51153012,

  /// Indicates that party has been updated
  ///
  /// The message will contain a payload of type ::ovrPartyUpdateNotificationHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetPartyUpdateNotification().
  ovrMessage_Notification_Party_PartyUpdate = 0x1D118AB2,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Indicates that the user has accepted an invitation, for example in Oculus
  /// Home. Use ovr_Message_GetString() to extract the ID of the room that the
  /// user has been inivted to as a string. Then call ovrID_FromString() to parse
  /// it into an ovrID.
  ///
  /// Note that you must call ovr_Room_Join() if you want to actually join the
  /// room.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Room_InviteAccepted = 0x6D1071B1,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Handle this to notify the user when they've received an invitation to join
  /// a room in your game. You can use this in lieu of, or in addition to,
  /// polling for room invitations via ovr_Notification_GetRoomInvites().
  ///
  /// The message will contain a payload of type ::ovrRoomInviteNotificationHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetRoomInviteNotification().
  ovrMessage_Notification_Room_InviteReceived = 0x6A499D54,

  /// DEPRECATED. Will be removed from headers at version v51.
  ///
  /// Indicates that the current room has been updated. Use ovr_Message_GetRoom()
  /// to extract the updated room.
  ///
  /// The message will contain a payload of type ::ovrRoomHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetRoom().
  ovrMessage_Notification_Room_RoomUpdate = 0x60EC3C2F,

  /// DEPRECATED. Do not use or expose further. Use
  /// ovrNotification_GroupPresence_InvitationsSent instead. Will be removed from
  /// headers at version v51.
  ///
  /// The message will contain a payload of type ::ovrLaunchInvitePanelFlowResultHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetLaunchInvitePanelFlowResult().
  ovrMessage_Notification_Session_InvitationsSent = 0x07F9C880,

  /// Sent when another user is attempting to establish a VoIP connection. Use
  /// ovr_Message_GetNetworkingPeer() to extract information about the user, and
  /// ovr_Voip_Accept() to accept the connection.
  ///
  /// The message will contain a payload of type ::ovrNetworkingPeerHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetworkingPeer().
  ovrMessage_Notification_Voip_ConnectRequest = 0x36243816,

  /// Indicates that the current microphone availability state has been updated.
  /// Use ovr_Voip_GetMicrophoneAvailability() to extract the microphone
  /// availability state.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate = 0x3E20CB57,

  /// Sent to indicate that the state of the VoIP connection changed. Use
  /// ovr_Message_GetNetworkingPeer() and ovr_NetworkingPeer_GetState() to
  /// extract the current state.
  ///
  /// The message will contain a payload of type ::ovrNetworkingPeerHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetNetworkingPeer().
  ovrMessage_Notification_Voip_StateChange = 0x34EFA660,

  /// Sent to indicate that some part of the overall state of SystemVoip has
  /// changed. Use ovr_Message_GetSystemVoipState() and the properties of
  /// ovrSystemVoipStateHandle to extract the state that triggered the
  /// notification.
  ///
  /// Note that the state may have changed further since the notification was
  /// generated, and that you may call the `GetSystemVoip...()` family of
  /// functions at any time to get the current state directly.
  ///
  /// The message will contain a payload of type ::ovrSystemVoipStateHandle.
  /// Extract the payload from the message handle with ::ovr_Message_GetSystemVoipState().
  ovrMessage_Notification_Voip_SystemVoipState = 0x58D254A5,

  /// Get vr camera related webrtc data channel messages for update.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Vrcamera_GetDataChannelMessageUpdate = 0x6EE4F33C,

  /// Get surface and update action from platform webrtc for update.
  ///
  /// The message will contain a payload of type const char *.
  /// Extract the payload from the message handle with ::ovr_Message_GetString().
  ovrMessage_Notification_Vrcamera_GetSurfaceUpdate = 0x37F21084,

  ovrMessage_PlatformInitializeWithAccessToken = 0x35692F2B,
  ovrMessage_Platform_InitializeStandaloneOculus = 0x51F8CE0C,
  ovrMessage_PlatformInitializeAndroidAsynchronous = 0x1AD307B4,
  ovrMessage_PlatformInitializeWindowsAsynchronous = 0x6DA7BA8F,
} ovrMessageType;

/// Convert an ovrMessageType to a human readable string
///
OVRPL_PUBLIC_FUNCTION(const char*) ovrMessageType_ToString(ovrMessageType value);

/// Return true if an ovrMessageType is a notification
///
OVRPL_PUBLIC_FUNCTION(bool) ovrMessageType_IsNotification(ovrMessageType value);

#endif
