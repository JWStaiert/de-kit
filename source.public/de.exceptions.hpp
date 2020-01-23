#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <stdexcept>

#define DE_THROW_STRINGIFY( value ) #value

#define DE_THROW_TO_STRING( value ) DE_THROW_STRINGIFY( value )

#define DE_THROW_EXCEPTION( message ) de::exception { __FUNCTION__ , DE_THROW_TO_STRING( __LINE__ ) , message }

/* */
#define DE_THROW_RUNTIME_ERROR( message ) throw std::runtime_error( DE_THROW_EXCEPTION( message ) )

namespace de
{
	class exception
	{
		char m_buffer[ 4096 ];

		inline void concat_buffer( const char * p_string );

		inline void initialize_buffer( const char * p_function , const char * p_line , const char * p_message );

	public:

		exception( const char * p_function , const char * p_line , const char * p_message );

		exception( const char * p_function , const char * p_line , const std::string & p_message );

		exception( const exception & ) = delete;

		~exception( );

		exception & operator=( const exception & ) = delete;

		operator const char *( ) const { return m_buffer; }

	};
}

/* END */
