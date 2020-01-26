#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exception.hpp"
#include "de.log.hpp"

/* */
#define DE__OS__ERROR__CHECK_AND_THROW( expression ) { if ( expression ) { DE__EXCEPTION__THROW_RUNTIME_ERROR( de::os::error::format( #expression ) ); } }

/* */
#define DE__OS__ERROR__CHECK_AND_LOG( expression ) { if ( expression ) { DE__LOG__EXCEPTION( de::os::error::format( #expression ) ); } }

namespace de
{
	namespace os
	{
		namespace error
		{
			const char * format( const char * p_expression );
		}
	}
}

/* END */
