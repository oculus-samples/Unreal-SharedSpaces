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

#ifndef OVR_DATASTORE_H
#define OVR_DATASTORE_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

/// \file
/// It's a custom data structure that contains a set of fields, each with its
/// own type and parameters. It's a flexible data structure that can hold a
/// variety of data types and can be used to store and retrieve data using
/// string keys For example, it can be used in user data store and the result
/// of an update request to the user data store can be retrieved by
/// ::ovrUserDataStoreUpdateResponseHandle.
typedef struct ovrDataStore *ovrDataStoreHandle;

/// It's a method that takes a string key as a parameter and returns a boolean
/// value indicating whether the key exists in the data store.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_DataStore_Contains(const ovrDataStoreHandle obj, const char *key);

/// It's a string that represents a single key in the data store. It allows you
/// to retrieve a specific key from the data store by its index
OVRP_PUBLIC_FUNCTION(const char *) ovr_DataStore_GetKey(const ovrDataStoreHandle obj, int index);

/// It's an integer that represents the number of keys in the data store.
OVRP_PUBLIC_FUNCTION(size_t) ovr_DataStore_GetNumKeys(const ovrDataStoreHandle obj);

/// It's a generic field that can hold any type of data. It allows you to store
/// and retrieve data using a string key, and it can be used to store a variety
/// of data types
OVRP_PUBLIC_FUNCTION(const char *) ovr_DataStore_GetValue(const ovrDataStoreHandle obj, const char *key);


#endif
