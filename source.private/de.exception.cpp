/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exception.hpp"

#include "de.util.hpp"

namespace de
{
	namespace exception
	{
		/* JWS: This code will be called to populate an exception string so it must be thread safe and free of system calls and memory allocations. */

		/* thread_local makes access thread safe. */
		static thread_local de::util::cstring_array<4096 - sizeof( de::util::cstring_basic )> s_buffer;

		const char * format_assertion( const char * p_prefix , const char * p_assertion )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( "Program violates assertion: " );
			s_buffer.append_cstring( p_assertion );
			return s_buffer;
		}

		const char * format_assertion_with_message( const char * p_prefix , const char * p_assertion , const char * p_message )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( "Program violates assertion: " );
			s_buffer.append_cstring( p_assertion );
			s_buffer.append_cstring( " | " );
			s_buffer.append_cstring( p_message );
			return s_buffer;
		}

		const char * format_check( const char * p_prefix , const char * p_expression )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( "Expression indicates failure: " );
			s_buffer.append_cstring( p_expression );
			return s_buffer;
		}

		const char * format_check_with_message( const char * p_prefix , const char * p_expression , const char * p_message )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( "Expression indicates failure: " );
			s_buffer.append_cstring( p_expression );
			s_buffer.append_cstring( " | " );
			s_buffer.append_cstring( p_message );
			return s_buffer;
		}
	}
}

/* END */
