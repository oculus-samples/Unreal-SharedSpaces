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
		/** Options of lobby types available. Lobby types might be implemented in certain Photon versions and won't be available on older servers.*/
		namespace LobbyType
		{
			
			static const nByte DEFAULT            = 0; ///<This lobby type is used unless another lobby type is specified. Room lists will be sent and Client::opJoinRandomRoom() can filter by matching properties.
			static const nByte SQL_LOBBY          = 2; ///<This lobby type lists rooms like type DEFAULT but  SQL-like "where" clauses for filtering can be used with Client::opJoinRandomRoom(). This allows 'bigger', 'less', 'or' and 'and' combinations.
			static const nByte ASYNC_RANDOM_LOBBY = 3; ///<This lobby does not send room lists. It is only used for Client::opJoinRandomRoom(). It keeps rooms available for matchmaking for a while even when there are only inactive users left.
		}
		/** @file */
	}
}