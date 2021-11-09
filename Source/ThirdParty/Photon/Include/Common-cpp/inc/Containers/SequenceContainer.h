/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Base.h"
#include "Common-cpp/inc/Helpers/Stringification/Stringifier.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsDerivedFrom.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsPrimitiveType.h"
#include "Common-cpp/inc/MemoryManagement/Allocate.h"
#include "Common-cpp/inc/MemoryManagement/Internal/Interface.h"
#include <memory>

namespace ExitGames
{
	namespace Common
	{
		template<template<typename> class T, typename Etype>
		class SequenceContainer : public Base
		{
		public:
			using ToString::toString;

			virtual ~SequenceContainer(void) = 0;

			SequenceContainer<T, Etype>& operator=(const SequenceContainer<T, Etype>& toCopy);
			template<template<typename> class FT> SequenceContainer<T, Etype>& operator=(const SequenceContainer<FT, Etype>& toCopy);

			bool operator==(const SequenceContainer<T, Etype>& toCompare) const;
			bool operator!=(const SequenceContainer<T, Etype>& toCompare) const;
			const Etype& operator[](unsigned int index) const;
			const Etype& operator[](int index) const;
			Etype& operator[](unsigned int index);
			Etype& operator[](int index);

			unsigned int getCapacity(void) const;
			bool contains(const Etype& elem) const;
			const Etype& getFirstElement(void) const;
			int getIndexOf(const Etype& elem) const;
			bool getIsEmpty(void) const;
			const Etype& getLastElement(void) const;
			int getLastIndexOf(const Etype& elem) const;
			unsigned int getSize(void) const;
			const Etype* getCArray(void) const;

			void copyInto(Etype* array) const;
			void addElement(const Etype& obj);
			void addElements(const Etype* carray, unsigned int elementCount);
			template<template<typename> class FT> void addElements(const SequenceContainer<FT, Etype>& container);
			void ensureCapacity(unsigned int minCapacity);
			void removeAllElements(void);
			bool removeElement(const Etype& obj);
			void trimToSize(void);
			const Etype& getElementAt(unsigned int index) const;
			void insertElementAt(const Etype &obj, unsigned int index);
			void removeElementAt(unsigned int index);
			void setElementAt(const Etype &obj, unsigned int index);
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			SequenceContainer(unsigned int initialCapacity=0, unsigned int capacityIncrement=1);
			SequenceContainer(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity=0, unsigned int capacityIncrement=1);

			explicit SequenceContainer(const SequenceContainer<T, Etype>& toCopy);
			template<template<typename> class FT> explicit SequenceContainer(const SequenceContainer<FT, Etype>& toCopy);

			virtual T<Etype>& assign(const SequenceContainer<T, Etype>& toCopy);
		private:
			template<template<typename> class FT> void init(const SequenceContainer<FT, Etype>& toCopy);

			void verifyIndex(unsigned int index) const;

			unsigned int mSize;
			unsigned int mCapacity;
			unsigned int mIncrement;
			Etype* mpData;

			template<template<typename> class CT, typename ET> friend class SequenceContainer;
		};



		/** @file */

		template<template<typename> class T, typename Etype>
		SequenceContainer<T, Etype>::SequenceContainer(unsigned int initialCapacity, unsigned int capacityIncrement) 
		{
			mSize = 0;
			mCapacity = initialCapacity;
			static MemoryManagement::AllocatorInterface* pAllocator = MemoryManagement::Internal::Interface::getAllocator(0); // this assures that the allocator gets constructed now and hence will still be around when the destructor is called, even when we construct a global/static instance with an initialCapacity of 0 as the very first user of the allocator
			if(pAllocator){} // this silences the unused variable warning - this line gets optimized out by the compiler in release configurations
			mpData = static_cast<Etype*>(MemoryManagement::EG_MALLOC(sizeof(Etype)*mCapacity));
			mIncrement = capacityIncrement;
		}

