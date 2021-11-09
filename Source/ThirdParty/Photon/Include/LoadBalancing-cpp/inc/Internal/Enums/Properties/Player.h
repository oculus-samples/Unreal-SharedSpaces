/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/PhotonPeer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			// Photon properties, internally set by LoadBalancing (LoadBalancing builtin properties)
			namespace Properties
			{
				namespace Player
				{
					/// (255) Name of a player/actor.
					static const nByte PLAYERNAME =  255;
					/// (254) Tells you if the player is currently in this game (getting events live).
					/// A server-set value for async games, where players can leave the game and return later.
					static const nByte IS_INACTIVE =  254;
					static const nByte USER_ID =  253;
				}
			}
		}
	}
}