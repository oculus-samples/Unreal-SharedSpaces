/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace LoadBalancing
	{
		class MutableRoom;
		class Player;

		namespace Internal
		{
			class PlayerMutableRoomPointerSetter
			{
				static void setMutableRoomPointer(Player& player, const MutableRoom* pRoom);

				friend class LoadBalancing::MutableRoom;
			};
		}
	}
}