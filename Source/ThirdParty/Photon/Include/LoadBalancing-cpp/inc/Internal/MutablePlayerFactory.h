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
		class MutablePlayer;
		class MutableRoom;
		class Peer;

		namespace Internal
		{
			class MutablePlayerFactory
			{
			protected:
				virtual ~MutablePlayerFactory(void);

				virtual MutablePlayer* create(int number, const Common::Hashtable& properties, const MutableRoom* pRoom, Client* pClient);
				virtual void destroy(const MutablePlayer* pPlayer);
			private:
				friend class LoadBalancing::Client;
			};
		}
	}
}