		template<template<typename> class T, typename Etype>
		SequenceContainer<T, Etype>::SequenceContainer(const Etype* carray, unsigned int elementCount, unsigned int initialCapacity, unsigned int capacityIncrement)
		{
			mSize = elementCount;
			mCapacity = initialCapacity<elementCount?elementCount:initialCapacity;
			static MemoryManagement::AllocatorInterface* pAllocator = MemoryManagement::Internal::Interface::getAllocator(0); // this assures that the allocator gets constructed now and hence will still be around when the destructor is called, even when we construct a global/static instance with an initialCapacity of 0 as the very first user of the allocator
			if(pAllocator){} // this silences the unused variable warning - this line gets optimized out by the compiler in release configurations
			mpData = static_cast<Etype*>(MemoryManagement::EG_MALLOC(sizeof(Etype)*mCapacity));
			mIncrement = capacityIncrement;
			for(unsigned int i=0; i<mSize; ++i)
				new(mpData+i) Etype(carray[i]);
		}
	
		/**
		   Destructor. */
		template<template<typename> class T, typename Etype>
		SequenceContainer<T, Etype>::~SequenceContainer(void)
		{
			removeAllElements();
			MemoryManagement::EG_FREE(mpData);
		}

		template<template<typename> class T, typename Etype>
		SequenceContainer<T, Etype>::SequenceContainer(const SequenceContainer<T, Etype>& toCopy)
			: mSize(0)
			, mCapacity(0)
			, mIncrement(0)
			, mpData(NULL)
		{
			init(toCopy);
		}

		template<template<typename> class T, typename Etype>
		template<template<typename> class FT>
		SequenceContainer<T, Etype>::SequenceContainer(const SequenceContainer<FT, Etype>& toCopy)
			: mSize(0)
			, mCapacity(0)
			, mIncrement(0)
			, mpData(NULL)
		{
			init(toCopy);
		}

		/**
		   operator=.
	   
		   Makes a deep copy of its right operand into its left operand.
	   
		   This overwrites old data in the left operand. */
		template<template<typename> class T, typename Etype>
		SequenceContainer<T, Etype>& SequenceContainer<T, Etype>::operator=(const SequenceContainer<T, Etype>& toCopy)
		{
			return static_cast<T<Etype>&>(*this) = static_cast<const T<Etype>&>(toCopy);
		}
		
		/** @overload */
		template<template<typename> class T, typename Etype>
		template<template<typename> class FT>
		SequenceContainer<T, Etype>& SequenceContainer<T, Etype>::operator=(const SequenceContainer<FT, Etype>& toCopy)
		{
			return static_cast<T<Etype>&>(*this) = FT<Etype>(toCopy);
		}

		template<template<typename> class T, typename Etype>
		T<Etype>& SequenceContainer<T, Etype>::assign(const SequenceContainer<T, Etype>& toCopy)
		{
			init(toCopy);
			return static_cast<T<Etype>&>(*this);
		}

		template<template<typename> class T, typename Etype>
		template<template<typename> class FT>
		void SequenceContainer<T, Etype>::init(const SequenceContainer<FT, Etype>& toCopy)
		{
			if(mSize > 0 || mCapacity < toCopy.mCapacity)
			{
				removeAllElements();
				MemoryManagement::EG_FREE(mpData);
				mCapacity = toCopy.mCapacity;
				mpData = static_cast<Etype*>(MemoryManagement::EG_MALLOC(sizeof(Etype)*mCapacity));
			}

			mSize = toCopy.mSize;
			mIncrement = toCopy.mIncrement;

			for(unsigned int i=0; i<mSize; i++)
				new(mpData+i) Etype(toCopy.mpData[i]);
		}
		
		/**
		   operator==.
		   @returns true, if both operands are equal, false otherwise.
		   Two instances are treated as equal, if they both contain the the same amount of elements and every element of one instance
		   equals the other instance's element at the same index. If the element type is a pointer type, then the pointers are checked
		   for equality, not the values, to which they point to. */
		template<template<typename> class T, typename Etype>
		bool SequenceContainer<T, Etype>::operator==(const SequenceContainer<T, Etype>& toCompare) const
		{
			if(getSize() != toCompare.getSize())
				return false;
			for(unsigned int i=0; i<getSize(); ++i)
				if((*this)[i] != toCompare[i])
					return false;
			return true;
		}

		/**
		   operator!=.
		   @returns false, if operator==() would return true, true otherwise. */
		template<template<typename> class T, typename Etype>
		bool SequenceContainer<T, Etype>::operator!=(const SequenceContainer<T, Etype>& toCompare) const
		{
			return !(*this == toCompare);
		}

