/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/IsClass.h"
#include "Common-cpp/inc/Helpers/TypeTraits/RemovePointer.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Ctype> struct IsPrimitiveType{static const bool is = !IsClass<typename RemovePointer<Ctype>::type>::is;};

			/** @file */
		}
	}
}