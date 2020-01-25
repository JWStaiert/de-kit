#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <stdexcept>

#define DE__EXCEPTIONS__STRINGIFY( value ) #value

#define DE__EXCEPTIONS__TO_STRING( value ) DE__EXCEPTIONS__STRINGIFY( value )

/* */
#define DE__EXCEPTIONS__THROW_RUNTIME_ERROR( message ) throw std::runtime_error( de::exceptions::format( __FUNCTION__ "@" DE__EXCEPTIONS__TO_STRING( __LINE__ ) "| " , message ) )

/* */
#define DE__EXCEPTIONS__CHECK_AND_THROW_RUNTIME_ERROR( expression , message ) if ( expression ) { throw std::runtime_error( de::exceptions::format( __FUNCTION__ "@" DE__EXCEPTIONS__TO_STRING( __LINE__ ) "| " , #expression , message ) ); }

namespace de
{
	namespace exceptions
	{
		const char * format( const char * p_prefix , const char * p_message );

		const char * format( const char * p_prefix , const char * p_expression , const char * p_message );
	}
}

/* END */
