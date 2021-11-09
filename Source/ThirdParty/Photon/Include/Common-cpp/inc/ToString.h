/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"

namespace ExitGames
{
	namespace Common
	{
		class JString;

		namespace Helpers
		{
			namespace TypeName
			{
				JString cut(const char* rawTypeName);
			}
		}

		class ToString
		{
		public:
			virtual ~ToString(void);
			virtual JString typeToString(void) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const = 0;
			JString toString(bool withTypes=false) const;
		protected:
			static const EG_CHAR* EG_STR_CHAR;
			static const EG_CHAR* EG_STR_SCHAR;
			static const EG_CHAR* EG_STR_UCHAR;
			static const EG_CHAR* EG_STR_SHORT;
			static const EG_CHAR* EG_STR_USHORT;
			static const EG_CHAR* EG_STR_INT;
			static const EG_CHAR* EG_STR_UINT;
			static const EG_CHAR* EG_STR_LONG;
			static const EG_CHAR* EG_STR_ULONG;
			static const EG_CHAR* EG_STR_LONGLONG;
			static const EG_CHAR* EG_STR_ULONGLONG;
			static const EG_CHAR* EG_STR_FLOAT;
			static const EG_CHAR* EG_STR_DOUBLE;
			static const EG_CHAR* EG_STR_LONGDOUBLE;
			static const EG_CHAR* EG_STR_BOOL;
		private:
			friend JString Helpers::TypeName::cut(const char* rawTypeName);
		};
	}
}