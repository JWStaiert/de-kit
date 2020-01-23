/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.module.hpp"

#include "de.exceptions.hpp"
#include "de.log.hpp"
#include "de.os.error.hpp"

#include <windows.h>

namespace de
{
	namespace os
	{
		/* */
		void module::set_search_path( const std::string & p_path )
		{
			if ( !SetDllDirectoryA( p_path.c_str( ) ) )
			{
				DE_THROW_RUNTIME_ERROR( de::os::error { } );
			}
		}

		/* */
		module::module( const std::string & p_pathname )
			: m_module { nullptr }
		{
			HMODULE l_module = LoadLibraryA( p_pathname.c_str( ) );

			if ( l_module == NULL )
			{
				DE_THROW_RUNTIME_ERROR( de::os::error { } );
			}

			m_module = static_cast<void *>( l_module );
		}

		/* */
		module::~module( )
		{
			HMODULE l_module = static_cast<HMODULE>( m_module );

			if ( !FreeLibrary( l_module ) )
			{
				DE_LOG_EXCEPTION( "FreeLibrary failed. " << de::os::error { } );
			}
		}

		/* */
		void * module::get_function_address( const std::string & p_name )
		{
			HMODULE l_module = static_cast<HMODULE>( m_module );

			FARPROC l_proc = GetProcAddress( l_module , p_name.c_str( ) );

			if ( l_proc == NULL )
			{
				DE_THROW_RUNTIME_ERROR( de::os::error { } );
			}

			return static_cast<void *>( l_proc );
		}
	}
}

/* END */
