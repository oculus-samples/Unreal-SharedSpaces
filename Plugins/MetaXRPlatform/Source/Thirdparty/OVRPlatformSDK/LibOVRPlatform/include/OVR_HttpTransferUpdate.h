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

#ifndef OVR_HTTPTRANSFERUPDATE_H
#define OVR_HTTPTRANSFERUPDATE_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>
#include <stddef.h>

/// \file
/// Represents an update to an HTTP transfer, which is a process of
/// transferring data over the internet using the HTTP protocol. It provides a
/// way for developers to monitor the progress of an HTTP transfer and can be
/// retrieved using #ovrMessage_Notification_HTTP_Transfer.
typedef struct ovrHttpTransferUpdate *ovrHttpTransferUpdateHandle;

/// An array of bytes that represents the data being transferred.
OVRP_PUBLIC_FUNCTION(const void *) ovr_HttpTransferUpdate_GetBytes(const ovrHttpTransferUpdateHandle obj);

/// It's a unique identifier for the HTTP transfer. It is used to track the
/// progress of the transfer and can be retrieved using
/// ovr_Message_GetRequestID().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_HttpTransferUpdate_GetID(const ovrHttpTransferUpdateHandle obj);

/// This field is a `boolean` value that indicates whether the HTTP transfer
/// has been completed or not.
OVRP_PUBLIC_FUNCTION(bool) ovr_HttpTransferUpdate_IsCompleted(const ovrHttpTransferUpdateHandle obj);

OVRP_PUBLIC_FUNCTION(size_t) ovr_HttpTransferUpdate_GetSize(const ovrHttpTransferUpdateHandle obj);

#endif
