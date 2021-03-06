#pragma once

#include "LoggerAPI.h"

#include "LogViewerNetworkRPCSinkBase.h"

#pragma warning( push )
#pragma warning( disable : 4251 )

namespace Log
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Sink targeting a network RPC connection. Must be initialized after construction in order to sink incomming 
	///		   messages. Can be initialized as a dummy in case errors prevent a normal initialization. 
	///        Initialization of any kind should only be delayed as much as possible to prevent high memory consumtion.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class LOGGER_API DelayedLogViewerNetworkRPCSink final : public LogViewerNetworkRPCSinkBase
	{
		friend class SinkFactory; //!< Friend to allow construction only from SinkFactory.
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Destructor.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual ~DelayedLogViewerNetworkRPCSink();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Initializes the sink. Does not do any initialization if the class is already initialized.
		///
		/// \param networkAddress The network address to use.
		///
		/// \exception std::runtime_error Thrown if the connection to the server could not be established.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void initialize(const std::string& networkAddress);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Initializes the sink as dummy. Does not do any initialization if the class is already initialized.
		///		   Initializing as dummy discards all log entries.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void initializeAsDummy();

	private:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// \brief Constructor.
		///
		/// \param sinkName A name for the sink that can be used to identify it.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		DelayedLogViewerNetworkRPCSink(const std::string& sinkName);
	};
}

#pragma warning( pop ) 