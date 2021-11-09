/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsArithmetic.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsEnum.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Ctype> struct IsScalar{static const bool is = IsArithmetic<Ctype>::is || IsMemberPointer<Ctype>::is || IsPointer<Ctype>::is || IsEnum<Ctype>::is;};

			/** @file */
		}
	}
}