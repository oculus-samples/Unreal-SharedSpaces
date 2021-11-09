/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Chat
	{
		namespace Internal
		{
			namespace EventCode
			{
				static const nByte CHAT_MESSAGES        = 0;
				static const nByte USERS                = 1;
				static const nByte PRIVATE_MESSAGE      = 2;
				static const nByte FRIEND_LIST          = 3;
				static const nByte STATUS_UPDATE        = 4;
				static const nByte SUBSCRIBE            = 5;
				static const nByte UNSUBSCRIBE          = 6;
			};
		}
	}
}