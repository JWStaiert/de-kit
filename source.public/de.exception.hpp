#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <stdexcept>

#define DE__EXCEPTION__STRINGIFY( value ) #value

#define DE__EXCEPTION__TO_STRING( value ) DE__EXCEPTION__STRINGIFY( value )

/* */
#define DE__EXCEPTION__ASSERT( assertion ) if ( ! ( assertion ) ) { throw std::logic_error( de::exception::format_assertion( __FUNCTION__ "@" DE__EXCEPTION__TO_STRING( __LINE__ ) "| " , #assertion ) ); }

/* */
#define DE__EXCEPTION__ASSERT_WITH_MESSAGE( assertion , message ) if ( ! ( assertion ) ) { throw std::logic_error( de::exception::format_assertion_with_message( __FUNCTION__ "@" DE__EXCEPTION__TO_STRING( __LINE__ ) "| " , #assertion , message ) ); }

/* */
#define DE__EXCEPTION__CHECK( expression ) if ( expression ) { throw std::runtime_error( de::exception::format_check( __FUNCTION__ "@" DE__EXCEPTION__TO_STRING( __LINE__ ) "| " , #expression ) ); }

/* */
#define DE__EXCEPTION__CHECK_WITH_MESSAGE( expression , message ) if ( expression ) { throw std::runtime_error( de::exception::format_check_with_message( __FUNCTION__ "@" DE__EXCEPTION__TO_STRING( __LINE__ ) "| " , #expression , message ) ); }

namespace de
{
	namespace exception
	{
		const char * format_assertion( const char * p_prefix , const char * p_assertion );

		const char * format_assertion_with_message( const char * p_prefix , const char * p_assertion , const char * p_message );

		const char * format_check( const char * p_prefix , const char * p_expression );

		const char * format_check_with_message( const char * p_prefix , const char * p_expression , const char * p_message );
	}
}

/* END */
