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
		class RaiseEventOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			RaiseEventOptions(nByte channelID=0, nByte eventCaching=Lite::EventCache::DO_NOT_CACHE, const int* targetPlayers=NULL, short numTargetPlayers=0, nByte receiverGroup=Lite::ReceiverGroup::OTHERS, nByte interestGroup=0, const WebFlags& webFlags=WebFlags(), int cacheSliceIndex=0);
			~RaiseEventOptions(void);

			RaiseEventOptions(const RaiseEventOptions& toCopy);
			RaiseEventOptions& operator=(const RaiseEventOptions& toCopy);

			nByte getChannelID(void) const;
			RaiseEventOptions& setChannelID(nByte channelID);
			nByte getEventCaching(void) const;
			RaiseEventOptions& setEventCaching(nByte eventCaching);
			const int* getTargetPlayers(void) const;
			short getNumTargetPlayers(void) const;
			RaiseEventOptions& setTargetPlayers(const int* targetPlayers, short numTargetPlayers);
			nByte getReceiverGroup(void) const;
			RaiseEventOptions& setReceiverGroup(nByte receiverGroup);
			nByte getInterestGroup(void) const;
			RaiseEventOptions& setInterestGroup(nByte interestGroup);
			const WebFlags& getWebFlags(void) const;
			RaiseEventOptions& setWebFlags(const WebFlags& webFlags);
			int getCacheSliceIndex(void) const;
			RaiseEventOptions& setCacheSliceIndex(int cacheSliceIndex);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			nByte mChannelID;
			nByte mEventCaching;
			Common::JVector<int> mTargetPlayers;
			nByte mReceiverGroup;
			nByte mInterestGroup;
			WebFlags mWebFlags;
			int mCacheSliceIndex;
		};
	}
}