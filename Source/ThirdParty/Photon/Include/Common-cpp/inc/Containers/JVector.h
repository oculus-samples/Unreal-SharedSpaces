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
		/**
		   This is a C++ implementation of the <i>Vector</i> Container
		   class from Sun Java.
		   @details
		   This class is based on the Java Vector class and as such
		   contains all the public member functions of its Java
		   equivalent. Unlike Java, typecasts are not necessary since
		   C++ allows template instantiation of types at compile time.
		   In addition to the Java public member functions, some
		   operators were also added in order to take advantage of the
		   operator overloading feature available in C++. */
		template<typename Etype>
		class JVector : public SequenceContainer<JVector, Etype>
		{
		public:
			JVector(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JVector(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JVector(void);

			JVector(const JVector<Etype>& toCopy);
			template<template<typename> class FT> JVector(const SequenceContainer<FT, Etype>& toCopy);
			virtual JVector<Etype>& operator=(const SequenceContainer<Common::JVector, Etype>& toCopy);
			template<template<typename> class FT> JVector<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JVector<Etype>& operator=(const JVector<Etype>& rhv);
		};



		/** @file */

		/** @copydoc JArray::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JVector<Etype>::JVector(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JVector, Etype>(initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc JArray::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) */
		template<typename Etype>
		JVector<Etype>::JVector(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JVector, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}
	
		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JVector<Etype>::~JVector(void)
		{
		}

		/** @copydoc JArray::JArray(const JArray<Etype>& toCopy) */
		template<typename Etype>
		JVector<Etype>::JVector(const JVector<Etype>& toCopy) : SequenceContainer<Common::JVector, Etype>(toCopy)
		{
		}

		/** @copydoc JArray::JArray(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JVector<Etype>::JVector(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JVector, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JVector<Etype>& JVector<Etype>::operator=(const SequenceContainer<Common::JVector, Etype>& toCopy)
		{
			return this->assign(static_cast<const JVector<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JVector<Etype>& JVector<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JVector<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JVector<Etype>& JVector<Etype>::operator=(const JVector<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}