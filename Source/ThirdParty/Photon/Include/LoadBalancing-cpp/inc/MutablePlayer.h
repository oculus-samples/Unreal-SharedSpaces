/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Player.h"
#include "LoadBalancing-cpp/inc/Internal/MutablePlayerFactory.h"
#include "LoadBalancing-cpp/inc/WebFlags.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class MutablePlayer : public Player
		{
		public:
			virtual ~MutablePlayer(void);

			MutablePlayer(const MutablePlayer& toCopy);
			virtual MutablePlayer& operator=(const Player& toCopy);
			virtual MutablePlayer& operator=(const MutablePlayer& toCopy);

			void setName(const Common::JString& name, const WebFlags& webflags=WebFlags());

			void mergeCustomProperties(const Common::Hashtable& customProperties, const WebFlags& webflags=WebFlags());
			template<typename ktype, typename vtype> void addCustomProperty(const ktype& key, const vtype& value, const WebFlags& webflags=WebFlags());
			template<typename ktype, typename vtype> void addCustomProperty(const ktype& key, const vtype pValueArray, typename Common::Helpers::ArrayLengthType<vtype>::type arrSize, const WebFlags& webflags=WebFlags());
			template<typename ktype, typename vtype> void addCustomProperty(const ktype& key, const vtype pValueArray, const short* pArrSizes, const WebFlags& webflags=WebFlags());
			void addCustomProperties(const Common::Hashtable& customProperties, const WebFlags& webflags=WebFlags());
			template<typename ktype> void removeCustomProperty(const ktype& key, const WebFlags& webflags=WebFlags());
			template<typename ktype> void removeCustomProperties(const ktype* keys, unsigned int count, const WebFlags& webflags=WebFlags());
		protected:
			MutablePlayer(int number, const Common::Hashtable& properties, const MutableRoom* pRoom, Client* pClient);

			virtual bool getIsMutable(void) const;

			virtual MutablePlayer& assign(const Player& toCopy);
		private:
			typedef Player super;

			Client* mpLoadBalancingClient;

			friend class Internal::MutablePlayerFactory;
		};



		template<typename ktype, typename vtype>
		void MutablePlayer::addCustomProperty(const ktype& key, const vtype& value, const WebFlags& webflags)
		{
			Common::Hashtable hash;
			hash.put(key, value);
			addCustomProperties(hash, webflags);
		}

		template<typename ktype, typename vtype>
		void MutablePlayer::addCustomProperty(const ktype& key, const vtype pValueArray, typename Common::Helpers::ArrayLengthType<vtype>::type arrSize, const WebFlags& webflags)
		{
			Common::Hashtable hash;
			hash.put(key, pValueArray, arrSize);
			addCustomProperties(hash, webflags);
		}

		template<typename ktype, typename vtype>
		void MutablePlayer::addCustomProperty(const ktype& key, const vtype pValueArray, const short* pArrSizes, const WebFlags& webflags)
		{
			Common::Hashtable hash;
			hash.put(key, pValueArray, pArrSizes);
			addCustomProperties(hash, webflags);
		}

		template<typename ktype>
		void MutablePlayer::removeCustomProperty(const ktype& key, const WebFlags& webflags)
		{
			removeCustomProperties(&key, 1, webflags);
		}

		template<typename ktype>
		void MutablePlayer::removeCustomProperties(const ktype* keys, unsigned int count, const WebFlags& webflags)
		{
			Common::Hashtable hash;
			for(unsigned int i=0; i<count; i++)
				hash.put(keys[i]);
			mergeCustomProperties(hash, webflags);
		}
	}
}