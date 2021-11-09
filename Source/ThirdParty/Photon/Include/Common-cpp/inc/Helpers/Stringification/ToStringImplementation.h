/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Stringification/ObjectToStringConverter.h"
#include "Common-cpp/inc/Helpers/Stringification/PrimitiveToStringConverter.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<bool isPrimitiveType, typename Etype>
			struct ToStringImplementation
			{
				static ObjectToStringConverter<Etype> converter;
			};

			template<bool isPrimitiveType, typename Etype>
			struct ToStringImplementation<isPrimitiveType, Etype*>
			{
				static ObjectToStringConverter<Etype*> converter;
			};

			template<typename Etype>
			struct ToStringImplementation<true, Etype>
			{
				static PrimitiveToStringConverter<Etype> converter;
			};

			template<typename Etype>
			struct ToStringImplementation<true, Etype*>
			{
				static PrimitiveToStringConverter<Etype*> converter;
			};

			template<bool isPrimitiveType, typename Etype> ObjectToStringConverter<Etype> ToStringImplementation<isPrimitiveType, Etype>::converter;
			template<bool isPrimitiveType, typename Etype> ObjectToStringConverter<Etype*> ToStringImplementation<isPrimitiveType, Etype*>::converter;
			template<typename Etype> PrimitiveToStringConverter<Etype> ToStringImplementation<true, Etype>::converter;
			template<typename Etype> PrimitiveToStringConverter<Etype*> ToStringImplementation<true, Etype*>::converter;
		}
	}
}