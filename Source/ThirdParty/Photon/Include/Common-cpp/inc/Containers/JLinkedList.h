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
		class JLinkedList : public SequenceContainer<JLinkedList, Etype>
		{
		public:
			JLinkedList(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JLinkedList(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JLinkedList(void);

			JLinkedList(const JLinkedList<Etype>& toCopy);
			template<template<typename> class FT> JLinkedList(const SequenceContainer<FT, Etype>& toCopy);
			virtual JLinkedList<Etype>& operator=(const SequenceContainer<Common::JLinkedList, Etype>& toCopy);
			template<template<typename> class FT> JLinkedList<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JLinkedList<Etype>& operator=(const JLinkedList<Etype>& rhv);
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JLinkedList<Etype>::JLinkedList(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JLinkedList, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JLinkedList<Etype>::JLinkedList(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JLinkedList, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JLinkedList<Etype>::~JLinkedList(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& toCopy) */
		template<typename Etype>
		JLinkedList<Etype>::JLinkedList(const JLinkedList<Etype>& toCopy) : SequenceContainer<Common::JLinkedList, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JLinkedList<Etype>::JLinkedList(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JLinkedList, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JLinkedList<Etype>& JLinkedList<Etype>::operator=(const SequenceContainer<Common::JLinkedList, Etype>& toCopy)
		{
			return this->assign(static_cast<const JLinkedList<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JLinkedList<Etype>& JLinkedList<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JLinkedList<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JLinkedList<Etype>& JLinkedList<Etype>::operator=(const JLinkedList<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}