/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsFloatingPoint.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsIntegral.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Ctype> struct IsArithmetic{static const bool is = IsIntegral<Ctype>::is || IsFloatingPoint<Ctype>::is;};

			/** @file */
		}
	}
}