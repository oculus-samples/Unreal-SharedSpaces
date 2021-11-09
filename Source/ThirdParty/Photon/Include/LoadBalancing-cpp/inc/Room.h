/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Internal/RoomFactory.h"
#include "LoadBalancing-cpp/inc/Internal/RoomPropertiesCacher.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Room : public Common::ToString
		{
		public:
			using ToString::toString;

			virtual ~Room(void);

			Room(const Room& toCopy);
			virtual Room& operator=(const Room& toCopy);

			const Common::JString& getName(void) const;
			virtual nByte getPlayerCount(void) const;
			nByte getMaxPlayers(void) const;
			bool getIsOpen(void) const;
			nByte getDirectMode(void) const;
			const Common::Hashtable& getCustomProperties(void) const;

			bool operator==(const Room& room) const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			virtual Common::JString toString(bool withTypes, bool withCustomProperties) const;
		protected:
			Room(const Common::JString& name, const Common::Hashtable& properties);

			virtual bool getIsMutable(void) const;

			virtual Room& assign(const Room& toCopy);
			virtual void cacheProperties(const Common::Hashtable& properties);
			virtual Common::JString payloadToString(bool withTypes=false, bool withCustomProperties=false) const;

			Common::JString mName;
			nByte mPlayerCount;
			nByte mMaxPlayers;
			bool mIsOpen;
			nByte mDirectMode;
			Common::Hashtable mCustomProperties;
		private:
			Room(void);

			friend class Internal::RoomFactory;
			friend class Internal::RoomPropertiesCacher;
		};
	}
}