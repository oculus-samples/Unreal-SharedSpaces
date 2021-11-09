/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsClass.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsReference.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsVoid.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace IsFunctionsImplementation{struct dummyType {}; template<typename Ctype> char test(Ctype*); template<typename Ctype> char test(dummyType); struct two{char c[2];}; template <typename Ctype> two test(...); template<typename Ctype> Ctype& source(int); template<typename Ctype> dummyType source(...);}
			template<typename Ctype> struct IsFunction{static const bool is = !IsClass<Ctype>::is && !IsUnion<Ctype>::is && !IsVoid<Ctype>::is && !IsReference<Ctype>::is && sizeof(IsFunctionsImplementation::test<Ctype>(IsFunctionsImplementation::source<Ctype>(0))) == 1;};

			/** @file */
		}
	}
}