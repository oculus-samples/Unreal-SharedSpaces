/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Photon
	{
		class TrafficStatsGameLevel : public Common::ToString
		{
		public:
			using ToString::toString;

			virtual ~TrafficStatsGameLevel(void);

			int getOperationByteCount(void) const;
			int getOperationCount(void) const;
			int getResultByteCount(void) const;
			int getResultCount(void) const;
			int getEventByteCount(void) const;
			int getEventCount(void) const;
			int getLongestOpResponseCallback(void) const;
			nByte getLongestOpResponseCallbackOpCode(void) const;
			int getLongestEventCallback(void) const;
			nByte getLongestEventCallbackCode(void) const;
			int getLongestDeltaBetweenDispatching(void) const;
			int getLongestDeltaBetweenSending(void) const;
			int getDispatchIncomingCommandsCalls(void) const;
			int getSendOutgoingCommandsCalls(void) const;
			int getTotalByteCount(void) const;
			int getTotalMessageCount(void) const;
			int getTotalIncomingByteCount(void) const;
			int getTotalIncomingMessageCount(void) const;
			int getTotalOutgoingByteCount(void) const;
			int getTotalOutgoingMessageCount(void) const;
			void resetMaximumCounters(void); // use PhotonPeer::resetTrafficStatsMaximumCounters() to call this on peer's stats
			
			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			virtual Common::JString toStringVitalStats(void) const;
		protected:
			TrafficStatsGameLevel(void);

			int mTimeOfLastDispatchCall;
			int mTimeOfLastSendCall;
			int mOperationByteCount;
			int mOperationCount;
			int mResultByteCount;
			int mResultCount;
			int mEventByteCount;
			int mEventCount;
			int mLongestOpResponseCallback;
			nByte mLongestOpResponseCallbackOpCode;
			int mLongestEventCallback;
			nByte mLongestEventCallbackCode;
			int mLongestDeltaBetweenDispatching;
			int mLongestDeltaBetweenSending;
			int mDispatchIncomingCommandsCalls;
			int mSendOutgoingCommandsCalls;
		};
	}
}