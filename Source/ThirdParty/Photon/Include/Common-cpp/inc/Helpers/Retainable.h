/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T>
			class Retainable : public T
			{
			public:
				Retainable(void);
				virtual Retainable<T>* retain(void);
				virtual const Retainable<T>* retain(void) const;
				virtual void release(void) const;

				virtual unsigned char getRefCount(void) const;
			protected:
				virtual ~Retainable(void);
			private:
				mutable unsigned char mRefCount;
			};



			template<typename T>
			Retainable<T>::Retainable(void)
				: mRefCount(0)
			{
				retain();
			}

			template<typename T>
			Retainable<T>::~Retainable(void)
			{
			}

			template<typename T>
			Retainable<T>* Retainable<T>::retain(void)
			{
				++mRefCount;
				return this;
			}

			template<typename T>
			const Retainable<T>* Retainable<T>::retain(void) const
			{
				++mRefCount;
				return this;
			}

			template<typename T>
			void Retainable<T>::release(void) const
			{
				if(!--mRefCount)
					DEALLOCATE(Retainable<T>, this);
			}

			template<typename T>
			unsigned char Retainable<T>::getRefCount(void) const
			{
				return mRefCount;
			}
		}
	}
}