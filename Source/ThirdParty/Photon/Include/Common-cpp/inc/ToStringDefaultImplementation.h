/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/ToString.h"

namespace ExitGames
{
	namespace Common
	{
		class ToStringDefaultImplementation : public ToString
		{
		public:
			using ToString::toString;

			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		};
	}
}