/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.module.hpp"

#include "de.os.error.hpp"

#include <windows.h>

namespace de
{
	namespace os
	{
		/* */
		module::module( const std::string & p_pathname )
			: m_module { nullptr }
		{
			HMODULE l_module = LoadLibraryA( p_pathname.c_str( ) );

			DE__OS__ERROR__CHECK_AND_THROW( l_module == NULL );

			m_module = static_cast<void *>( l_module );
		}

		/* */
		module::~module( )
		{
			HMODULE l_module = static_cast<HMODULE>( m_module );

			DE__OS__ERROR__CHECK_AND_LOG( !FreeLibrary( l_module ) );
		}

		/* */
		void * module::get_function_address( const std::string & p_name )
		{
			HMODULE l_module = static_cast<HMODULE>( m_module );

			FARPROC l_proc = GetProcAddress( l_module , p_name.c_str( ) );

			DE__OS__ERROR__CHECK_AND_THROW( l_proc == NULL );

			return static_cast<void *>( l_proc );
		}
	}
}

/* END */
