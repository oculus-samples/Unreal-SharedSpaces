/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class FriendInfo : public Common::ToString
		{
		public:
			using ToString::toString;

			Common::JString getUserID(void) const;
			bool getIsOnline(void) const;
			Common::JString getRoom(void) const;
			bool getIsInRoom(void) const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			FriendInfo(const Common::JString& userID, bool isOnline=false, const Common::JString& room=Common::JString());

			Common::JString mUserID;
			bool mIsOnline;
			Common::JString mRoom;

			friend class Client;
		};
	}
}