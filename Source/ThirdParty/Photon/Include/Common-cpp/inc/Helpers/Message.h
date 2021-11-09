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
		namespace Helpers
		{
			class Message : public ToString
			{
			public:
				virtual size_t getTypeID(void) const = 0;
			};
		}
	}
}