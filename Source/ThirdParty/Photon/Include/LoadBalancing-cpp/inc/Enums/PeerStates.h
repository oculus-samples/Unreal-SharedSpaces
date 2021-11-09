/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace PeerStates
		{
			static const int Uninitialized                              =  0;
			static const int PeerCreated                                =  1;
			static const int ConnectingToNameserver                     =  2;
			static const int ConnectedToNameserver                      =  3;
			static const int DisconnectingFromNameserver                =  4;
			static const int Connecting                                 =  5;
			static const int Connected                                  =  6;
			static const int WaitingForCustomAuthenticationNextStepCall =  7;
			static const int Authenticated                              =  8;
			static const int JoinedLobby                                =  9;
			static const int DisconnectingFromMasterserver              = 10;
			static const int ConnectingToGameserver                     = 11;
			static const int ConnectedToGameserver                      = 12;
			static const int AuthenticatedOnGameServer                  = 13;
			static const int Joining                                    = 14;
			static const int Joined                                     = 15;
			static const int Leaving                                    = 16;
			static const int Left                                       = 17;
			static const int DisconnectingFromGameserver                = 18;
			static const int ConnectingToMasterserver                   = 19;
			static const int ConnectedComingFromGameserver              = 20;
			static const int AuthenticatedComingFromGameserver          = 21;
			static const int Disconnecting                              = 22;
			static const int Disconnected                               = 23;
		}
		/** @file */
	}
}