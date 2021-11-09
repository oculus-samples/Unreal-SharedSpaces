/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Stringification/ObjectToStringConverterBase.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype> class ObjectToStringConverter : public ObjectToStringConverterBase<Etype>{};
			template<typename Etype> class ObjectToStringConverter<Etype*> : public ObjectToStringConverterBase<Etype*>{};
		}
	}
}