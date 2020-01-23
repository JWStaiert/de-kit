#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <string>
#include <vector>

class de__os__module__test;

namespace de
{
	namespace os
	{
		class module
		{
			friend class de__os__module__test;

			void * m_module;

		public:

			static void set_search_path( const std::string & p_path );

			module( ) = delete;

			module( const std::string & p_pathname );

			module( const module & ) = delete;

			~module( );

			module & operator=( const module & ) = delete;

			void * get_function_address( const std::string & p_name );

		};
	}
}

/* END */
