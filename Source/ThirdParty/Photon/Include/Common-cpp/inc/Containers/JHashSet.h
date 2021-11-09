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
		class JHashSet : public SequenceContainer<JHashSet, Etype>
		{
		public:
			JHashSet(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JHashSet(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JHashSet(void);

			JHashSet(const JHashSet<Etype>& toCopy);
			template<template<typename> class FT> JHashSet(const SequenceContainer<FT, Etype>& toCopy);
			virtual JHashSet<Etype>& operator=(const SequenceContainer<Common::JHashSet, Etype>& toCopy);
			template<template<typename> class FT> JHashSet<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JHashSet<Etype>& operator=(const JHashSet<Etype>& rhv);
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JHashSet<Etype>::JHashSet(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JHashSet, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JHashSet<Etype>::JHashSet(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JHashSet, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JHashSet<Etype>::~JHashSet(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& toCopy) */
		template<typename Etype>
		JHashSet<Etype>::JHashSet(const JHashSet<Etype>& toCopy) : SequenceContainer<Common::JHashSet, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JHashSet<Etype>::JHashSet(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JHashSet, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JHashSet<Etype>& JHashSet<Etype>::operator=(const SequenceContainer<Common::JHashSet, Etype>& toCopy)
		{
			return this->assign(static_cast<const JHashSet<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JHashSet<Etype>& JHashSet<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JHashSet<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JHashSet<Etype>& JHashSet<Etype>::operator=(const JHashSet<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}