		/**
		   operator[]. Wraps the function getElementAt(),
		   so that you have the same syntax like for c-arrays.                                                 */
		template<template<typename> class T, typename Etype>
		const Etype& SequenceContainer<T, Etype>::operator[](unsigned int index) const
		{
			return getElementAt(index);
		}

		/**
		   operator[]. Wraps the function getElementAt(),
		   so that you have the same syntax like for c-arrays.                                                 */
		template<template<typename> class T, typename Etype>
		const Etype& SequenceContainer<T, Etype>::operator[](int index) const
		{
			return getElementAt(index);
		}

		/**
		   operator[]. Enables c-array like write access to elements.                                                */
		template<template<typename> class T, typename Etype>
		Etype& SequenceContainer<T, Etype>::operator[](unsigned int index)
		{
			verifyIndex(index);
			return mpData[index];
		}

		/**
		   operator[]. Enables c-array like write access to elements.                                                */
		template<template<typename> class T, typename Etype>
		Etype& SequenceContainer<T, Etype>::operator[](int index)
		{
			verifyIndex(index);
			return mpData[index];
		}

		/**
		   Returns the current capacity of the instance .
		   @returns
		   the current capacity.                                */
		template<template<typename> class T, typename Etype>
		unsigned int SequenceContainer<T, Etype>::getCapacity(void) const
		{
			return mCapacity;
		}

		/**
		   Checks, if the instance contains the passed data as an
		   element.
		   @param elem a reference to the data, you want to check. Needs to be either a primitive type or an object of a class with an overloaded == operator.
		   @returns
		   true, if the element was found, false otherwise.             */
		template<template<typename> class T, typename Etype>
		bool SequenceContainer<T, Etype>::contains(const Etype &elem) const
		{
			for(unsigned int i=0; i<mSize; i++)
			{
				if(mpData[i] == elem)
					return true;
			}

			return false;
		}

		/**
		   Copies all elements of the container instance into the passed
		   array. The caller has to make sure, that the array is big enough
		   to take all elements of the vector, otherwise calling this
		   function produces a buffer overflow.
		   @param array  an array of variables of the type of the template instantiation.
		   @returns
		   nothing.                                                     */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::copyInto(Etype* array) const
		{
			for(unsigned int i=0; i<mSize; i++)
				array[i] = *mpData[i];
		}

		/**
		   Returns the element of the instance at the passed
		   index. This does not check for valid indexes and shows
		   undefined behavior for invalid indexes!
		   @param index the index of the element, that should be returned. Must not be bigger than the current size of the vector!
		   @returns
		   the element at the passed index.                            */
		template<template<typename> class T, typename Etype>
		const Etype& SequenceContainer<T, Etype>::getElementAt(unsigned int index) const
		{
			verifyIndex(index);
			return mpData[index];
		}

		/**
		   Returns the first element of the instance. Shows
		   undefined behavior for empty vectors.
		   @returns
		   the first element.                                      */
		template<template<typename> class T, typename Etype>
		const Etype& SequenceContainer<T, Etype>::getFirstElement(void) const
		{
			verifyIndex(0);
			return mpData[0];
		}

		/**
		   Searches the instance from the first element in forward
		   direction for the passed element and returns the first index,
		   where it was found.
		   @param elem the element, to search for.
		   @returns
		   the index of the first found of the passed element or -1, if
		   the element could not be found at all.                        */
		template<template<typename> class T, typename Etype>
		int SequenceContainer<T, Etype>::getIndexOf(const Etype &elem) const
		{
			for(unsigned int i=0; i<mSize; i++)
				if(mpData[i] == elem)
					return i;
			return -1;
		}

		/**
		   Checks, if the instance is empty.
		   @returns
		   true, if the instance is empty, or false, if it contains at
		   least one element.                                         */
		template<template<typename> class T, typename Etype>
		bool SequenceContainer<T, Etype>::getIsEmpty(void) const
		{
			return !mSize;
		}

		/**
		   Returns the last element of the instance. Shows
		   undefined behavior for empty vectors.
		   @returns
		   the last element.                                      */
		template<template<typename> class T, typename Etype>
		const Etype& SequenceContainer<T, Etype>::getLastElement() const
		{
			verifyIndex(0);
			return mpData[mSize-1];
		}

