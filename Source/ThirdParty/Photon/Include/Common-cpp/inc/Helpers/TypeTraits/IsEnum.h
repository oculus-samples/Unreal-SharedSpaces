/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsArray.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsFunction.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsFloatingPoint.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsIntegral.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsMemberPointer.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsPointer.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Ctype> struct IsEnum{static const bool is = !IsVoid<Ctype>::is && !IsIntegral<Ctype>::is && !IsFloatingPoint<Ctype>::is && !IsArray<Ctype>::is && !IsPointer<Ctype>::is && !IsReference<Ctype>::is && !IsMemberPointer<Ctype>::is && !IsUnion<Ctype>::is && !IsClass<Ctype>::is && !IsFunction<Ctype>::is;};

			/** @file */
		}
	}
}