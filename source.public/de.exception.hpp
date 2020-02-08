#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <stdexcept>

#define DE__EXCEPTION__STRINGIFY( value ) #value

#define DE__EXCEPTION__TO_STRING( value ) DE__EXCEPTION__STRINGIFY( value )

#define DE__EXCEPTION__PREFIX __FUNCTION__ "@" DE__EXCEPTION__TO_STRING( __LINE__ ) " | "

/* */
#define DE__EXCEPTION__THROW_LOGIC_ERROR( condition ) throw std::logic_error( de::exception::format_logic_error( DE__EXCEPTION__PREFIX, condition ) )

/* */
#define DE__EXCEPTION__THROW_LOGIC_ERROR_WITH_MESSAGE( condition, message ) throw std::logic_error( de::exception::format_logic_error_with_message( DE__EXCEPTION__PREFIX, condition, message ) )

/* */
#define DE__EXCEPTION__THROW_RUNTIME_ERROR( condition ) throw std::runtime_error( de::exception::format_runtime_error( DE__EXCEPTION__PREFIX, condition ) )

/* */
#define DE__EXCEPTION__THROW_RUNTIME_ERROR_WITH_MESSAGE( condition, message ) throw std::runtime_error( de::exception::format_runtime_error_with_message( DE__EXCEPTION__PREFIX, condition, message ) )

/* */
#define DE__EXCEPTION__ASSERT( assertion )              \
	if ( !( assertion ) )                               \
	{                                                   \
		DE__EXCEPTION__THROW_LOGIC_ERROR( #assertion ); \
	}

/* */
#define DE__EXCEPTION__ASSERT_WITH_MESSAGE( assertion, message )              \
	if ( !( assertion ) )                                                     \
	{                                                                         \
		DE__EXCEPTION__THROW_LOGIC_ERROR_WITH_MESSAGE( #assertion, message ); \
	}

/* */
#define DE__EXCEPTION__CHECK( expression )                 \
	if ( expression )                                      \
	{                                                      \
		DE__EXCEPTION__THROW_RUNTIME_ERROR( #expression ); \
	}

/* */
#define DE__EXCEPTION__CHECK_WITH_MESSAGE( expression, message )                 \
	if ( expression )                                                            \
	{                                                                            \
		DE__EXCEPTION__THROW_RUNTIME_ERROR_WITH_MESSAGE( #expression, message ); \
	}

namespace de
{
	namespace exception
	{
		const char* format_logic_error( const char*, const char* );

		const char* format_logic_error_with_message( const char*, const char*, const char* );

		const char* format_runtime_error( const char*, const char* );

		const char* format_runtime_error_with_message( const char*, const char*, const char* );
	}
}

/* END */
