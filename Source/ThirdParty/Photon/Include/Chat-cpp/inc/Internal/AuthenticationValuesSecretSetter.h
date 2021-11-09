/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Common
	{
		class JString;
	}

	namespace Chat
	{
		class AuthenticationValues;
		class Client;

		namespace Internal
		{
			class AuthenticationValuesSecretSetter
			{
				static void setSecret(AuthenticationValues& authenticationValues, const Common::JString& secret);

				friend class Chat::Client;
			};
		}
	}
}