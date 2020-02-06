#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exception.hpp"
#include "de.log.hpp"

/* */
#define DE__OS__ERROR__CHECK( expression ) DE__EXCEPTION__CHECK_WITH_MESSAGE( expression , de::os::error::get_message( ) )

/* */
#define DE__OS__ERROR__LOG( expression ) { if ( expression ) { DE__LOG__EXCEPTION( de::exception::format_logic_error_with_message( "" , #expression , de::os::error::get_message( ) ) ); } }

namespace de
{
	namespace os
	{
		namespace error
		{
			const char * get_message( );
		}
	}
}

/* END */
