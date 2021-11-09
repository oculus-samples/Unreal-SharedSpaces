/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/CallbackBase.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T>
			struct Callback : public CallbackBase
			{
				virtual void operator()(const Message& msg);
				virtual void operator()(const T& msg) = 0;
			};

			template<typename T>
			void Callback<T>::operator()(const Message& msg)
			{
				(*this)(static_cast<const T&>(msg));
			}
		}
	}
}