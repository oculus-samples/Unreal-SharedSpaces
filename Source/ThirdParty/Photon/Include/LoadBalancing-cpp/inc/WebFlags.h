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
		class WebFlags : public Common::ToString
		{
		public:
			using ToString::toString;

			WebFlags(nByte webFlags=0);

			nByte getFlags(void) const;
			WebFlags& setFlags(nByte webFlags);
			bool getHttpForward(void) const;
			WebFlags& setHttpForward(bool httpWebForward);
			bool getSendAuthCookie(void) const;
			WebFlags& setSendAuthCookie(bool sendAuthCookie);
			bool getSendSync(void) const;
			WebFlags& setSendSync(bool sendSync);
			bool getSendState(void) const;
			WebFlags& setSendState(bool sendState);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			nByte mWebFlags;

			static const nByte M_HTTP_FORWARD = 0x01;
			static const nByte M_SEND_AUTH_COOKIE = 0x02;
			static const nByte M_SEND_SYNC = 0x04;
			static const nByte M_SEND_STATE = 0x08;
		};
	}
}