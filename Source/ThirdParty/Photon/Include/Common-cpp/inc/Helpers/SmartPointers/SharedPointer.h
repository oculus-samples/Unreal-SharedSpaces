/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/SmartPointers/SharedPointerBase.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype>
			class SharedPointer : public SharedPointerBase<Etype>
			{
			public:
				SharedPointer(void (*pDeleter)(const Etype*)=MemoryManagement::deallocate);
				SharedPointer(Etype* pData, void (*pDeleter)(const Etype*)=MemoryManagement::deallocate);

				template<typename Ftype> SharedPointer(const SharedPointer<Ftype>& toCopy, const SharedPointer<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Ftype>::type>* pDummyDeducer=NULL);
				template<typename Ftype> SharedPointer<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Etype>::type>& operator=(const SharedPointer<Ftype>& toCopy);
			private:
				typedef SharedPointerBase<Etype> super;

				virtual inline SharedPointerBase<Etype>& operator=(const SharedPointerBase<Etype>& toCopy); // 'inline' prevents a false positive for MSVC warning 4505
			};

			template<typename Etype>
			class SharedPointer<Etype[]> : public SharedPointerBase<Etype>
			{
			public:
				SharedPointer(void (*pDeleter)(const Etype*)=MemoryManagement::deallocateArray);
				SharedPointer(Etype* pData, void (*pDeleter)(const Etype*)=MemoryManagement::deallocateArray);

				// intentionally no support for the potentially disastrous assignment of subclass arrays
				virtual SharedPointer<Etype[]>& operator=(const SharedPointer<Etype[]>& toCopy);
			private:
				typedef SharedPointerBase<Etype> super;

				virtual inline SharedPointerBase<Etype>& operator=(const SharedPointerBase<Etype>& toCopy); // 'inline' prevents a false positive for MSVC warning 4505
			};



			template<typename Etype>
			SharedPointer<Etype>::SharedPointer(void (*pDeleter)(const Etype*)) : SharedPointerBase<Etype>(pDeleter)
			{
			}

			template<typename Etype>
			SharedPointer<Etype>::SharedPointer(Etype* pData, void (*pDeleter)(const Etype*)) : SharedPointerBase<Etype>(pData, pDeleter)
			{
			}

			template<typename Etype>
			template<typename Ftype>
			SharedPointer<Etype>::SharedPointer(const SharedPointer<Ftype>& toCopy, const SharedPointer<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Ftype>::type>* /*pDummyDeducer*/) : SharedPointerBase<Etype>(toCopy)
			{
			}

			template<typename Etype>
			template<typename Ftype>
			SharedPointer<typename EnableIf<IsDerivedFrom<Ftype, Etype>::is, Etype>::type>& SharedPointer<Etype>::operator=(const SharedPointer<Ftype>& toCopy)
			{
				super::operator=(toCopy);
				return *this;
			}

			template<typename Etype>
			SharedPointerBase<Etype>& SharedPointer<Etype>::operator=(const SharedPointerBase<Etype>& toCopy)
			{
				DEBUG_ASSERT(false);
				super::operator=(toCopy);
				return *this;
			}



			template<typename Etype>
			SharedPointer<Etype[]>::SharedPointer(void (*pDeleter)(const Etype*)) : SharedPointerBase<Etype>(pDeleter)
			{
			}

			template<typename Etype>
			SharedPointer<Etype[]>::SharedPointer(Etype* pData, void (*pDeleter)(const Etype*)) : SharedPointerBase<Etype>(pData, pDeleter)
			{
			}

			template<typename Etype>
			SharedPointer<Etype[]>& SharedPointer<Etype[]>::operator=(const SharedPointer<Etype[]>& toCopy)
			{
				super::operator=(toCopy);
				return *this;
			}

			template<typename Etype>
			SharedPointerBase<Etype>& SharedPointer<Etype[]>::operator=(const SharedPointerBase<Etype>& toCopy)
			{
				DEBUG_ASSERT(false);
				super::operator=(toCopy);
				return *this;
			}
		}
	}
}