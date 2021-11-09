/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/JString.h"
#include "Common-cpp/inc/Helpers/ElementAccessor.h"
#include "Common-cpp/inc/Helpers/SmartPointers/SmartPointerBase.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsDerivedFrom.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype>
			class ObjectToStringConverterBase
			{
			public:
				static JString toString(const Etype& data, bool withTypes=false);
				static JString toString(const Etype* pData, unsigned int size, bool withTypes=false);
			private:
				typedef ElementAccessor<Etype, IsDerivedFrom<Etype, SmartPointerBase>::is> EA;
			};



			template<typename Etype>
			JString ObjectToStringConverterBase<Etype>::toString(const Etype& data, bool withTypes)
			{
				return EA::getElement(&data, 0).toString(withTypes);
			}

			template<typename Etype>
			JString ObjectToStringConverterBase<Etype>::toString(const Etype* pData, unsigned int size, bool withTypes)
			{
				JString retStr = JString(L"[");
				for(unsigned int i=0; i<size; ++i)
				{
					retStr += EA::getElement(pData, i).toString(withTypes);
					if(i < size-1)
						retStr += L", ";
				}
				retStr += L"]";
				return retStr;
			}
		}
	}
}