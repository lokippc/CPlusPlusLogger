#pragma once

#include "LoggerAPI.h"

#include "LogLevel.h"

#include <chrono>
#include <thread>

#pragma warning( push )
#pragma warning( disable : 4251 )

namespace Log
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief A Raw Log Entry that contaisn all raw data captured by logger during a log event.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class LOGGER_API RawLogEntry
	{
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Constructor that takes all parts of the raw entry.
		///
		/// \param timeStamp The time stamp of the message.
		/// \param logLevel The log level the message was logged with.
		/// \param moduleName The module name of the logger.
		/// \param threadID The thread id of the thread the message was created.
		/// \param message The log message.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		RawLogEntry(const std::chrono::time_point<std::chrono::system_clock>& timeStamp, const LogLevel logLevel, const std::string& moduleName, const std::thread::id threadID, const std::string& message);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the time stamp.
		///
		/// \returns The time stamp of the message.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const std::chrono::time_point<std::chrono::system_clock>& getTimeStamp() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the log level.
		///
		/// \returns The log level the message was logged with.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const LogLevel getLogLevel() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the module name.
		///
		/// \returns The module name of the logger.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const std::string& getModuleName() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the thread id.
		///
		/// \returns The thread id of the thread the message was created.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const std::thread::id getThreadID() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the message.
		///
		/// \returns The log message.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const std::string& getMessage() const;

	private:
		std::chrono::time_point<std::chrono::system_clock> m_timeStamp; //!< The timestamp of the message.
		LogLevel m_logLevel; //!< The log level the message was logged with.
		std::string m_moduleName; //!< The module name of the logger.
		std::thread::id m_threadID; //!< The thread id of the thread the message was created.
		std::string m_message; //!< The log message.
	};
}

#pragma warning( pop ) 