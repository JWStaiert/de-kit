#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <filesystem>
#include <new>
#include <vector>

class de__os__module__test_fixture;

namespace de
{
	namespace os
	{
		class module
		{
			friend class de__os__module__test_fixture;

			void* m_module;

		public:
			module( ) = delete;

			module( const std::filesystem::path& p_pathname );

			module( const module& ) = delete;

			module( module&& ) = delete;

			~module( );

			module& operator=( const module& ) = delete;

			module& operator=( module&& ) = delete;

			void* get_function_address( const std::string& p_name );
		};
	}
}

/* END */
