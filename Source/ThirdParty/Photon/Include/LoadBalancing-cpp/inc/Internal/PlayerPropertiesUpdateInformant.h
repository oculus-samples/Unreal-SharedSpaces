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
		class MutableRoom;

		namespace Internal
		{
			class PlayerMovementInformant;

			class PlayerPropertiesUpdateInformant
			{
				static void onUpdate(MutableRoom& room, int number, const Common::Hashtable& properties);
				static bool setIsInactive(MutableRoom& room, int number, bool isInactive);

				friend class LoadBalancing::Client;
				friend class LoadBalancing::Internal::PlayerMovementInformant;
			};
		}
	}
}