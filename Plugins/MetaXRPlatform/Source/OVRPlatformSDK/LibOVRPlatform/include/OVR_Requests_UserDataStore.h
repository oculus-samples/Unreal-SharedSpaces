// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_USERDATASTORE_H
#define OVR_REQUESTS_USERDATASTORE_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// Delete an entry by a key from a private user data store.
/// \param userID The ID of the user who owns this private user data store.
/// \param key The key of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PrivateDeleteEntryByKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserDataStoreUpdateResponseHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserDataStoreUpdateResponse().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PrivateDeleteEntryByKey(ovrID userID, const char *key);

/// Get entries from a private user data store.
/// \param userID The ID of the user who owns this private user data store.
///
/// A message with type ::ovrMessage_UserDataStore_PrivateGetEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDataStoreHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDataStore().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PrivateGetEntries(ovrID userID);

/// Get an entry by a key from a private user data store.
/// \param userID The ID of the user who owns this private user data store.
/// \param key The key of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PrivateGetEntryByKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDataStoreHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDataStore().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PrivateGetEntryByKey(ovrID userID, const char *key);

/// Write a single entry to a private user data store.
/// \param userID The ID of the user who owns this private user data store.
/// \param key The key of entry.
/// \param value The value of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PrivateWriteEntry will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserDataStoreUpdateResponseHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserDataStoreUpdateResponse().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PrivateWriteEntry(ovrID userID, const char *key, const char *value);

/// Delete an entry by a key from a public user data store.
/// \param userID The ID of the user who owns this public user data store.
/// \param key The key of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PublicDeleteEntryByKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserDataStoreUpdateResponseHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserDataStoreUpdateResponse().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PublicDeleteEntryByKey(ovrID userID, const char *key);

/// Get entries from a public user data store.
/// \param userID The ID of the user who owns this public user data store.
///
/// A message with type ::ovrMessage_UserDataStore_PublicGetEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDataStoreHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDataStore().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PublicGetEntries(ovrID userID);

/// Get an entry by a key from a public user data store.
/// \param userID The ID of the user who owns this public user data store.
/// \param key The key of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PublicGetEntryByKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDataStoreHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDataStore().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PublicGetEntryByKey(ovrID userID, const char *key);

/// Write a single entry to a public user data store.
/// \param userID The ID of the user who owns this public user data store.
/// \param key The key of entry.
/// \param value The value of entry.
///
/// A message with type ::ovrMessage_UserDataStore_PublicWriteEntry will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserDataStoreUpdateResponseHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserDataStoreUpdateResponse().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_UserDataStore_PublicWriteEntry(ovrID userID, const char *key, const char *value);

#endif
