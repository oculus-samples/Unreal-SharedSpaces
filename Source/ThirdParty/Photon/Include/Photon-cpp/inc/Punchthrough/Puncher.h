#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace Punchthrough
			{
				class PunchConn;
				class SocketImplementation;

				namespace Forwards
				{
					class StunMsgType;
					struct SockaddrIn;
					class PunchConnState;
				}
			}
		}

		namespace Punchthrough
		{
			class PunchListener;
			class RelayClient;

			class Puncher
			{			
			public:
				Puncher(RelayClient* pRelayClient, const Common::Logger& logger);
				virtual ~Puncher(void);

				bool init(PunchListener* pPunchListener);
				void clear(void);

				bool startPunch(int remoteID);
				bool sendDirect(const Common::JVector<nByte>& buffer, int targetID, bool fallbackRelay);
				int sendDirect(const Common::JVector<nByte>& buffer, const Common::JVector<int>& targetIDs, bool fallbackRelay);

				bool processRelayPackage(const Common::JVector<nByte>& packet, int relayRemoteID);
				void service(void);						
			private:
				const Internal::Punchthrough::Forwards::SockaddrIn* getEndpoint(int remoteID);			
				bool getIsPunch(const Common::JVector<nByte>& packet);
				bool processPackage(const Common::JVector<nByte>& packet, bool relay, const Internal::Punchthrough::Forwards::SockaddrIn& directRemoteAddr, int relayRemoteID);
				bool processPunchPackage(const Common::JVector<nByte>& packet, const Internal::Punchthrough::Forwards::SockaddrIn& remoteAddr);
				void socketService(void);
				// working with mConnections container
				bool hasConnection(int remoteID) const;
				Internal::Punchthrough::PunchConn* findConnection(int remoteID);
				Internal::Punchthrough::PunchConn* insertConnection(const Internal::Punchthrough::PunchConn& conn);
				bool removeConnection(int remoteID);
				void setConnectionState(Internal::Punchthrough::PunchConn& conn, Internal::Punchthrough::Forwards::PunchConnState state);

				// :: Handlers
				void handlerOffer(int idIncoming, const Internal::Punchthrough::Forwards::SockaddrIn& addrIncomingIntern, const Internal::Punchthrough::Forwards::SockaddrIn& addrIncomingExtern);
				void handlerAnswer(int idIncoming, const Internal::Punchthrough::Forwards::SockaddrIn& addrIncomingIntern, const Internal::Punchthrough::Forwards::SockaddrIn& addrIncomingExtern);

				void handlerPing(int idIncoming, const Internal::Punchthrough::Forwards::SockaddrIn& remoteAddr);
				void handlerPong(int idIncoming, const Internal::Punchthrough::Forwards::SockaddrIn& remoteAddr);

				// :: Senders
				bool sendOffer(int remoteid);
				bool sendAnswer(int remoteid);
				bool sendPing(Internal::Punchthrough::PunchConn& conn);
				bool sendPong(Internal::Punchthrough::PunchConn& conn, const Internal::Punchthrough::Forwards::SockaddrIn& remoteAddr);
				bool sendStunRelay(int remoteid, Internal::Punchthrough::Forwards::StunMsgType stunMsgType, const nByte* pMsgID);
				bool sendStunDirect(const Internal::Punchthrough::PunchConn& conn, const Internal::Punchthrough::Forwards::SockaddrIn& remoteAddr, Internal::Punchthrough::Forwards::StunMsgType stunMsgType, const nByte* pMsgID);

				bool sendRelay(const Common::JVector<nByte>& buffer, const Common::JVector<int>& targetIDs);

				// :: Builders
				Common::JVector<nByte> buildMsgBindingRequest(void);
				Common::JVector<nByte> buildStunImplementation(const Internal::Punchthrough::PunchConn* pConn, nByte id, Internal::Punchthrough::Forwards::StunMsgType stunMsgType, const nByte* pMsgID);

				// :: EndPoint Utils
				const Internal::Punchthrough::Forwards::SockaddrIn& getLocalEndpoint(void);
				void acquireExternalEndpoint(void);

				static const Common::JString addrToStr(const Internal::Punchthrough::Forwards::SockaddrIn& addr);

				Internal::Punchthrough::SocketImplementation* mpSocket;
				RelayClient* mpRelayClient;
				PunchListener* mpPunchListener;

				const Common::Logger& mLogger;

				Common::Helpers::UniquePointer<Internal::Punchthrough::Forwards::SockaddrIn> mupClientExternAddr;
				bool mValidExternalAddr;

				// Connections
				Common::Helpers::UniquePointer<Common::JVector<Internal::Punchthrough::PunchConn> > mupConnections;

				static const nByte mMsgBindingID[12];
				static const nByte mMsgRequestID[12];
				static const nByte mMsgResponseID[12];
				static const nByte mUserMsgByte0;
			};
		}
	}
}