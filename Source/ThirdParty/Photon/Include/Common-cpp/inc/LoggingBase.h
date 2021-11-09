/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Logger.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename T>
		class LoggingBase : virtual public ToString
		{
		public:
			virtual ~LoggingBase(void) = 0;
			static void setListener(const BaseListener* baseListener);
			static int getDebugOutputLevel(void);
			static bool setDebugOutputLevel(int debugLevel);
			static const LogFormatOptions& getLogFormatOptions(void);
			static void setLogFormatOptions(const LogFormatOptions& options);
		private:
			struct Accessor : private T
			{
				static Logger& getLogger(void);
			private:
				Accessor(void);
			};
		};



		/** @file */

		/**
		   Destructor. */
		template<typename T>
		LoggingBase<T>::~LoggingBase(void)
		{
		}

		/**
		   Registers a listener for receiving debug information from the
		   Exit Games Utility classes.
		   @details
		   Please refer to BaseListener for more information and
		   a code example.
		   @param baseListener The listener, in which you want to receive the the events. Has to be a pointer to a class derived from BaseListener.
		   @sa
		   BaseListener                                                    */
		template<typename T>
		void LoggingBase<T>::setListener(const BaseListener* const baseListener)
		{
			Accessor::getLogger().setListener(*baseListener);
		}

		/**
		   @copydoc ExitGames::Common::Logger::getDebugOutputLevel() */
		template<typename T>
		int LoggingBase<T>::getDebugOutputLevel(void)
		{
			return Accessor::getLogger().getDebugOutputLevel();
		}

		/**
		   @copydoc ExitGames::Common::Logger::setDebugOutputLevel() */
		template<typename T>
		bool LoggingBase<T>::setDebugOutputLevel(int debugLevel)
		{
			return Accessor::getLogger().setDebugOutputLevel(debugLevel);
		}

		/**
		   @copydoc ExitGames::Common::Logger::getFormatOptions() */
		template<typename T>
		const LogFormatOptions& LoggingBase<T>::getLogFormatOptions(void)
		{
			return Accessor::getLogger().getFormatOptions();
		}

		/**
		   @copydoc ExitGames::Common::Logger::setFormatOptions() */
		template<typename T>
		void LoggingBase<T>::setLogFormatOptions(const LogFormatOptions& formatOptions)
		{
			Accessor::getLogger().setFormatOptions(formatOptions);
		}

		template<typename T>
		Logger& LoggingBase<T>::Accessor::getLogger(void)
		{
			return T::mLogger;
		}
	}
}