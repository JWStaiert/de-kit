/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.os.module.hpp"

#include "de.log.hpp"
#include "de.log.unit-test.hpp"
#include "de.unit-test.hpp"

#include <string>
#include <regex>

#include <windows.h>

class de__os__module__test : public de__log__test
{
public:

	de__os__module__test( )
		: de__log__test { }
	{
	}

	~de__os__module__test( )
	{
	}

	void SetUp( )
	{
		de__log__test::SetUp( );

		de::log::start( "stdout" );
	}

	void TearDown( )
	{
		de::log::stop( );

		de__log__test::TearDown( );
	}

	void * GetModulePtr( de::os::module & p_uut )
	{
		return p_uut.m_module;
	}

	void SetModulePtr( de::os::module & p_uut , void * p_value )
	{
		p_uut.m_module = p_value;
	}

};

TEST_F( de__os__module__test , _ctor_failure )
{
	try
	{
		de::os::module uut { "" };

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		std::regex re { "de::os::module::module@[0-9]+\\| Expression \\(l_module == NULL\\) indicates failure\\. GetLastError\\(00000057\\)=\\[The parameter is incorrect\\]\\." };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test , _dtor_failure )
{
	HMODULE l_module = NULL;

	try
	{
		{
			de::os::module uut { DE_TEST_MODULE_PATHNAME };

			l_module = static_cast<HMODULE>( GetModulePtr( uut ) );

			SetModulePtr( uut , nullptr );
		}

		ProcessLog( );

		EXPECT_EQ( m_log_lines.size( ) , 1 );

		std::regex re { "de::os::module::~module@[0-9]+\\| !EXCEPTION! Expression \\(!FreeLibrary\\( l_module \\)\\) indicates failure\\. GetLastError\\(0000007E\\)=\\[The specified module could not be found\\]\\." };

		EXPECT_TRUE( std::regex_match( m_log_lines[ 0 ] , re ) ) << m_log_lines[ 0 ];
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}

	if ( l_module != NULL )
	{
		FreeModule( l_module );
	}
}

TEST_F( de__os__module__test , _get_function_address_failure )
{
	try
	{
		de::os::module uut { DE_TEST_MODULE_PATHNAME };

		uut.get_function_address( "" );

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		std::regex re { "de::os::module::get_function_address@[0-9]+\\| Expression \\(l_proc == NULL\\) indicates failure\\. GetLastError\\(0000007F\\)=\\[The specified procedure could not be found\\]\\." };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test , _get_function_address_success )
{
	EXPECT_NO_THROW( { de::os::module uut { DE_TEST_MODULE_PATHNAME }; uut.get_function_address( "vkGetInstanceProcAddr" ); } );
}

/* END */
