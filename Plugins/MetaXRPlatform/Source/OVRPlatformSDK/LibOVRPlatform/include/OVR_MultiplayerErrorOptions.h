// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MULTIPLAYER_ERROR_OPTIONS_H
#define OVR_MULTIPLAYER_ERROR_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_MultiplayerErrorErrorKey.h"

struct ovrMultiplayerErrorOptions;
/// The multiplayer error option. This is used in invokable error dialogs that
/// provide general error messages to a ovrUserHandle. Read more about error
/// dialogues in our
/// [docs](https://developer.oculus.com/documentation/native/ps-error-
/// dialogs/).
typedef struct ovrMultiplayerErrorOptions* ovrMultiplayerErrorOptionsHandle;
/// \brief Creates a new instance of ovrMultiplayerErrorOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrMultiplayerErrorOptionsHandle) ovr_MultiplayerErrorOptions_Create();
/// \brief Destroys an existing instance of the ovrMultiplayerErrorOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_Destroy(ovrMultiplayerErrorOptionsHandle handle);
/// Key associated with the predefined error message to be shown to users.
///
/// Key List:
///
/// - ovrMultiplayerErrorErrorKey_DestinationUnavailable
///
/// - ovrMultiplayerErrorErrorKey_DlcRequired
///
/// - ovrMultiplayerErrorErrorKey_General
///
/// - ovrMultiplayerErrorErrorKey_GroupFull
///
/// - ovrMultiplayerErrorErrorKey_InviterNotJoinable
///
/// - ovrMultiplayerErrorErrorKey_LevelNotHighEnough
///
/// - ovrMultiplayerErrorErrorKey_LevelNotUnlocked
///
/// - ovrMultiplayerErrorErrorKey_NetworkTimeout
///
/// - ovrMultiplayerErrorErrorKey_NoLongerAvailable
///
/// - ovrMultiplayerErrorErrorKey_UpdateRequired
///
/// - ovrMultiplayerErrorErrorKey_TutorialRequired
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_SetErrorKey(ovrMultiplayerErrorOptionsHandle handle, ovrMultiplayerErrorErrorKey value);

#endif
