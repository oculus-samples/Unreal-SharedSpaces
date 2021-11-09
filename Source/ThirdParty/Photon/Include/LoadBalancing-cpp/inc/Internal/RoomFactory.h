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
			class RoomFactory
			{
				static Room* create(const Common::JString& name, const Common::Hashtable& properties);
				static void destroy(const Room* pRoom);

				friend class LoadBalancing::Client;
			};
		}
	}
}