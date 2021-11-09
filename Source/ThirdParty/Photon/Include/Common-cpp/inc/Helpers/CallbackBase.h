/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Message.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class CallbackBase : public ToString
			{
			public:
				using ToString::toString;

				virtual void operator()(const Message& msg) = 0;

				virtual bool operator==(const CallbackBase& toCompare) const;
				virtual bool operator!=(const CallbackBase& toCompare) const;

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			};
		}
	}
}