/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/SmartPointers/SmartPointerInterface.h"
#ifdef EG_PLATFORM_SUPPORTS_ATOMICS
#	include <atomic>
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype>
			class SharedPointerBase : public SmartPointerInterface<Etype>
			{
			protected:
				SharedPointerBase(void (*pDeleter)(const Etype*));
				SharedPointerBase(Etype* pData, void (*pDeleter)(const Etype*));
				virtual ~SharedPointerBase(void) = 0;

				SharedPointerBase(const SharedPointerBase<Etype>& toCopy);
				template<typename Ftype> SharedPointerBase(const SharedPointerBase<Ftype>& toCopy, const SharedPointerBase<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Ftype>::type>* pDummyDeducer=NULL);
				virtual SharedPointerBase& operator=(const SharedPointerBase<Etype>& toCopy);
				template<typename Ftype> SharedPointerBase<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Etype>::type>& operator=(const SharedPointerBase<Ftype>& toCopy);

#ifdef EG_PLATFORM_SUPPORTS_ATOMICS
				typedef std::atomic<unsigned int> atomicUInt;
#else
				typedef unsigned int atomicUInt;
#endif
				atomicUInt* mpRefCount;
			private:
				template<typename Ftype> SharedPointerBase& assign(const SharedPointerBase<Ftype>& toCopy);

				typedef SmartPointerInterface<Etype> super;
				template<typename T> friend class SharedPointerBase;
			};



			template<typename Etype>
			SharedPointerBase<Etype>::SharedPointerBase(void (*pDeleter)(const Etype*)) : SmartPointerInterface<Etype>(pDeleter)
			{
				mpRefCount = MemoryManagement::allocate<atomicUInt>(1);
			}

			template<typename Etype>
			SharedPointerBase<Etype>::SharedPointerBase(Etype* pData, void (*pDeleter)(const Etype*)) : SmartPointerInterface<Etype>(pData, pDeleter)
			{
				mpRefCount = MemoryManagement::allocate<atomicUInt>(1);
			}

			template<typename Etype>
			SharedPointerBase<Etype>::~SharedPointerBase(void)
			{
				if(--*mpRefCount)
					return;
				super::mpDeleter(super::mpData);
				MemoryManagement::deallocate(mpRefCount);
			}

			template<typename Etype>
			SharedPointerBase<Etype>::SharedPointerBase(const SharedPointerBase<Etype>& toCopy) : SmartPointerInterface<Etype>(toCopy)
			{
				super::mpData = NULL;
				mpRefCount = NULL;
				*this = toCopy;
			}

			template<typename Etype>
			template<typename Ftype>
			SharedPointerBase<Etype>::SharedPointerBase(const SharedPointerBase<Ftype>& toCopy, const SharedPointerBase<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Ftype>::type>* /*pDummyDeducer*/) : SmartPointerInterface<Etype>(toCopy)
			{
				super::mpData = NULL;
				mpRefCount = NULL;
				*this = toCopy;
			}

			template<typename Etype>
			SharedPointerBase<Etype>& SharedPointerBase<Etype>::operator=(const SharedPointerBase<Etype>& toCopy)
			{
				return assign(toCopy);
			}

			template<typename Etype>
			template<typename Ftype>
			SharedPointerBase<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Etype>::type>& SharedPointerBase<Etype>::operator=(const SharedPointerBase<Ftype>& toCopy)
			{
				return assign(toCopy);
			}

			template<typename Etype>
			template<typename Ftype>
			SharedPointerBase<Etype>& SharedPointerBase<Etype>::assign(const SharedPointerBase<Ftype>& toCopy)
			{
				if(mpRefCount && !--*mpRefCount)
				{
					super::mpDeleter(super::mpData);
					MemoryManagement::deallocate(mpRefCount);
				}
				super::mpData = toCopy.mpData;
				super::mpDeleter = reinterpret_cast<typename super::Deleter>(toCopy.mpDeleter);
				++*(mpRefCount=toCopy.mpRefCount);
				return *this;
			}
		}
	}
}