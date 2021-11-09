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
		class JArray : public SequenceContainer<JArray, Etype>
		{
		public:
			JArray(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			virtual ~JArray(void);

			JArray(const JArray<Etype>& toCopy);
			template<template<typename> class FT> JArray(const SequenceContainer<FT, Etype>& toCopy);
			virtual JArray<Etype>& operator=(const SequenceContainer<Common::JArray, Etype>& toCopy);
			template<template<typename> class FT> JArray<Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);
			virtual JArray<Etype>& operator=(const JArray<Etype>& rhv);
		};



		/** @file */
		
		/**
		   Constructor.
	   
		   Creates an empty container instance of elements of the type of the template parameter.
		   @param initialCapacity the amount of elements, the container instance can take without need for resize. If you choose this too small, the container instance needs expensive resizes later (it's most likely, that the complete memory has to be copied to a new
		   location on resize), if you choose it too big, you will waste much memory. The default is 0.
		   @param capacityIncrement  Every time, when one adds an element to the Vector and it has no capacity left anymore, it's capacity will grow with this amount of elements on automatic resize. If you pass a too small value here, expensive resizes will be needed more
		   often, if you choose a too big one, possibly memory is wasted. The default is 1.  */
		template<typename Etype>
		JArray<Etype>::JArray(unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JArray, Etype>(initialCapacity, capacityIncrement)
		{
		}
		
		/**
		   Constructor.
	   
		   Creates a container instance, initialized with the passed carray of elements of the type of the template parameter.
		   @param carray all elements of this array up to elementCount will get copied into the constructed instance
		   @param elementCount shall not be greater than the actual element count of carray or undefined behavior will occur
		   @param initialCapacity the amount of elements, the container instance can take without need for resize. Defaults to the value that gets passed for elementCount. If you choose this too small, the container instance needs expensive resizes later (it's most
		   likely, that the complete memory has to be copied to a new location on resize), if you choose it too big, you will waste much memory.
		   @param capacityIncrement Every time, when one adds an element to the container and it has no capacity left anymore, it's capacity will grow with this amount of elements on automatic resize. If you pass a too small value here, expensive resizes will be needed more
		   often, if you choose a too big one, possibly memory is wasted. The default is 1. */
		template<typename Etype>
		JArray<Etype>::JArray(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement) : SequenceContainer<Common::JArray, Etype>(carray, elementCount, initialCapacity, capacityIncrement)
		{
		}

		/** @copydoc SequenceContainer::~SequenceContainer(void) */
		template<typename Etype>
		JArray<Etype>::~JArray(void)
		{
		}
		
		/**
		   Copy-Constructor.

		   Creates an object out of a deep copy of its parameter.

		   @param toCopy The object to copy. */
		template<typename Etype>
		JArray<Etype>::JArray(const JArray<Etype>& toCopy) : SequenceContainer<Common::JArray, Etype>(toCopy)
		{
		}
		
		/** @overload */
		template<typename Etype>
		template<template<typename> class FT>
		JArray<Etype>::JArray(const SequenceContainer<FT, Etype>& toCopy) : SequenceContainer<Common::JArray, Etype>(toCopy)
		{
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JArray<Etype>& JArray<Etype>::operator=(const SequenceContainer<Common::JArray, Etype>& toCopy)
		{
			return this->assign(static_cast<const JArray<Etype>&>(toCopy));
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<FT, Etype>& toCopy) */
		template<typename Etype>
		template<template<typename> class FT>
		JArray<Etype>& JArray<Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return *this = JArray<Etype>(toCopy);
		}

		/** @copydoc SequenceContainer::operator=(const SequenceContainer<T, Etype>& toCopy) */
		template<typename Etype>
		JArray<Etype>& JArray<Etype>::operator=(const JArray<Etype>& toCopy)
		{
			return this->assign(toCopy);
		}
	}
}