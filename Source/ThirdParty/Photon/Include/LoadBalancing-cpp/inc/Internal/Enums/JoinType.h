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
		namespace Internal
		{
			namespace JoinType
			{
				static const nByte CREATE_ROOM                = 255;
				static const nByte JOIN_OR_CREATE_ROOM        = 254;
				static const nByte JOIN_RANDOM_OR_CREATE_ROOM = 253;
				static const nByte JOIN_ROOM                  = 252;
				static const nByte JOIN_RANDOM_ROOM           = 251;
				static const nByte AUTO_JOIN_LOBBY            = 250;
				static const nByte EXPLICIT_JOIN_LOBBY        = 249;
			}
		}
	}
}