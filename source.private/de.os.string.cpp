/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.os.error.hpp>
#include <de.os.string.hpp>

#include <Windows.h>

namespace de
{
	namespace os
	{
		namespace string
		{
			std::string UTF16_to_UTF8( const std::wstring& p_wide_str )
			{
				std::string l_mb_str{};

				if ( p_wide_str.size( ) > 0 )
				{
					int l_mb_str_size = 0;

					DE__OS__ERROR__CHECK( ( l_mb_str_size = WideCharToMultiByte( CP_UTF8, 0, p_wide_str.c_str( ), -1, NULL, 0, NULL, NULL ) ) == 0 );

					// JWS: l_mb_str_size includes terminating null (due to chMultiByte == -1 in WideCharToMultiByte call). It must be removed or the
					// converted string will include the null which breaks std::string and std::wstring.
					l_mb_str_size -= 1;

					l_mb_str.resize( l_mb_str_size );

					DE__OS__ERROR__CHECK( WideCharToMultiByte( CP_UTF8, 0, p_wide_str.c_str( ), l_mb_str_size, l_mb_str.data( ), l_mb_str_size, NULL, NULL ) == 0 );
				}

				return l_mb_str;
			}

			std::wstring UTF8_to_UTF16( const std::string& p_mb_str )
			{
				std::wstring l_wide_str{};

				if ( p_mb_str.size( ) > 0 )
				{
					int l_wide_str_size = 0;

					DE__OS__ERROR__CHECK( ( l_wide_str_size = MultiByteToWideChar( CP_UTF8, 0, p_mb_str.c_str( ), -1, NULL, 0 ) ) == 0 );

					// JWS: l_wide_str_size includes terminating null (due to chMultiByte == -1 in WideCharToMultiByte call). It must be removed or the
					// converted string will include the null which breaks std::string and std::wstring.
					l_wide_str_size -= 1;

					l_wide_str.resize( l_wide_str_size );

					DE__OS__ERROR__CHECK( MultiByteToWideChar( CP_UTF8, 0, p_mb_str.c_str( ), l_wide_str_size, l_wide_str.data( ), l_wide_str_size ) == 0 );
				}

				return l_wide_str;
			}
		}
	}
}

/* END */
