#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <memory>
#include <mutex>
#include <ostream>
#include <string>

#include <cstdint>

#include "de.exceptions.hpp"

/* */
#define DE_LOG_INFO( expression ) { std::lock_guard<std::mutex> lock { de::log::stream.mutex }; if ( de::log::stream.ptr != nullptr ) { *(de::log::stream.ptr) << expression ; de::log::stream.ptr->flush( ); } }

/* */
#define DE_LOG_WARNING( expression ) { std::lock_guard<std::mutex> lock { de::log::stream.mutex }; if ( de::log::stream.ptr != nullptr ) { *(de::log::stream.ptr) << __FUNCTION__ << "@" << __LINE__ << "| " << expression ; de::log::stream.ptr->flush( ); } }

/* */
#define DE_LOG_EXCEPTION( expression ) { std::lock_guard<std::mutex> lock { de::log::stream.mutex }; if ( de::log::stream.ptr != nullptr ) { *(de::log::stream.ptr) << __FUNCTION__ << "@" << __LINE__ << "| !" << "EXCEPTION" << "! " << expression ; de::log::stream.ptr->flush( ); } }

namespace de
{
	namespace log
	{
		struct alignas (256) _stream
		{
			std::mutex mutex;

			std::byte _padding0[ 128 - sizeof( std::mutex ) ];

			std::ostream * ptr;

			std::byte _padding1[ 128 - sizeof( std::ostream * ) ];
		};
		
		extern de::log::_stream stream;

		void start( const std::string & pathname );

		void stop( );
	}
}

/* END */
