#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.exception.hpp>

#include <filesystem>
#include <memory>
#include <mutex>
#include <ostream>

#include <cstdint>

/* */
#define DE__LOG__INFO( expression )                                \
	{                                                              \
		std::lock_guard<std::mutex> lock{ de::log::stream.mutex }; \
		if ( de::log::stream.ptr != nullptr )                      \
		{                                                          \
			*( de::log::stream.ptr ) << expression;                \
			de::log::stream.ptr->flush( );                         \
		}                                                          \
	}

/* */
#define DE__LOG__WARNING( expression )                                       \
	{                                                                        \
		std::lock_guard<std::mutex> lock{ de::log::stream.mutex };           \
		if ( de::log::stream.ptr != nullptr )                                \
		{                                                                    \
			*( de::log::stream.ptr ) << DE__EXCEPTION__PREFIX << expression; \
			de::log::stream.ptr->flush( );                                   \
		}                                                                    \
	}

/* */
#define DE__LOG__EXCEPTION( expression )                                                         \
	{                                                                                            \
		std::lock_guard<std::mutex> lock{ de::log::stream.mutex };                               \
		if ( de::log::stream.ptr != nullptr )                                                    \
		{                                                                                        \
			*( de::log::stream.ptr ) << DE__EXCEPTION__PREFIX << "!EXCEPTION! | " << expression; \
			de::log::stream.ptr->flush( );                                                       \
		}                                                                                        \
	}

namespace de
{
	namespace log
	{
		struct alignas( 256 ) _stream
		{
			std::mutex mutex;

			std::byte _padding0[ 128 - sizeof( std::mutex ) ];

			std::ostream* ptr;

			std::byte _padding1[ 128 - sizeof( std::ostream* ) ];
		};

		extern de::log::_stream stream;

		void start( const std::filesystem::path& pathname );

		void stop( );
	}
}

/* END */
