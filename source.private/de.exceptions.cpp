/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exceptions.hpp"

#include "de.util.hpp"

namespace de
{
	namespace exceptions
	{
		/* JWS: This code will be called to populate an exception string so it must be thread safe and free of system calls and memory allocations. */

		/* thread_local makes access thread safe. */
		static thread_local de::util::cstring_array<4096 - sizeof( de::util::cstring_basic )> s_buffer;

		const char * format( const char * p_prefix , const char * p_message )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( p_message );
			return s_buffer;
		}

		const char * format( const char * p_prefix , const char * p_expression , const char * p_message )
		{
			s_buffer.reset( );
			s_buffer.append_cstring( p_prefix );
			s_buffer.append_cstring( "Expression (" );
			s_buffer.append_cstring( p_expression );
			s_buffer.append_cstring( ") indicates failure. " );
			s_buffer.append_cstring( p_message );
			return s_buffer;
		}
	}
}

/* END */
