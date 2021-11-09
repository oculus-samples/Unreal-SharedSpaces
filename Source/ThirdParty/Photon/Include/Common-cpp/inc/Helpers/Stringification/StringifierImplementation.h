/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/JString.h"
#include "Common-cpp/inc/Helpers/Stringification/ToStringImplementation.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsPrimitiveType.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T, bool isSmartPointer>
			struct StringifierImplementation
			{
				static JString toString(const T& data);
				static JString toString(const T* dataArray, unsigned int elementCount);
			};

			template<typename T>
			struct StringifierImplementation<T, true>
			{
				static JString toString(const T& data);
				static JString toString(const T* dataArray, unsigned int elementCount);
			};



			template<typename T, bool isSmartPointer>
			JString StringifierImplementation<T, isSmartPointer>::toString(const T& data)
			{
				return ToStringImplementation<IsPrimitiveType<T>::is, T>::converter.toString(data);
			}

			template<typename T, bool isSmartPointer>
			JString StringifierImplementation<T, isSmartPointer>::toString(const T* dataArray, unsigned int elementCount)
			{
				return ToStringImplementation<IsPrimitiveType<T>::is, T>::converter.toString(dataArray, elementCount);
			}

			template<typename T>
			JString StringifierImplementation<T, true>::toString(const T& data)
			{
				return ToStringImplementation<IsPrimitiveType<typename T::type>::is, T>::converter.toString(data);
			}

			template<typename T>
			JString StringifierImplementation<T, true>::toString(const T* dataArray, unsigned int elementCount)
			{
				return ToStringImplementation<IsPrimitiveType<typename T::type>::is, T>::converter.toString(dataArray, elementCount);
			}
		}
	}
}