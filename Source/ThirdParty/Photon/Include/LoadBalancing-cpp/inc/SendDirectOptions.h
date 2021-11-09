/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/Enums/EventCache.h"
#include "Photon-cpp/inc/Enums/ReceiverGroup.h"
#include "LoadBalancing-cpp/inc/WebFlags.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class SendDirectOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			SendDirectOptions(const Common::JVector<int>& targetPlayers=Common::JVector<int>(), bool fallbackRelay=false, nByte receiverGroup=Lite::ReceiverGroup::OTHERS);
			~SendDirectOptions(void);

			SendDirectOptions(const SendDirectOptions& toCopy);
			SendDirectOptions& operator=(const SendDirectOptions& toCopy);

			const Common::JVector<int>& getTargetPlayers(void) const;
			SendDirectOptions& setTargetPlayers(const Common::JVector<int>& targetPlayers);
			nByte getReceiverGroup(void) const;
			SendDirectOptions& setReceiverGroup(nByte receiverGroup);
			bool getFallbackRelay(void) const;
			SendDirectOptions& setFallbackRelay(bool fallbackRelay);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			Common::JVector<int> mTargetPlayers;
			bool mFallbackRelay;
			nByte mReceiverGroup;
		};
	}
}