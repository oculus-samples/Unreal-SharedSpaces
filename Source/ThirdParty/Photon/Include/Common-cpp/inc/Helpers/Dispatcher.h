/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Callback.h"
#include "Common-cpp/inc/Helpers/SmartPointers/SharedPointer.h"
#include "Common-cpp/inc/Helpers/TypeID.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename EKeyType, typename EValueType> class JDictionary;

		namespace Helpers
		{
			template<typename T>
			class Dispatcher : public Base
			{
			public:
				using ToString::toString;

				template<typename K, typename C> void bind(C& callback);
				void dispatch(const T& obj);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			private:
				JDictionary<size_t, SharedPointer<CallbackBase> > mCallbacks;
			};



			template<typename T>
			template<typename K, typename C>
			void Dispatcher<T>::bind(C& callback)
			{
				mCallbacks.put(Helpers::TypeID<K>::get(), &callback);
			}

			template<typename T>
			void Dispatcher<T>::dispatch(const T& obj)
			{
				SharedPointer<CallbackBase> spCallback = *mCallbacks.getValue(obj.getTypeID());
				if(spCallback)
					(*spCallback)(obj);
				else
					EGLOG(DebugLevel::ERRORS, (JString(L"Could not dispatch callback for ")+obj.getTypeID()).cstr());
			}

			template<typename T>
			JString& Dispatcher<T>::toString(JString& retStr, bool /*withTypes*/) const
			{
				return retStr += JString(L"{") + L"callbacks: " + mCallbacks.toString() + L"}";
			}
		}
	}
}