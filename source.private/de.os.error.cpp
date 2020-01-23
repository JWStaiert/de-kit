/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.error.hpp"

#include "de.exceptions.hpp"

#include <windows.h>

namespace de
{
	namespace os
	{
		/* This code is usually called to populate an exception string or log message so we want to keep this code free of system calls and memory allocations (no std::string or std::stringstream.) */

		static inline char lsB_to_ascii( unsigned int p_value )
		{
			unsigned int l_value = p_value % 16;

			if ( ( 0 <= l_value ) && ( l_value <= 9 ) )
			{
				return static_cast<char>( l_value + '0' );
			}
			else
			{
				return static_cast<char>( ( l_value - 10 ) + 'A' );
			}
		}

		inline void error::concat_buffer( const char * p_string )
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

		/* */
		error::error( )
			: m_buffer { 0 }
		{
			concat_buffer( "GetLastError(####:####) = " );

			DWORD l_last_error = GetLastError( );

			m_buffer[ 13 ] = lsB_to_ascii( l_last_error >> 28 );
			m_buffer[ 14 ] = lsB_to_ascii( l_last_error >> 24 );
			m_buffer[ 15 ] = lsB_to_ascii( l_last_error >> 20 );
			m_buffer[ 16 ] = lsB_to_ascii( l_last_error >> 16 );

			m_buffer[ 18 ] = lsB_to_ascii( l_last_error >> 12 );
			m_buffer[ 19 ] = lsB_to_ascii( l_last_error >>  8 );
			m_buffer[ 20 ] = lsB_to_ascii( l_last_error >>  4 );
			m_buffer[ 21 ] = lsB_to_ascii( l_last_error       );

			if ( !FormatMessageA(
				( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS ) ,
				NULL ,
				l_last_error ,
				MAKELANGID( LANG_NEUTRAL , SUBLANG_DEFAULT ) ,
				& m_buffer[26] ,
				( sizeof( m_buffer ) - 27 ),
				NULL
				) )
			{
				concat_buffer( "FormatMessageA failed." );
			}
			else
			{
				for ( int i = 0 ; i < sizeof( m_buffer ) ; ++i )
				{
					if ( m_buffer[ i ] == 0 )
					{
						/* Strip trailing new-line and carriage return. */
						m_buffer[ --i ] = 0;
						m_buffer[ --i ] = 0;
						break;
					}
				}
			}
		}

		/* */
		error::~error( )
		{
		}
	}
}

/* END */
