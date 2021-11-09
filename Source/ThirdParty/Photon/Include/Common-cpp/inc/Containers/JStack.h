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
		class JStack : public SequenceContainer<JStack, Etype>
		{
		public:
			JStack(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JStack(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JStack(void);

			JStack(const JStack<Etype>& toCopy);
			template<template<typename> class FT> JStack(const SequenceContainer<FT, Etype>& toCopy);
			virtual JStack<Etype>& operator=(const SequenceContainer<Common::JStack, Etype>& toCopy);
			template<template<typename> class FT> JStack<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JStack<Etype>& operator=(const JStack<Etype>& rhv);

			void push(const Etype& element);
			Etype pop(void);
			const Etype& peek(void);
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JStack<Etype>::JStack(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JStack, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JStack<Etype>::JStack(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JStack, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JStack<Etype>::~JStack(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& toCopy) */
		template<typename Etype>
		JStack<Etype>::JStack(const JStack<Etype>& toCopy) : SequenceContainer<Common::JStack, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JStack<Etype>::JStack(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JStack, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JStack<Etype>& JStack<Etype>::operator=(const SequenceContainer<Common::JStack, Etype>& toCopy)
		{
			return this->assign(static_cast<const JStack<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JStack<Etype>& JStack<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JStack<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JStack<Etype>& JStack<Etype>::operator=(const JStack<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}

		template<typename Etype>
		void JStack<Etype>::push(const Etype& element)
		{
			this->addElement(element);
		}

		template<typename Etype>
		Etype JStack<Etype>::pop(void)
		{
			Etype ret = this->getLastElement();
			this->removeElementAt(this->getSize()-1);
			return ret;
		}

		template<typename Etype>
		const Etype& JStack<Etype>::peek(void)
		{
			return this->getLastElement();
		}
	}
}