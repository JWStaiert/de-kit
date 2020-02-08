#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <string>

namespace de
{
	namespace os
	{
		namespace string
		{
			std::string UTF16_to_UTF8( const std::wstring& );

			std::wstring UTF8_to_UTF16( const std::string& );
		}
	}
}

/* END */
