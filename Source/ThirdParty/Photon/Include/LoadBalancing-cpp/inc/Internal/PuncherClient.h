/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/Punchthrough/Puncher.h"
#include "Photon-cpp/inc/Punchthrough/PunchListener.h"
#include "Photon-cpp/inc/Punchthrough/RelayClient.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Client;
		class Listener;

		namespace Internal
		{
			class PuncherClient : private Photon::Punchthrough::RelayClient, private Photon::Punchthrough::PunchListener
			{
			public:			
				PuncherClient(Client& client, Listener& listener, const Common::Logger& logger);
				virtual ~PuncherClient(void);
				bool initPuncher(void);
				bool startPunch(int playerNr);
				bool sendDirect(const Common::JVector<nByte>& buffer, int targetID, bool fallbackRelay);
				int sendDirect(const Common::JVector<nByte>& buffer, const Common::JVector<int>& targetIDs, bool fallbackRelay);
				void service(void);
				bool processRelayPackage(const Common::JVector<nByte>& packet, int remoteID);
			private:			
				Photon::Punchthrough::Puncher* mpPuncher;
				Client& mLoadBalancingClient;
				Listener& mLoadBalancingListener;
				const Common::Logger& mLogger;
				// PunchListener
				virtual void onDirectConnectionEstablished(int remoteID);
				virtual void onDirectConnectionFailedToEstablish(int /*remoteID*/);
				virtual void onReceiveDirect(const Common::JVector<nByte>& buffer, int remoteID, bool relay);
				// RelayClient
				virtual int getLocalID(void);
				virtual bool sendRelay(const Common::JVector<nByte>& buffer, const Common::JVector<int>& targetIDs);
			};
		}
	}
}