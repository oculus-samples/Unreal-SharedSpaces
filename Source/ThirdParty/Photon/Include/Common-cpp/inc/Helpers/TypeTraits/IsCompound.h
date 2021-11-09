/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsFundamental.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Ctype> struct IsCompound{static const bool is = !IsFundamental<Ctype>::is;};

			/** @file */
		}
	}
}