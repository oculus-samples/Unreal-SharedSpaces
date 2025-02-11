// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_ACHIEVEMENTS_H
#define OVR_REQUESTS_ACHIEVEMENTS_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AchievementDefinitionArray.h"
#include "OVR_AchievementProgressArray.h"

/// \file
/// Achievements Overview
///
/// *** Achievement Objects:
///
/// The API exposes two object types related to achievements, achievement definition
/// objects and achievement progress objects.
///
/// Achievement Definitions:
/// Achievement definition objects define your game's achievements. They comprise an
/// internal name, an achievement type, and the target which much be reached to
/// unlock that achievement
///
/// Achievement Progress:
/// Achievement progress objects represent the progress that a player has made
/// toward an achievement. They comprise a name, whether or not the achievement is
/// unlocked, the time at which it was unlocked, an achievement type, and, depending
/// on the type, the progress made towards unlocking it.
///
///
/// *** Achievement Types:
///
/// Achievements come in three flavors: Simple achievements, count achievements, and
/// bitfield achievements.
///
/// Simple Achievements:
/// Simple achievements are either locked or unlocked, with no notion of progress.
/// Examples could include "Beat Level 3" or "Give Josh A Bad Performance Review
/// Because He Made Me Write This Boring Achievements Documentation". Call
/// ovr_Achievements_Unlock() to unlock a simple achievement.
///
/// Count Achievements:
/// Count achievements have an integer target and are unlocked when that target is
/// reached. Call ovr_AchievementDefinition_GetTarget() to get the target, and
/// ovr_Achievements_AddCount() to add progress towards the target of a bitfield
/// achievement. Examples could include "Collect 100 Coins" or "Avoid 5 Tedious
/// Meetings About Improving The Achievements API By Hiding In The Utility Closet"
///
/// Bitfield Achievements:
/// Bitfield achievement have a fixed number of fields which are either true or
/// false, and an integer target which represents the number of fields which must be
/// true for the achievement to be unlocked. This makes it possible to create N of M
/// achievements, such as "Visit 4 of the 7 Continents" or "Fix 3 of 10 Crash Bugs
/// In The Achievements API, But Leave The Rest In, Because Life Would be Boring
/// Without A Little Unpredictability". Call ovr_Achievements_AddFields() to unlock
/// the fields of a bitfield achievement

/// Add 'count' to the achievement with the given name. This must be a COUNT
/// achievement. The largest number that is supported by this method is the max
/// value of a signed 64-bit integer. If the number is larger than that, it is
/// clamped to that max value before being passed to the servers.
/// \param name The api_name of the achievement that will be adding count, which can be retrieved by ovr_AchievementDefinition_GetName().
/// \param count The value of count that will be added to the achievement.
///
/// A message with type ::ovrMessage_Achievements_AddCount will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementUpdate().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_AddCount(const char *name, unsigned long long count);

/// Unlock fields of a BITFIELD achievement.
/// \param name The api_name of the Bitfield achievement whose field(s) will be unlocked, which can be retrieved by ovr_AchievementDefinition_GetName().
/// \param fields A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
///
/// A message with type ::ovrMessage_Achievements_AddFields will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementUpdate().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_AddFields(const char *name, const char *fields);

/// Retrieve all achievement definitions for the app, including their name,
/// unlock requirements, and any additional details.
///
/// A message with type ::ovrMessage_Achievements_GetAllDefinitions will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementDefinitionArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementDefinitionArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetAllDefinitions();

/// Retrieve the progress for the user on all achievements in the app.
///
/// A message with type ::ovrMessage_Achievements_GetAllProgress will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementProgressArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementProgressArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetAllProgress();

/// Retrieve the achievement definitions that match the specified names,
/// including their name, unlock requirements, and any additional details.
/// \param names The api_names of the achievements used to retrieve the definition information, which can be retrieved by ovr_AchievementDefinition_GetName().
/// \param count The number of specified achievements names.
///
/// A message with type ::ovrMessage_Achievements_GetDefinitionsByName will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementDefinitionArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementDefinitionArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetDefinitionsByName(const char **names, int count);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_Achievements_GetNextAchievementDefinitionArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementDefinitionArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementDefinitionArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetNextAchievementDefinitionArrayPage(ovrAchievementDefinitionArrayHandle handle);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_Achievements_GetNextAchievementProgressArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementProgressArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementProgressArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetNextAchievementProgressArrayPage(ovrAchievementProgressArrayHandle handle);

/// Retrieve the user's progress on the achievements that match the specified
/// names.
/// \param names The api_names of the achievements used to retrieve the progress information, which can be retrieved by ovr_AchievementDefinition_GetName().
/// \param count The number of specified achievements names.
///
/// A message with type ::ovrMessage_Achievements_GetProgressByName will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementProgressArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementProgressArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_GetProgressByName(const char **names, int count);

/// Unlock the achievement with the given name. This can be of any achievement
/// type: a simple unlock, count-based, or bitfield-based achievement. The Meta
/// Quest Platform supports three types of achievements: simple, count and
/// bitfield. Each achievement type has a different unlock mechanism. Simple
/// achievements are all-or-nothing. They are unlocked by a single event or
/// objective completion. For example, a simple achievement is unlocked when
/// Frodo reaches Mount Doom. Count achievements are unlocked when a counter
/// reaches a defined target. Define the ovr_AchievementDefinition_GetTarget()
/// to reach that triggers the achievement. For example, a target achievement
/// is unlocked when Darth Vader chokes 3 disappointing Imperial officers.
/// Bitfield achievements are unlocked when a target number of bits in a
/// bitfield are set. Define the ovr_AchievementDefinition_GetTarget() and
/// ovr_AchievementDefinition_GetBitfieldLength() that triggers the
/// achievement. For example, a bitfield achievement is unlocked when Harry
/// destroys 5 of the 7 Horcruxes.
/// \param name The api_name of the achievement that will be unlocked, which can be retrieved by ovr_AchievementDefinition_GetName().
///
/// A message with type ::ovrMessage_Achievements_Unlock will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAchievementUpdate().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Achievements_Unlock(const char *name);

#endif
