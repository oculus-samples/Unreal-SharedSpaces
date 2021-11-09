/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"
#include "LoadBalancing-cpp/inc/MutableRoom.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Client;
		class Player;

		namespace Internal
		{
			class PlayerMovementInformant
			{
				static void onEnterLocal(MutableRoom& room, Player& player);
				static void onEnterRemote(MutableRoom& room, int number, const Common::Hashtable& properties);
				static bool onLeaveLocal(MutableRoom& room, int number);
				static bool onLeaveRemote(MutableRoom& room, int number);
				static bool onMasterClientChanged(MutableRoom& room, int number);

				friend class LoadBalancing::Client;
			};
		}
	}
}