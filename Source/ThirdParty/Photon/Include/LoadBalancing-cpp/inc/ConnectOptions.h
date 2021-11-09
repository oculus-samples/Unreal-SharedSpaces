/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/AuthenticationValues.h"
#include "LoadBalancing-cpp/inc/Enums/ServerType.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class ConnectOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			ConnectOptions(const AuthenticationValues& authenticationValues=AuthenticationValues(), const Common::JString& username=Common::JString(L""), const Common::JString& serverAddress=Common::JString(M_NAMESERVER), nByte serverType=ServerType::NAME_SERVER, bool tryUseDatagramEncryption=false);
			~ConnectOptions(void);

			ConnectOptions(const ConnectOptions& toCopy);
			ConnectOptions& operator=(const ConnectOptions& toCopy);

			const AuthenticationValues& getAuthenticationValues(void) const;
			ConnectOptions& setAuthenticationValues(const AuthenticationValues& authenticationValues);
			const Common::JString& getUsername(void) const;
			ConnectOptions& setUsername(const Common::JString& username);
			const Common::JString& getServerAddress(void) const;
			ConnectOptions& setServerAddress(const Common::JString& serverAddress);
			nByte getServerType(void) const;
			ConnectOptions& setServerType(nByte serverType);
			bool getTryUseDatagramEncryption(void) const;
			ConnectOptions& setTryUseDatagramEncryption(bool tryUseDatagramEncryption);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			AuthenticationValues mAuthenticationValues;
			Common::JString mUsername;
			Common::JString mServerAddress;
			nByte mServerType;
			bool mTryUseDatagramEncryption;

			static const EG_CHAR* M_NAMESERVER;
		};
	}
}