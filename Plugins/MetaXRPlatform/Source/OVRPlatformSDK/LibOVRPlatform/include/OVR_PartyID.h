// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTYID_H
#define OVR_PARTYID_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// The party ID is a unique identifier of the party that will be generated for
/// every distinct party. This ID can be used to make requests such as
/// ovr_Party_Join(), ovr_Party_Leave(), ovr_Party_Create(), etc. Read more
/// about [parties](https://developer.oculus.com/documentation/native/ps-
/// parties/).
typedef struct ovrPartyID *ovrPartyIDHandle;

/// The party ID can be used to retrieve ovrPartyHandle. Every party will have
/// a unique ID that is associated with it.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyID_GetID(const ovrPartyIDHandle obj);


#endif
