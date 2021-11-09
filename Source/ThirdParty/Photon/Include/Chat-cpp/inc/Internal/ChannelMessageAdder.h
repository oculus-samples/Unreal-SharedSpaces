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
		template<typename Etype> class JVector;
		class Object;
	}

	namespace Chat
	{
		class Client;

		namespace Internal
		{
			class ChannelMessageAdder
			{
				static void add(Channel& channel, const Common::JString& sender, const Common::Object& message);
				static void add(Channel& channel, const Common::JVector<Common::JString>& senders, const Common::JVector<Common::Object>& messages);

				friend class Chat::Client;
			};
		}
	}
}