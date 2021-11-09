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
		/** Possible states for a Client.*/
		namespace ClientState
		{
			static const int Uninitialized               = 0; ///<Peer is created but not used yet.
			static const int ConnectingToNameServer      = 1; ///<Connecting to Name Server (includes connect authenticate and joining the lobby)
			static const int ConnectedToNameServer       = 2; ///<Connected to Name Server.
			static const int Authenticating              = 3; ///<Authenticating.
			static const int Authenticated               = 4; ///<Authenticated.
			static const int DisconnectingFromNameServer = 5; ///<Transition from Name to Chat Server.
			static const int ConnectingToFrontEnd        = 6; ///<Transition to Chat Server.
			static const int ConnectedToFrontEnd         = 7; ///<Connected to Chat Server. Subscribe to channels and chat here.
			static const int Disconnecting               = 8; ///<The client disconnects (from any server).
			static const int Disconnected                = 9; ///<The client is no longer connected (to any server). Connect to Name Server to go on.
		}
		/** @file */
	}
}