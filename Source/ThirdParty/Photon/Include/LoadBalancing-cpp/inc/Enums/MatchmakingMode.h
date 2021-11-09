/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		/**
			Options for matchmaking rules for OpJoinRandomRoom.*/
		namespace MatchmakingMode
		{
			static const nByte FILL_ROOM       = 0; ///<Fills up rooms (oldest first) to get players together as fast as possible. Default. Makes most sense with MaxPlayers > 0 and games that can only start with more players.
			static const nByte SERIAL_MATCHING = 1; ///<Distributes players across available rooms sequentially but takes filters into account. Without filters, rooms get players evenly distributed.
			static const nByte RANDOM_MATCHING = 2; ///<Joins a (fully) random room. Expected properties must match, but aside from this, any available room might be selected.
		}
		/** @file */
	}
}