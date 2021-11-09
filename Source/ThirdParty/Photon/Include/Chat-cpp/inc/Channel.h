/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Chat
	{
		namespace Internal
		{
			class ChannelFactory;
			class ChannelMessageAdder;
			class ChannelPropertiesSetter;
		}

		class Channel : public Common::ToString
		{
		public:
			using ToString::toString;

			void clearMessages(void);

			const Common::JString& getName(void) const;
			const int getID(void) const;
			unsigned int getMessageCount(void) const;
			const Common::JVector<Common::JString>& getSenders(void) const;
			const Common::JVector<Common::Object>& getMessages(void) const;
			bool getIsPrivate(void) const;
			const Common::Dictionary<Common::Object, Common::Object>& getCustomProperties() const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			Channel(const Common::JString& name, int id, bool isPrivate);
			void add(const Common::JString& sender, const Common::Object& message);
			void add(const Common::JVector<Common::JString>& senders, const Common::JVector<Common::Object>& messages);
			void readProperties(const Common::Dictionary<Common::Object, Common::Object>& props);

			Common::JString mName;
			int mID;
			Common::JVector<Common::JString> mSenders;
			Common::JVector<Common::Object> mMessages;
			Common::Dictionary<Common::Object, Common::Object> mCustomProperties;
			bool mIsPrivate;

			friend class Internal::ChannelFactory;
			friend class Internal::ChannelMessageAdder;
			friend class Internal::ChannelPropertiesSetter;
		};
	}
}