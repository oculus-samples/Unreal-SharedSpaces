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
		class Client;
		class Room;

		namespace Internal
		{
			class RoomPropertiesCacher
			{
				static void cache(Room& room, const Common::Hashtable& properties);

				friend class LoadBalancing::Client;
			};
		}
	}
}