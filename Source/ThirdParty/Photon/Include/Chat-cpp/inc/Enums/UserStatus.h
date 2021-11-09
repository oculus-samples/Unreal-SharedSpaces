/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Chat
	{
		/**
			Contains commonly used status values for SetOnlineStatus. You can define your own.
			While "online" (value 2 and up), the status message will be sent to anyone who has you on his friend list.
			
			Define custom online status values as you like with these rules:
			0: Means "offline". It will be used when you are not connected. In this status, there is no status message.
			1: Means "invisible" and is sent to friends as "offline". They see status 0, no message but you can chat.
			2: And any higher value will be treated as "online". Status can be set.*/
		namespace UserStatus
		{
			static const int OFFLINE   = 0; ///<Offline.
			static const int INVISIBLE = 1; ///<Be invisible to everyone. Sends no message.
			static const int ONLINE    = 2; ///<Online and available.
			static const int AWAY      = 3; ///<Online but not available.
			static const int DND       = 4; ///<Do not disturb.
			static const int LFG       = 5; ///<Looking For Game/Group. Could be used when you want to be invited or do matchmaking.
			static const int PLAYING   = 6; ///<Could be used when in a room, playing.
		}
		/** @file */
	}
}