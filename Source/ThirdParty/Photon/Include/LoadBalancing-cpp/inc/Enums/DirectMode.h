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
		/** Options for optional client to client direct connections - set in RoomOptions during room creation.*/
		namespace DirectMode
		{
			static const nByte NONE              = 0; ///<Do not create any 2p2 connections between the clients. This is the default.
#ifndef _EG_EMSCRIPTEN_PLATFORM
			static const nByte ALL_TO_OTHERS     = 1; ///<Each client establishes a direct connection with every other client inside the room.
			static const nByte MASTER_TO_OTHERS  = 2; ///<The master client establishes a direct connection with every other client inside the room. All other clients only establish a direct connection with the master client but not with each other.
			static const nByte ALL_TO_ALL        = 3; ///<Each client establishes a direct connection with every client inside the room, including itself.
			static const nByte MASTER_TO_ALL     = 4; ///<The master client establishes a direct connection with every client inside the room, including itself. All other clients only establish a direct connection with the master client but not with each other.
#endif
		}
		/** @file */
	}
}