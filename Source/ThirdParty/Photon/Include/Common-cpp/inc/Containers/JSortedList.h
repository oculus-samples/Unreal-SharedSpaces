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
		template<typename EKeyType, typename EValueType>
		class JSortedList : public GenericAssociativeContainer<JSortedList, EKeyType, EValueType>
		{
		public:
			JSortedList(void);
			virtual ~JSortedList(void);

			JSortedList(const JSortedList<EKeyType, EValueType>& toCopy);
			template<template<typename, typename> class FT> JSortedList(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);
			virtual JSortedList<EKeyType, EValueType>& operator=(const GenericAssociativeContainer<Common::JSortedList, EKeyType, EValueType>& toCopy);
			template<template<typename, typename> class FT> JSortedList<EKeyType, EValueType>& operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);
			virtual JSortedList<EKeyType, EValueType>& operator=(const JSortedList<EKeyType, EValueType>& toCopy);
		};



		/** @file */

		template<typename EKeyType, typename EValueType>
		JSortedList<EKeyType, EValueType>::JSortedList(void) : GenericAssociativeContainer<Common::JSortedList, EKeyType, EValueType>()
		{
		}

		template<typename EKeyType, typename EValueType>
		JSortedList<EKeyType, EValueType>::~JSortedList(void)
		{
		}

		template<typename EKeyType, typename EValueType>
		JSortedList<EKeyType, EValueType>::JSortedList(const JSortedList<EKeyType, EValueType>& toCopy) : GenericAssociativeContainer<Common::JSortedList, EKeyType, EValueType>(toCopy)
		{
		}

		template<typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT>
		JSortedList<EKeyType, EValueType>::JSortedList(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy) : GenericAssociativeContainer<Common::JSortedList, EKeyType, EValueType>(toCopy)
		{
		}

		template<typename EKeyType, typename EValueType>
		JSortedList<EKeyType, EValueType>& JSortedList<EKeyType, EValueType>::operator=(const GenericAssociativeContainer<Common::JSortedList, EKeyType, EValueType>& toCopy)
		{
			return this->assign(static_cast<const  JSortedList<EKeyType, EValueType>&>(toCopy));
		}

		template<typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT> JSortedList<EKeyType, EValueType>& JSortedList<EKeyType, EValueType>::operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy)
		{
			return *this = JSortedList<EKeyType, EValueType>(toCopy);
		}

		template<typename EKeyType, typename EValueType>
		JSortedList<EKeyType, EValueType>& JSortedList<EKeyType, EValueType>::operator=(const JSortedList<EKeyType, EValueType>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}