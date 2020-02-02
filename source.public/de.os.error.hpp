#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exception.hpp"
#include "de.log.hpp"

/* */
#define DE__OS__ERROR__CHECK_AND_THROW( expression ) DE__EXCEPTION__CHECK_WITH_MESSAGE( expression , de::os::error::format( ) )

/* */
#define DE__OS__ERROR__CHECK_AND_LOG( expression ) { if ( expression ) { DE__LOG__EXCEPTION( de::exception::format_check_with_message( "" , #expression , de::os::error::format( ) ) ); } }

namespace de
{
	namespace os
	{
		namespace error
		{
			const char * format( );
		}
	}
}

/* END */
