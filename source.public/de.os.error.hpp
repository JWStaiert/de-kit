#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

namespace de
{
	namespace os
	{
		class error
		{
			char m_buffer[ 1204 ];

			inline void concat_buffer( const char * p_string );

		public:

			error( );

			error( const error & ) = delete;

			~error( );

			error & operator=( const error & ) = delete;

			operator const char *( ) const { return m_buffer; }
		};
	}
}

/* END */
