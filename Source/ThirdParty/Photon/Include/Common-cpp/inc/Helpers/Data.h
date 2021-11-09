/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Base.h"

#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class Data
			{
			public:
				Data(unsigned char* buffer, int size);
				~Data(void);

				Data(Data&& rhs);
				Data& operator=(Data&& rhs);

				int getSize() const;
				nByte* getBuffer() const;
			private:
				Data(const Data& rhs);
				Data& operator=(const Data& rhs);

				void clear(void);
				void reset(void);

				int mSize;
				nByte* mpBuffer;
			};
		}
	}
}

#endif