		/**
		   Searches the instance from the last element in backward
		   direction for the passed element and returns the first index,
		   where it was found.
		   @param elem the element, to search for.
		   @returns
		   the index of the first found of the passed element or -1, if
		   the element could not be found at all.                        */
		template<template<typename> class T, typename Etype>
		int SequenceContainer<T, Etype>::getLastIndexOf(const Etype &elem) const
		{
			for(unsigned int i=mSize; i; i--)
				if(*mpData[i] == elem)
					return i;
			return -1;
		}

		/**
		   Returns the number of elements of the instance.
		   @returns
		   the size.                              */
		template<template<typename> class T, typename Etype>
		unsigned int SequenceContainer<T, Etype>::getSize(void) const
		{
			return mSize;
		}

		/**
		   @remarks
		   For a deep-copy @link copyInto()\endlink should be used.
		   Use @link getSize()\endlink to find out the element count of the returned array.
		   @returns
		   a read-only pointer copy of the Etype*, that is internally used to store the elements. */
		template<template<typename> class T, typename Etype>
		const Etype* SequenceContainer<T, Etype>::getCArray(void) const
		{
			return getSize()?mpData:NULL;
		}

		/**
		   Adds an element to the instance. This automatically
		   resizes the instances capacity to it's old size + the capacityIncrement,
		   that you passed, when creating the vector (if you passed no value for
		   capacityIncrement, then it was set to it's default value (see
		   constructor doc)), if the size of the instance has already
		   reached it's capacity.
		   When resizing occurs, then most likely the
		   whole vector has to be copied to new memory. So this can be
		   an expensive operation for huge vectors.
		   @note When this function needs to increase the capacity, then all references/pointers to elements, that have been acquired before this function has been called, become invalid!
		   @param elem the element to add.
		   @returns
		   nothing.                                                      */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::addElement(const Etype& elem)
		{
			if(mSize == mCapacity)
				ensureCapacity(mCapacity+mIncrement);
			new(mpData+mSize) Etype(elem);
			++mSize;
		}

		/**
		   Adds the first 'elementCount' elements of the provided array to the instance.
		   This automatically resizes the instances capacity to it's old size + 'elementCount',
		   if the new size of the instance is bigger than it's old capacity.
		   When resizing occurs, then most likely the
		   whole vector has to be copied to new memory. So this can be
		   an expensive operation for huge vectors.
		   @note When this function needs to increase the capacity, then all references/pointers to elements, that have been acquired before this function has been called, become invalid!
		   @param carray the elements to add.
		   @param elementCount the number of elements to add - must not be greater than the size of carray.
		   @returns
		   nothing.                                                      */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::addElements(const Etype* carray, unsigned int elementCount)
		{
			if((mSize+elementCount) > mCapacity)
				ensureCapacity(mSize+elementCount);
			for(unsigned int i=0; i<elementCount; ++i)
				new(mpData+mSize+i) Etype(carray[i]);
			mSize += elementCount;
		}
		
		/**
		   @overload
		   Calls the above function with container.getCArray() and container.getSize() as parameters
		   @param container the container class instance from which to copy the elements */
		template<template<typename> class T, typename Etype>
		template<template<typename> class FT> 
		void SequenceContainer<T, Etype>::addElements(const SequenceContainer<FT, Etype>& container)
		{
			addElements(container.getCArray(), container.getSize());
		}

		/**
		   Resizes the instance to the passed capacity, if it's
		   old capacity has been smaller. If resizing is needed,
		   then the whole instance has to be copied into new memory,
		   so in that case this is an expensive operation for huge
		   instances.
		   Call this function, before you add a lot of elements to
		   the vector, to avoid multiple expensive resizes through
		   adding.
		   @note When this function needs to increase the capacity, then all references/pointers to elements, that have been acquired before this function has been called, will get invalid!
		   @param minCapacity the new capacity for the instance.
		   @returns
		   nothing.                                                      */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::ensureCapacity(unsigned int minCapacity)
		{
			if(minCapacity <= mCapacity)
				return;
			Etype* temp = static_cast<Etype*>(MemoryManagement::EG_MALLOC(sizeof(Etype)*(mCapacity=minCapacity)));

			//copy all the elements over up to new memory
			for(unsigned int i=0; i<mSize; i++)
			{
				new(temp+i) Etype(mpData[i]);
				mpData[i].~Etype();
			}

			MemoryManagement::EG_FREE(mpData);

			mpData = temp;
		}

