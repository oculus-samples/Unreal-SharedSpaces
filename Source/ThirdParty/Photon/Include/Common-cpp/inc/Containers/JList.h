/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/SequenceContainer.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename Etype>
		class JList : public SequenceContainer<JList, Etype>
		{
		public:
			JList(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JList(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JList(void);

			JList(const JList<Etype>& toCopy);
			template<template<typename> class FT> JList(const SequenceContainer<FT, Etype>& toCopy);
			virtual JList<Etype>& operator=(const SequenceContainer<Common::JList, Etype>& toCopy);
			template<template<typename> class FT> JList<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JList<Etype>& operator=(const JList<Etype>& rhv);
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JList<Etype>::JList(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JList, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JList<Etype>::JList(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JList, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JList<Etype>::~JList(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& toCopy) */
		template<typename Etype>
		JList<Etype>::JList(const JList<Etype>& toCopy) : SequenceContainer<Common::JList, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JList<Etype>::JList(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JList, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JList<Etype>& JList<Etype>::operator=(const SequenceContainer<Common::JList, Etype>& toCopy)
		{
			return this->assign(static_cast<const JList<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JList<Etype>& JList<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JList<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JList<Etype>& JList<Etype>::operator=(const JList<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}