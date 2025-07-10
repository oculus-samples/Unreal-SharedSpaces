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

#ifndef OVR_USERPROOF_H
#define OVR_USERPROOF_H

#include "OVR_Platform_Defs.h"

/// \file
/// This object is retrieved from the ovr_User_GetUserProof() request and will
/// contain a nonce that is used to verify the identity of the User. Read more
/// about user verification in our [User Verification
/// guide](https://developer.oculus.com/documentation/native/ps-
/// ownership/#integrate-user-verification)
///
/// NOTE: The nonce is only good for one check and then it is invalidated.
typedef struct ovrUserProof *ovrUserProofHandle;

/// A string that is returned from the client that is used to verify the
/// identity of the User. The nonce can be used with the meta account to the
/// `https://graph.oculus.com/user_nonce_validate` endpoint to verify identity.
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserProof_GetNonce(const ovrUserProofHandle obj);


#endif