		/**
		   Inserts parameter one into the instance at the index,
		   passed as parameter two. Because all elements above or at the
		   passed index have to be moved one position up, it is
		   expensive, to insert an element at an low index into a huge
		   instance.
		   @param obj the element, to insert.
		   @param index the position in the instance, the element is inserted at.
		   @returns
		   nothing.                                                      */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::insertElementAt(const Etype &obj, unsigned int index)
		{
			if(index == mSize)
				addElement(obj);
			else
			{
				verifyIndex(index);

				if(mSize == mCapacity)
					ensureCapacity(mCapacity + mIncrement);

				Etype newItem = obj;

				Etype tmp; //temp to hold item to be moved over.
				for(unsigned int i=index; i<=mSize; i++)
				{
					if(i != mSize)
					{
						tmp = mpData[i];
						mpData[i] = newItem;
						newItem = tmp;
					}
					else
						new(mpData+i) Etype(newItem);
				}
				mSize++;
			}
		}

		/**
		   Clears the instance.
		   @returns
		   nothing.                   */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::removeAllElements()
		{
			for(unsigned int i=0; i<mSize; i++)
				mpData[i].~Etype();

			mSize = 0;
		}

		/**
		   Removes the first occurrence of the passed value from the instance.
		   @param obj the element, to remove.
		   @returns
		   true, if an occurrence of the value has been removed, false, if the value could not be found.                                                     */
		template<template<typename> class T, typename Etype>
		bool SequenceContainer<T, Etype>::removeElement(const Etype &obj)
		{
			for(unsigned int i=0; i<mSize; i++)
			{
				if(mpData[i] == obj)
				{
					removeElementAt(i);
					return true;
				}
			}
			return false;
		}

		/**
		   Removes the element at the passed index from the instance.
		   Shows undefined behavior for invalid indexes.
		   @param index the index of the element to remove.
		   @returns
		   nothing.                                                         */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::removeElementAt(unsigned int index)
		{
			verifyIndex(index);

			for(unsigned int i=index+1; i<mSize; i++)
			{
				mpData[i-1].~Etype();
				new(mpData+i-1) Etype(mpData[i]);
			}

			mpData[mSize-1].~Etype();

			mSize--;
		}

		/**
		   Sets the element at the passed index of the instance to
		   the passed new value. Shows undefined behavior for invalid
		   indexes.
		   @param obj the new value.
		   @param index the index of the element, which is set to the new value.
		   @returns
		   nothing.                                                      */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::setElementAt(const Etype &obj, unsigned int index)
		{
			verifyIndex(index);

			mpData[index] = obj;
		}

		/**
		   Trims the capacity of the instance to the size, it
		   currently uses. Call this function for a instance with huge
		   unused capacity, if you do not want to add further elements
		   to it and if you are short on memory. This function copies the
		   whole vector to new memory, so it is expensive for huge
		   vectors. If you only add one element to the instance later,
		   it's copied again.
		   @note Trimming a instance instance (that isn't already optimally trimmed) will make all references/pointers to elements, that have been acquired before this function has been called, invalid!                                           */
		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::trimToSize(void)
		{
			if(mSize != mCapacity)
			{
				Etype* temp = static_cast<Etype*>(MemoryManagement::EG_MALLOC(sizeof(Etype)*mSize));;
				unsigned int i;

				for(i=0; i<mSize; i++)
				{
					new(temp+i) Etype(mpData[i]);
					mpData[i].~Etype();
				}

				MemoryManagement::EG_FREE(mpData);

				mpData = temp;
				mCapacity = mSize;
			}
		}

		template<template<typename> class T, typename Etype>
		void SequenceContainer<T, Etype>::verifyIndex(unsigned int index) const
		{
			if(index >= mSize)
				EGLOG(DebugLevel::ERRORS, L"Index Out Of Bounds");
		}

		template<template<typename> class T, typename Etype>
		JString& SequenceContainer<T, Etype>::toString(JString& retStr, bool /*withTypes*/) const
		{
			return retStr += Helpers::Stringifier<Etype>::toString(mpData, getSize());
		}
	}
}