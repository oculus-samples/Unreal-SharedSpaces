// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTY_UPDATE_ACTION_H
#define OVR_PARTY_UPDATE_ACTION_H

#include "OVR_Platform_Defs.h"

/// An enum that specifies the action that the user can take, which will lead
/// to a ovrPartyUpdateNotificationHandle. It can be used in {'party_update':
/// 'ovrNotification_Party_PartyUpdate'} and can be retrieved using
/// ovr_PartyUpdateNotification_GetAction()
typedef enum ovrPartyUpdateAction_ {
  ovrPartyUpdateAction_Unknown,
  /// Indicates the user joined the party.
  ovrPartyUpdateAction_Join,
  /// Indicates the user left the party.
  ovrPartyUpdateAction_Leave,
  /// Indicates the user was invited to the party.
  ovrPartyUpdateAction_Invite,
  /// Indicates the user was uninvited to the party.
  ovrPartyUpdateAction_Uninvite,
} ovrPartyUpdateAction;

/// Converts an ovrPartyUpdateAction enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrPartyUpdateAction_ToString(ovrPartyUpdateAction value);

/// Converts a string representing an ovrPartyUpdateAction enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrPartyUpdateAction) ovrPartyUpdateAction_FromString(const char* str);

#endif
