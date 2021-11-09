/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Enums/CustomAuthenticationType.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			class AuthenticationValuesSecretSetter;
		}

		class AuthenticationValues : public Common::ToString
		{
		public:
			using ToString::toString;

			AuthenticationValues(void);

			nByte getType(void) const;
			AuthenticationValues& setType(nByte type);
			const Common::JString& getParameters(void) const;
			AuthenticationValues& setParameters(const Common::JString& parameters);
			AuthenticationValues& setParametersWithUsernameAndToken(const Common::JString& username, const Common::JString& token);
			const Common::Object& getData(void) const;
			AuthenticationValues& setData(const Common::JVector<nByte>& data);
			AuthenticationValues& setData(const Common::JString& data);
			AuthenticationValues& setData(const Common::Dictionary<Common::JString, Common::Object>& data);
			const Common::JString& getSecret(void) const;
			const Common::JString& getUserID(void) const;
			AuthenticationValues& setUserID(const Common::JString& userID);
			
			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			AuthenticationValues& setSecret(const Common::JString& secret);

			nByte mType;
			Common::JString mParameters;
			Common::Object mData;
			Common::JString mSecret;
			Common::JString mUserID;

			friend class Internal::AuthenticationValuesSecretSetter;
		};
	}
}