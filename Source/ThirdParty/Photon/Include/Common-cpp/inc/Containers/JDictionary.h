/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/GenericAssociativeContainer.h"

namespace ExitGames
{
	namespace Common
	{
		/** @class JDictionary
		   @details
		   This class implements the well-known concept of a container structure storing an arbitrary number of key/value-pairs.

		   In contrast to a JHashtable, the types of both the keys and also the values in a JDictionary have to be the same for all
		   entries.
		   This takes flexibility, but it also improves type safety and means, that the type infos only have to be stored twice 
		   for the whole JDictionary (once for the key and once for the value), while in a Hashtable they have to be stored twice per
		   entry.
		   Therefor with JDictionaries storing the same amount of key-value pairs will cause less memory than with JHashtables.

		   Please refer to the documentation for put() and getValue() to see how to store and access data in a JDictionary.
		   @sa
		   put(), getValue(), JHashtable */
		template<typename EKeyType, typename EValueType>
		class JDictionary : public GenericAssociativeContainer<JDictionary, EKeyType, EValueType>
		{
		public:
			JDictionary(void);
			virtual ~JDictionary(void);

			JDictionary(const JDictionary<EKeyType, EValueType>& toCopy);
			template<template<typename, typename> class FT> JDictionary(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);
			virtual JDictionary<EKeyType, EValueType>& operator=(const GenericAssociativeContainer<Common::JDictionary, EKeyType, EValueType>& toCopy);
			template<template<typename, typename> class FT> JDictionary<EKeyType, EValueType>& operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);
			virtual JDictionary<EKeyType, EValueType>& operator=(const JDictionary<EKeyType, EValueType>& toCopy);
		};



		/** @file */

		template<typename EKeyType, typename EValueType>
		JDictionary<EKeyType, EValueType>::JDictionary(void) : GenericAssociativeContainer<Common::JDictionary, EKeyType, EValueType>()
		{
		}

		template<typename EKeyType, typename EValueType>
		JDictionary<EKeyType, EValueType>::~JDictionary(void)
		{
		}

		template<typename EKeyType, typename EValueType>
		JDictionary<EKeyType, EValueType>::JDictionary(const JDictionary<EKeyType, EValueType>& toCopy) : GenericAssociativeContainer<Common::JDictionary, EKeyType, EValueType>(toCopy)
		{
		}

		template<typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT>
		JDictionary<EKeyType, EValueType>::JDictionary(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy) : GenericAssociativeContainer<Common::JDictionary, EKeyType, EValueType>(toCopy)
		{
		}

		template<typename EKeyType, typename EValueType>
		JDictionary<EKeyType, EValueType>& JDictionary<EKeyType, EValueType>::operator=(const GenericAssociativeContainer<Common::JDictionary, EKeyType, EValueType>& toCopy)
		{
			return this->assign(static_cast<const JDictionary<EKeyType, EValueType>&>(toCopy));
		}

		template<typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT> JDictionary<EKeyType, EValueType>& JDictionary<EKeyType, EValueType>::operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy)
		{
			return *this = JDictionary<EKeyType, EValueType>(toCopy);
		}

		template<typename EKeyType, typename EValueType>
		JDictionary<EKeyType, EValueType>& JDictionary<EKeyType, EValueType>::operator=(const JDictionary<EKeyType, EValueType>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}