/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/AssociativeContainerBase.h"
#include "Common-cpp/inc/JObject.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename T>
		class AssociativeContainer : public AssociativeContainerBase<T, JObject>
		{
		};



		/** @file */
	}
}