// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_VOIP_OPTIONS_H
#define OVR_VOIP_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_VoipBitrate.h"
#include "OVR_VoipDtxState.h"

struct ovrVoipOptions;
typedef struct ovrVoipOptions* ovrVoipOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrVoipOptionsHandle) ovr_VoipOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_VoipOptions_Destroy(ovrVoipOptionsHandle handle);
/// Sets the maximum average bitrate the audio codec should use. Higher
/// bitrates will increase audio quality at the expense of increased network
/// usage. Use a lower bitrate if you think the quality is good but the network
/// usage is too much. Use a higher bitrate if you think the quality is bad and
/// you can afford to have a large streaming bitrate.
OVRP_PUBLIC_FUNCTION(void) ovr_VoipOptions_SetBitrateForNewConnections(ovrVoipOptionsHandle handle, ovrVoipBitrate value);
/// Set the opus codec to use discontinous transmission (DTX). DTX only
/// transmits data when a person is speaking. Setting this to true takes
/// advantage of the fact that in a two-way converstation each individual
/// speaks for less than half the time. Enabling DTX will conserve battery
/// power and reduce transmission rate when a pause in the voice chat is
/// detected.
OVRP_PUBLIC_FUNCTION(void) ovr_VoipOptions_SetCreateNewConnectionUseDtx(ovrVoipOptionsHandle handle, ovrVoipDtxState value);

#endif
