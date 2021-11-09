/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Internal/PlayerFactory.h"
#include "LoadBalancing-cpp/inc/Internal/PlayerMutableRoomPointerSetter.h"
#include "LoadBalancing-cpp/inc/Internal/PlayerPropertiesCacher.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Player : public Common::ToString
		{
		public:
			using ToString::toString;

			virtual ~Player(void);

			Player(const Player& toCopy);
			virtual Player& operator=(const Player& toCopy);

			int getNumber(void) const;
			const Common::JString& getName() const;
			const Common::JString& getUserID() const;
			const Common::Hashtable& getCustomProperties() const;
			bool getIsInactive(void) const;
			bool getIsMasterClient(void) const;

			bool operator==(const Player& player) const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			virtual Common::JString toString(bool withTypes, bool withCustomProperties) const;
		protected:
			Player(int number, const Common::Hashtable& properties, const MutableRoom* pRoom);

			virtual bool getIsMutable(void) const;

			virtual Player& assign(const Player& toCopy);
			virtual void setMutableRoomPointer(const MutableRoom* pRoom);
			virtual void setIsInactive(bool);
			virtual void cacheProperties(const Common::Hashtable& properties);
			virtual Common::JString payloadToString(bool withTypes, bool withCustomProperties=false) const;

			int mNumber;
			Common::JString mName;
			Common::JString mUserID;
			Common::Hashtable mCustomProperties;
			const MutableRoom* mpRoom;
			bool mIsInactive;
		private:
			Player(void);

			friend class Internal::PlayerFactory;
			friend class Internal::PlayerPropertiesCacher;
			friend class Internal::PlayerMutableRoomPointerSetter;
		};
	}
}