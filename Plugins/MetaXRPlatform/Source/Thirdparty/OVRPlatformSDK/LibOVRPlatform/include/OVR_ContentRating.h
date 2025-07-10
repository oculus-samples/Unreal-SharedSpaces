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

#ifndef OVR_CONTENTRATING_H
#define OVR_CONTENTRATING_H

#include "OVR_Platform_Defs.h"

/// \file
/// A Content Rating of a ::ovrProductHandle. This rating is sourced by the
/// International Age Rating Coalition (IARC) certificate from the local rating
/// authority. An Add-on's Content Rating can be configured by adding a IARC
/// certificate in the developer dashboard. The Add-on can also inherit the
/// Content Rating of the base App.
typedef struct ovrContentRating *ovrContentRatingHandle;

/// URI for the image that needs to be shown for the content rating of the
/// ::ovrProductHandle.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ContentRating_GetAgeRatingImageUri(const ovrContentRatingHandle obj);

/// The age rating text is the text version of the rating used to describe age
/// appropriateness by the International Age Rating Coalition (IARC).
OVRP_PUBLIC_FUNCTION(const char *) ovr_ContentRating_GetAgeRatingText(const ovrContentRatingHandle obj);

/// The list of descriptors which indicate content within the product that may
/// have triggered a particular age rating or may be of interest or concern to
/// consumers, e.g., "Blood and Gore", "Intense Violence", etc.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ContentRating_GetDescriptor(const ovrContentRatingHandle obj, unsigned int index);

/// The list of interactive elements, which advise consumers up front that a
/// ::ovrProductHandle includes interactive or online behaviors/options that
/// may be of interest or concern, e.g., "In-App Purchases".
OVRP_PUBLIC_FUNCTION(const char *) ovr_ContentRating_GetInteractiveElement(const ovrContentRatingHandle obj, unsigned int index);

/// The URI pointing to a website with International Age Rating Coalition
/// (IARC) rating definitions from local rating authorities (e.g., Australian
/// Classification Board, ESRB, GRAC, etc).
OVRP_PUBLIC_FUNCTION(const char *) ovr_ContentRating_GetRatingDefinitionUri(const ovrContentRatingHandle obj);

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_ContentRating_GetDescriptorsSize(const ovrContentRatingHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_ContentRating_GetInteractiveElementsSize(const ovrContentRatingHandle obj);

#endif
