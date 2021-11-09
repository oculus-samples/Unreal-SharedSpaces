/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include <stddef.h>
#undef min
#undef max

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace MathHelper
			{
				size_t log2(size_t v);
				double rint(double x);
				double round(double x);
				template<typename T> const T& min(const T& a, const T& b);
				template<typename T> const T& max(const T& a, const T& b);
				template<typename T> const T& clamp(const T& value, const T& min, const T& max);
				template<template<typename> class TCollectionType, typename TElementType> const TElementType sum(const TCollectionType<TElementType>& collection);
				template<template<typename, typename> class TCollectionType, typename TKeyType, typename TValType> const TValType sum(const TCollectionType<TKeyType, TValType>& collection);



				template<typename T>
				const T& min(const T& a, const T& b)
				{
					return b<a?b:a;
				}

				template<typename T>
				const T& max(const T& a, const T& b)
				{
					return a<b?b:a;
				}

				template<typename T>
				const T& clamp(const T& value, const T& min, const T& max)
				{
					return value<min?min:value>max?max:value;
				}

				template<template<typename> class TCollectionType, typename TElementType>
				const TElementType sum(const TCollectionType<TElementType>& collection)
				{
					TElementType retVal = TElementType();
					for(unsigned int i=0; i<collection.getSize(); ++i)
						retVal += collection[i];
					return retVal;
				}

				template<template<typename, typename> class TCollectionType, typename TKeyType, typename TValType>
				const TValType sum(const TCollectionType<TKeyType, TValType>& collection)
				{
					TValType retVal = TValType();
					for(unsigned int i=0; i<collection.getSize(); ++i)
						retVal += collection[i];
					return retVal;
				}
			}
		}
	}
}