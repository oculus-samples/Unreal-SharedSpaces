/* Exit Games Photon Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"

namespace ExitGames
{
	namespace Common
	{
		namespace TypeCode
		{
			static const nByte BYTE               = 'b'; ///<nByte
			static const nByte SHORT              = 'k'; ///<short
			static const nByte INTEGER            = 'i'; ///<int
			static const nByte LONG               = 'l'; ///<int64
			static const nByte EG_FLOAT           = 'f'; ///<float
			static const nByte DOUBLE             = 'd'; ///<double
			static const nByte BOOLEAN            = 'o'; ///<bool
			static const nByte STRING             = 's'; ///<@if CPP JString@endif @if OBJC NSString@endif
			static const nByte HASHTABLE          = 'h'; ///<@if CPP Hashtable@endif @if OBJC NSDictionary@endif
			static const nByte DICTIONARY         = 'D'; ///<@if CPP Dictionary@endif @if OBJC EGDictionary@endif
			static const nByte OBJECT             = 'z'; ///<@if CPP Object@endif @if OBJC NSObject@endif, only allowed for arrays!
			static const nByte ARRAY              = 'y'; ///<internal only
			static const nByte BYTEARRAY          = 'x'; ///<internal only
			static const nByte PHOTON_COMMAND     = 'p'; ///<internal only@internal used for photon commands
			static const nByte EG_NULL            = '*'; ///<<@if CPP an empty Object@endif @if OBJC nil@endif
			static const nByte CUSTOM             = 'c'; ///<a subclass of class @if CPP CustomType@endif @if OBJC EGCustomType@endif - check the value of @if CPP getCustomType()@endif @if OBJC CustomType@endif to find out the exact custom type
			static const nByte UNKNOWN            = 0  ; ///<internal only@internal used instead of OBJECT for values inside a Dictionary
		}
		/** @file */
	}
}