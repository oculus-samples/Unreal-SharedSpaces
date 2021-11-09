/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Photon
	{
		namespace PeerState
		{
			static const int DISCONNECTED             = 0; ///<The peer is disconnected and can't call Operations. Call PhotonPeer_connect().
			static const int CONNECTING               = 1; ///<The peer is establishing the connection: opening a socket, exchanging packages with Photon.
			static const int INITIALIZING_APPLICATION = 2; ///<The connection is established and now sends the application name to Photon. You set the "application name" by calling PhotonPeer_connect().
			static const int CONNECTED                = 3; ///<The peer is connected and initialized (selected an application). You can now use operations.
			static const int DISCONNECTING            = 4; ///<The peer is disconnecting. It sent a disconnect to the server, which will acknowledge closing the connection.
		}
		/** @file */
	}
}