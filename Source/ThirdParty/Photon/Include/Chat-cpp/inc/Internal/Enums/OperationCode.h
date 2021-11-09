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
			namespace OperationCode
			{
				/// (230) Operation Authenticate.
				static const nByte AUTHENTICATE       = 230;
				/// (0) Operation to subscribe to chat channels.
				static const nByte SUBSCRIBE            = 0;
				/// (1) Operation to unsubscribe from chat channels.
				static const nByte UNSUBSCRIBE          = 1;
				/// (2) Operation to publish a message in a chat channel.
				static const nByte PUBLISH              = 2;
				/// (3) Operation to send a private message to some other user.
				static const nByte SEND_PRIVATE         = 3;
				// Not used yet.
				static const nByte CHANNEL_HISTORY      = 4;
				/// (5) Set your (client's) status.
				static const nByte UPDATE_STATUS        = 5;
				/// (6) Adds users to the list that should update you of their status.
				static const nByte ADD_FRIENDS          = 6;
				/// (7) Removes users from the list that should update you of their status.
				static const nByte REMOVE_FRIENDS       = 7;
			}
		}
	}
}