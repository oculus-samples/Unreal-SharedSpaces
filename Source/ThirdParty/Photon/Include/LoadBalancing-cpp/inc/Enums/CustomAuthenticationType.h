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
		/** Options for optional "Custom Authentication" services used with Photon. Used when the client sends an authentication request to the server.*/
		namespace CustomAuthenticationType
		{
			static const nByte CUSTOM          =  0; ///<Use a custom authentication service.
			static const nByte STEAM           =  1; ///<Authenticates users by their Steam Account. Set auth values accordingly!
			static const nByte FACEBOOK        =  2; ///<Authenticates users by their Facebook Account. Set auth values accordingly!
			static const nByte OCULUS          =  3; ///<Authenticates users by their Oculus Account. Set auth values accordingly!
			static const nByte PLAYSTATION_4   =  4; ///<Authenticates users by their PSN Account. Set auth values accordingly!
			static const nByte XBOX            =  5; ///<Authenticates users by their XBox Network Account. Set auth values accordingly!
			static const nByte NINTENDO_SWITCH = 11; ///<Authenticates users by their Nintendo Account. Set auth values accordingly!
			static const nByte PLAYSTATION_5   = 12; ///<Authenticates users by their PSN Account. Set auth values accordingly!
			static const nByte NONE            = UCHAR_MAX; ///<Disables custom authentication.
		}
		/** @file */
	}
}