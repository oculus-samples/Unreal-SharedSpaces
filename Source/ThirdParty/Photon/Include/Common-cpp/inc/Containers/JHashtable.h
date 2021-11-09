/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/AssociativeContainer.h"

namespace ExitGames
{
	namespace Common
	{
		/** @class JHashtable
		   The JHashtable class together with the Dictionary class template is one of the two main container classes for objects to be
		   transmitted over Photon when using the C++ Client.
		   @details
		   This class implements the well-known concept of a container structure storing an arbitrary number of key/value-pairs.

		   In contrast to a Dictionary, the types of both the keys and also the values in a JHashtable can differ for every entry.
		   This adds flexibility, but it also reduces type safety and means, that the type infos have to be stored twice (once for the key
		   and once for the value) per entry in a JHashtable, while in a Dictionary it only has to be stored twice for the whole
		   Dictionary, no matter how many entries are in there.
		   Therefor with Dictionaries transferring the same amount of key-value pairs will cause less traffic than with Hashtables.

		   Please have a look at the @link Datatypes Table of Datatypes\endlink for a list of types, that are supported as keys and as
		   values.

		   Please refer to the documentation for put() and getValue() to see how to store and access data in a JHashtable.
		   @sa
		   put(), getValue(), KeyObject, ValueObject, Dictionary */
		class JHashtable : public AssociativeContainer<JHashtable>
		{
		};



		/** @file */
	}
}