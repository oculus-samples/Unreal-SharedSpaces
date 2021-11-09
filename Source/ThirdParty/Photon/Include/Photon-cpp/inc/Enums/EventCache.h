/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Lite
	{
		namespace EventCache
		{
			static const nByte DO_NOT_CACHE                            =  0; // Default value (not sent).
			static const nByte MERGE_CACHE                             =  1; // Obsolete - Merges this event's keys with those already cached.
			static const nByte REPLACE_CACHE                           =  2; // Obsolete - Replaces the event cache for this eventCode with this event's content.
			static const nByte REMOVE_CACHE                            =  3; // Obsolete - Removes this event (by eventCode) from the cache.
			static const nByte ADD_TO_ROOM_CACHE                       =  4; // Adds this event to the room's cache
			static const nByte ADD_TO_ROOM_CACHE_GLOBAL                =  5; // Adds this event to the cache for actor 0 (becoming a "globally owned" event in the cache).
			static const nByte REMOVE_FROM_ROOM_CACHE                  =  6; // Removes fitting events from the room's cache.
			static const nByte REMOVE_FROM_ROOM_CACHE_FOR_ACTORS_LEFT  =  7; // Removes events of players who already left the room (cleaning up).
			static const nByte SLICE_INC_INDEX                         = 10; // Increments the slice index.
			static const nByte SLICE_SET_INDEX                         = 11; // Sets the slice index to the specified value.
			static const nByte SLICE_PURGE_INDEX                       = 12; // Deletes or purges the specified slice index.
			static const nByte SLICE_PURGE_UP_TO_INDEX                 = 13; // Purges all cache slices up to the specified index (inclusive).
		}
		/** @file */
	}
}