/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Voice
	{
		template<typename T>
		class Buffer : public Common::ToString
		{
		public:
			using ToString::toString;

			Buffer(void);
			Buffer(int size);

			T* getArray(void);
			const T* getArray(void) const;
			int getSize(void) const;

			static const Buffer<T>& getEmpty(void);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			Common::Helpers::SharedPointer<T[]> mspArr;
			int mSize;

			static const Buffer<T> mEmpty;
		};



		template<typename T> const Buffer<T> Buffer<T>::mEmpty;

		template<typename T>
		Buffer<T>::Buffer(void)
			: mspArr()
			, mSize(0)
		{
		}

		template<typename T>
		Buffer<T>::Buffer(int size)
			: mspArr(Common::MemoryManagement::allocateArray<T>(size))
			, mSize(size)
		{
		}

		template<typename T>
		T* Buffer<T>::getArray(void)
		{
			return mspArr;
		}

		template<typename T>
		const T* Buffer<T>::getArray(void) const
		{
			return mspArr;
		}

		template<typename T>
		int Buffer<T>::getSize(void) const
		{
			return mSize;
		}

		template<typename T>
		const Buffer<T>& Buffer<T>::getEmpty(void)
		{
			return mEmpty;
		}

		template<typename T>
		Common::JString& Buffer<T>::toString(Common::JString& retStr, bool /*withTypes*/) const
		{
			return retStr += Common::Helpers::Stringifier<T>::toString(mspArr, getSize());
		}
	}
}