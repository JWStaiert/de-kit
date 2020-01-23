/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exceptions.hpp"

namespace de
{
	/* This code is called to populate an exception string so we want to keep this code free of system calls and memory allocations (no std::string or std::stringstream.) */

	inline void exception::concat_buffer( const char * p_string )
	{
		auto i = 0;

		while ( ( i < ( sizeof( m_buffer ) - 1 ) ) && ( m_buffer[ i ] != 0 ) )
		{
			i++;
		}

		auto j = 0;

		while ( ( i < ( sizeof( m_buffer ) - 1 ) ) && ( ( m_buffer[ i ] = p_string[ j ] ) != 0 ) )
		{
			i++;
			j++;
		}
	}

	inline void exception::initialize_buffer( const char * p_function , const char * p_line , const char * p_message )
	{
		concat_buffer( p_function );
		concat_buffer( " @ " );
		concat_buffer( p_line );
		concat_buffer( " | " );
		concat_buffer( p_message );
	}

	exception::exception( const char * p_function , const char * p_line , const char * p_message )
		: m_buffer { 0 }
	{
		initialize_buffer( p_function , p_line , p_message );
	}

	exception::exception( const char * p_function , const char * p_line , const std::string & p_message )
		: m_buffer { 0 }
	{
		initialize_buffer( p_function , p_line , p_message.c_str( ) );
	}

	exception::~exception( )
	{
	}
}

/* END */
