/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#if defined EG_DEBUGGER
	#include <assert.h>
	#define DEBUG_ASSERT(__exp) assert(__exp)
#else
	#define DEBUG_ASSERT(__exp) ((void)0)
#endif