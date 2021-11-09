/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsUnion.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace IsClassImplementation{template<typename Ctype> char test(int Ctype::*); struct two{char c[2];}; template<typename Ctype> two test(...);}
			template<typename Ctype> struct IsClass{static const bool is = sizeof(IsClassImplementation::test<Ctype>(0)) == 1 && !IsUnion<Ctype>::is;};

			/** @file */
		}
	}
}