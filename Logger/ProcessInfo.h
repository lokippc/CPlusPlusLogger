#pragma once

#include "LoggerAPI.h"

#include <string>

#pragma warning( push )
#pragma warning( disable : 4251 )

namespace Log
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Gathers and contains information about the current running process.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class LOGGER_API ProcessInfo
	{
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Constructor.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ProcessInfo();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Destructor.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		~ProcessInfo();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the file name of the current process.
		///
		/// \returns The file name of the current process.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const std::string& getProcessFileName() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Returns the ID of the current process.
		///
		/// \returns The ID of the current process.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		const unsigned long getProcessID() const;

	private:
		std::string m_processFileName; //!< The file name of the current process.
		unsigned long m_processID; //!< The ID of the current process.
	};
}

#pragma warning( pop ) 