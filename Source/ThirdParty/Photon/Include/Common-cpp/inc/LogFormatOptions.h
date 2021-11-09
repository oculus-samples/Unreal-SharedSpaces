/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/ToString.h"

namespace ExitGames
{
	namespace Common
	{
		class LogFormatOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			LogFormatOptions(void);
			virtual ~LogFormatOptions(void);

			bool operator==(const LogFormatOptions& toCompare) const;
			bool operator!=(const LogFormatOptions& toCompare) const;

			bool getAddDateTime(void) const;
			LogFormatOptions& setAddDateTime(bool addTime);
			bool getAddLevel(void) const;
			LogFormatOptions& setAddLevel(bool addLevel);
			bool getAddFile(void) const;
			LogFormatOptions& setAddFile(bool addFile);
			bool getAddFunction(void) const;
			LogFormatOptions& setAddFunction(bool addFunction);
			unsigned int getMaxNumberOfNamespaces(void) const;
			LogFormatOptions& setMaxNumberOfNamespaces(unsigned int maxNumberOfNamespaces);
			bool getAddLine(void) const;
			LogFormatOptions& setAddLine(bool addLine);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			bool mAddDateTime;
			bool mAddLevel;
			bool mAddFile;
			bool mAddFunction;
			unsigned int mMaxNumberOfNamespaces;
			bool mAddLine;
		};
	}
}