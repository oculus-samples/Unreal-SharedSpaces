/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"
#include "Photon-cpp/inc/Enums/OperationCode.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			namespace OperationCode
			{
				static const nByte LEAVE            = Lite::OperationCode::LEAVE;
				static const nByte RAISE_EVENT      = Lite::OperationCode::RAISE_EV;
				static const nByte SET_PROPERTIES   = Lite::OperationCode::SETPROPERTIES;
				static const nByte GET_PROPERTIES   = Lite::OperationCode::GETPROPERTIES;
				static const nByte CHANGE_GROUPS    = Lite::OperationCode::CHANGE_GROUPS;
				static const nByte AUTH_ONCE        = 231;
				static const nByte AUTHENTICATE     = 230;
				static const nByte JOIN_LOBBY       = 229;
				static const nByte LEAVE_LOBBY      = 228;
				static const nByte CREATE_ROOM      = 227;
				static const nByte JOIN_ROOM        = 226;
				static const nByte JOIN_RANDOM_ROOM = 225;
				static const nByte FIND_FRIENDS     = 222;
				static const nByte LOBBY_STATS      = 221;
				static const nByte GET_REGIONS      = 220;
				static const nByte RPC              = 219;
				static const nByte GET_ROOM_LIST    = 217;
			}
		}
	}
}