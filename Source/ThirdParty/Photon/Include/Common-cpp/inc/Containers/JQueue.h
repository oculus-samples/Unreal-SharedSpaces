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
		class JQueue : public SequenceContainer<JQueue, Etype>
		{
		public:
			JQueue(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JQueue(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JQueue(void);

			JQueue(const JQueue<Etype>& toCopy);
			template<template<typename> class FT> JQueue(const SequenceContainer<FT, Etype>& toCopy);
			virtual JQueue<Etype>& operator=(const SequenceContainer<Common::JQueue, Etype>& toCopy);
			template<template<typename> class FT> JQueue<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JQueue<Etype>& operator=(const JQueue<Etype>& rhv);

			void enqueue(const Etype& element);
			Etype dequeue(void);
			const Etype& peek(void) const;
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JQueue<Etype>::JQueue(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JQueue, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JQueue<Etype>::JQueue(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JQueue, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JQueue<Etype>::~JQueue(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& rhv) */
		template<typename Etype>
		JQueue<Etype>::JQueue(const JQueue<Etype>& toCopy) : SequenceContainer<Common::JQueue, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JQueue<Etype>::JQueue(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JQueue, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JQueue<Etype>& JQueue<Etype>::operator=(const SequenceContainer<Common::JQueue, Etype>& toCopy)
		{
			return this->assign(static_cast<const JQueue<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JQueue<Etype>& JQueue<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JQueue<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JQueue<Etype>& JQueue<Etype>::operator=(const JQueue<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}

		template<typename Etype>
		void JQueue<Etype>::enqueue(const Etype& element)
		{
			this->addElement(element);
		}

		template<typename Etype>
		Etype JQueue<Etype>::dequeue(void)
		{
			Etype ret = this->getFirstElement();
			this->removeElementAt(0);
			return ret;
		}

		template<typename Etype>
		const Etype& JQueue<Etype>::peek(void) const
		{
			return this->getFirstElement();
		}
	}
}