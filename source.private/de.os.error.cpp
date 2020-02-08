/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.error.hpp"

#include <de.util.hpp>

#include <Windows.h>

namespace de
{
	namespace os
	{
		namespace error
		{
			/* JWS: This code will be called to populate an exception string so
			 * it must be thread safe and free of system calls and memory
			 * allocations. */

			/* thread_local makes access thread safe. */
			static thread_local de::util::cstring_array<4096 - sizeof( de::util::cstring_basic )> s_buffer;

			const char* get_message( )
			{
				DWORD l_last_error = GetLastError( );

				s_buffer.reset( );
				s_buffer.append_cstring( "GetLastError(" );
				s_buffer.append_hexadecimal( static_cast<std::uint32_t>( l_last_error ) );
				s_buffer.append_cstring( ")=[" );

				char l_buffer[ 2048 ]{ 0 };

				if ( !FormatMessageA( ( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS ), NULL, l_last_error, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), l_buffer, sizeof( l_buffer ), NULL ) )
				{
					s_buffer.append_cstring( "FormatMessageA failed" );
				}
				else
				{
					for ( int i = 0; i < sizeof( l_buffer ); ++i )
					{
						/* Strip trailing period, carriage return, and newline.
						 */
						if ( l_buffer[ i ] == '.' || l_buffer[ i ] == '\r' || l_buffer[ i ] == '\n' )
						{
							l_buffer[ i ] = 0;
							break;
						}
					}

					s_buffer.append_cstring( l_buffer );
				}

				s_buffer.append_cstring( "]" );

				return s_buffer;
			}
		}
	}
}

/* END */
