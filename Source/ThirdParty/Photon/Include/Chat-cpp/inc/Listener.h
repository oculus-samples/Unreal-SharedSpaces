/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/PhotonPeer.h"

namespace ExitGames
{
	namespace Chat
	{
		/**
			Callback interface for Chat client side. Contains callback methods to notify your app about updates.
			Must be provided to new Chat::Client in constructor*/
		class Listener: public virtual Common::BaseListener
		{
		public:
			virtual ~Listener(void){}

			// receive and print out debug out here
			virtual void debugReturn(int debugLevel, const Common::JString& string) = 0;

			/**
				Notifies app that client state changed.
				@param state new client state
				@sa ClientState::ClientState*/
			virtual void onStateChange(int state) = 0;

			// implement your error-handling here
			virtual void connectionErrorReturn(int errorCode) = 0;
			virtual void clientErrorReturn(int errorCode) = 0;
			virtual void warningReturn(int warningCode) = 0;
			virtual void serverErrorReturn(int errorCode) = 0;

			// callbacks for operations on server

			/**
				Client is connected now.*/
			virtual void connectReturn(int errorCode, const Common::JString& errorString) = 0;

			/**
				Disconnection happened.*/
			virtual void disconnectReturn(void) = 0;

			/** 
				The result of the subscribe operation. Returns per channel name if the channel is now subscribed.
				@param channels channel names
				@param results per channel result: true if subscribed*/
			virtual void subscribeReturn(const Common::JVector<Common::JString>& channels, const Common::JVector<bool>& results) = 0;

			/** 
				Result of unsubscribe operation. Returns per channel name if the channel is now subscribed.
				@param channels channel names that are no longer subscribed*/
			virtual void unsubscribeReturn(const Common::JVector<Common::JString>& channels) = 0;

			/**
				The new status of another user (you get updates for users that are in your friends list).
				@param user name of the user
				@param status new status of that user
				@param gotMessage true if the status contains a message you should cache locally. False: This status update does not include a message (keep any you have).
				@param message message that user set*/
			virtual void onStatusUpdate(const Common::JString& user, int status, bool gotMessage, const Common::Object& message) = 0;

			/**
				Notifies the app that the client got new messages from the server
				Number of senders is equal to number of messages in 'messages'. Sender with number '0' corresponds to message with
				number '0', sender with number '1' corresponds to message with number '1' and so on
				@param channelName channel from where messages came
				@param senders list of users who sent messages
				@param messages list of messages it self*/
			virtual void onGetMessages(const Common::JString& channelName, const Common::JVector<Common::JString>& senders, const Common::JVector<Common::Object>& messages) = 0;

			/**
				Notifies the app about a private message
				@param sender user who sent this message
				@param message the message itself
				@param channelName the channel name for private messages (messages that you sent yourself get added to a channel per target username)*/
			virtual void onPrivateMessage(const Common::JString& sender, const Common::Object& message, const Common::JString& channelName) = 0;

			/**
				Notifies the app about a broadcast message
				@param channelName the channel name through which the message is broadcast
				@param inBuff the message buffer
				@param inBuffBodyLength the message buffer length*/
			virtual void onReceiveBroadcastMessage(const Common::JString& channelName, nByte* inBuff, int inBuffBodyLength) {};
		};
		/** @file */
	}
}