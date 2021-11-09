/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/SmartPointers/SmartPointerInterface.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype>
			class UniquePointerBase : public SmartPointerInterface<Etype>
			{
			protected:
				UniquePointerBase(void (*pDeleter)(const Etype*));
				UniquePointerBase(Etype* pData, void (*pDeleter)(const Etype*));
				virtual ~UniquePointerBase(void) = 0;

				virtual inline UniquePointerBase<Etype>& operator=(Etype* pData); // 'inline' prevents a false positive for MSVC warning 4505
			private:
				UniquePointerBase& operator=(const UniquePointerBase<Etype>& toCopy);

				typedef SmartPointerInterface<Etype> super;
			};



			template<typename Etype>
			UniquePointerBase<Etype>::UniquePointerBase(void (*pDeleter)(const Etype*)) : SmartPointerInterface<Etype>(pDeleter)
			{
			}

			template<typename Etype>
			UniquePointerBase<Etype>::UniquePointerBase(Etype* pData, void (*pDeleter)(const Etype*)) : SmartPointerInterface<Etype>(pData, pDeleter)
			{
			}

			template<typename Etype>
			UniquePointerBase<Etype>::~UniquePointerBase(void)
			{
				super::mpDeleter(super::mpData);
			}

			template<typename Etype>
			UniquePointerBase<Etype>& UniquePointerBase<Etype>::operator=(Etype* pData)
			{
				if(super::mpData)
					super::mpDeleter(super::mpData);
				super::mpData = pData;
				return *this;
			}
		}
	}
}