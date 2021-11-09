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
			namespace JoinMode
			{
				static const nByte DEFAULT              = 0;
				static const nByte CREATE_IF_NOT_EXISTS = 1;
				static const nByte JOIN_OR_REJOIN       = 2;
				static const nByte REJOIN_ONLY          = 3;
			}
		}
	}
}