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
			namespace ParameterCode
			{
				/// (230) Address of a (game) server to use.
				static const nByte ADDRESS                              = 230;
				/// (225) User's ID
				static const nByte USER_ID                              = 225;
				static const nByte APPLICATION_ID                       = 224;
				/// (221) Secret token to identify an authorized user.
				static const nByte SECRET                               = 221;
				static const nByte APP_VERSION                          = 220;
				/// (217) This key's (byte) value defines the target custom authentication type/service the client connects with. Used in OpAuthenticate
				static const nByte CLIENT_AUTHENTICATION_TYPE           = 217;
				/// (216) This key's (string) value provides parameters sent to the custom authentication type/service the client connects with. Used in OpAuthenticate
				static const nByte CLIENT_AUTHENTICATION_PARAMETERS     = 216;
				/// (214) This key's (string or byte[]) value provides parameters sent to the custom authentication service setup in Photon Dashboard. Used in OpAuthenticate
				static const nByte CLIENT_AUTHENTICATION_DATA           = 214;
				/// (210) Used for region values in OpAuth and OpGetRegions.
				static const nByte REGION                               = 210;
				/// (29) Generated unique reusable channel id
				static const nByte CHANNEL_ID                           =  29;
				/// (22) Properties of a channel or a user.
				static const nByte PROPERTIES                            = 22;
				/// (15) Subscribe operation result parameter. A bool[] with result per channel.
				static const nByte SUBSCRIBE_RESULTS                    =  15;
				/// (14) Number of message to fetch from history. 0: no history. 1 and higher: number of messages in history. -1: all history.
				static const nByte HISTORY_LENGTH                       =  14;
				/// (12) SkipMessage is used in SetOnlineStatus and if true, the message is not being broadcast.
				static const nByte SKIP_MESSAGE                         =  12;
				/// (11) Friends.
				static const nByte FRIENDS                              =  11;
				/// (10) Status.
				static const nByte STATUS                               =  10;
				/// (9) Not used.
				static const nByte MSG_IDS                              =   9;
				/// (8) Id of a message.
				static const nByte MSG_ID                               =   8;
				/// (6) Not used.
				static const nByte CHANNEL_USER_COUNT                   =   6;
				/// (5) Name of a the user who sent a chat message.
				static const nByte SENDER                               =   5;
				/// (4) Array of names of the users who sent the array of chat messages.
				static const nByte SENDERS                              =   4;
				/// (3) A single chat message.
				static const nByte MESSAGE                              =   3;
				/// (2) Array of chat messages.
				static const nByte MESSAGES                             =   2;
				/// (1) Name of a single chat channel.
				static const nByte CHANNEL                              =   1;
				/// (0) Array of chat channels.
				static const nByte CHANNELS                             =   0;
			};
		}
	}
}