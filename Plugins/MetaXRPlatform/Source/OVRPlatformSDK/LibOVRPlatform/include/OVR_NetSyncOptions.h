// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_NET_SYNC_OPTIONS_H
#define OVR_NET_SYNC_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_NetSyncVoipStreamMode.h"

struct ovrNetSyncOptions;
typedef struct ovrNetSyncOptions* ovrNetSyncOptionsHandle;
/// \brief Creates a new instance of ovrNetSyncOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrNetSyncOptionsHandle) ovr_NetSyncOptions_Create();
/// \brief Destroys an existing instance of the ovrNetSyncOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_Destroy(ovrNetSyncOptionsHandle handle);
/// If provided, immediately set the voip_group to this value upon connection
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetVoipGroup(ovrNetSyncOptionsHandle handle, const char * value);
/// When a new remote voip user connects, default that connection to this
/// stream type by default.
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetVoipStreamDefault(ovrNetSyncOptionsHandle handle, ovrNetSyncVoipStreamMode value);
/// Unique identifier within the current application grouping
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetZoneId(ovrNetSyncOptionsHandle handle, const char * value);

#endif
