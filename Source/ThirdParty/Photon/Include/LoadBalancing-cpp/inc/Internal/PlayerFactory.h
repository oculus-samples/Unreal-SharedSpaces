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
		class MutableRoom;
		class Player;

		namespace Internal
		{
			class PlayerFactory
			{
				static Player* create(int number, const Common::Hashtable& properties, const MutableRoom* pRoom);
				static void destroy(const Player* pPlayer);

				friend class LoadBalancing::MutableRoom;
			};
		}
	}
}