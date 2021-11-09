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
		class Peer;

		namespace Internal
		{
			class MutableRoomFactory
			{
			protected:
				virtual ~MutableRoomFactory(void);
				virtual MutableRoom* create(const Common::JString& name, const Common::Hashtable& properties, Client* pClient, const Common::JVector<Common::JString>& propsListedInLobby, int playerTtl, int emptyRoomTtl, bool suppressRoomEvents, const Common::JVector<Common::JString>* pPlugins, bool publishUserID, const Common::JVector<Common::JString>& expectedUsers);
				virtual void destroy(const MutableRoom* pRoom);
			private:
				friend class LoadBalancing::Client;
			};
		}
	}
}