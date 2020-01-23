/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.os.module.hpp"

#include "de.log.hpp"

#include <string>
#include <regex>

#include <windows.h>

static const std::string DE_TEST_MODULE_PATH { "../../targets/active/debug/bin/" };

static const std::string DE_TEST_MODULE_NAME { "vulkan-1.dll" };

static const std::string DE_TEST_MODULE_PATHNAME { DE_TEST_MODULE_PATH + DE_TEST_MODULE_NAME };

class de__os__module__test : public testing::Test
{
	std::streambuf * m_sbuf;

protected:

	std::stringstream m_log;

public:

	de__os__module__test( )
		: m_log { }
	{
		/* Save std::cout buffer. */
		m_sbuf = std::cout.rdbuf( );

		/* Set std::cout to our stringstream buffer. */
		std::cout.rdbuf( m_log.rdbuf( ) );
	}

	~de__os__module__test( )
	{
		/* Restore std::cout. */
		std::cout.rdbuf( m_sbuf );
	}

	void SetUp( )
	{
		de::log::start( "stdout" );
	}

	void TearDown( )
	{
		de::log::stop( );
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

TEST_F( de__os__module__test , ctor_throws )
{
	try
	{
		de::os::module uut { "" };

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		std::regex re { "de::os::module::module @ [0-9]+ \\| GetLastError\\(0000:0057\\) = The parameter is incorrect\\." };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test , get_function_address_throws )
{
	try
	{
		de::os::module uut { DE_TEST_MODULE_PATHNAME };

		uut.get_function_address( "" );

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		std::regex re { "de::os::module::get_function_address @ [0-9]+ \\| GetLastError\\(0000:007F\\) = The specified procedure could not be found\\." };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test , get_function_address )
{
	EXPECT_NO_THROW( { de::os::module uut { DE_TEST_MODULE_PATHNAME }; uut.get_function_address( "vkGetInstanceProcAddr" ); } );
}

TEST_F( de__os__module__test , dtor_logs_exception_on_error )
{
	HMODULE l_module = NULL;

	try
	{
		{
			de::os::module uut { DE_TEST_MODULE_PATHNAME };

			l_module = static_cast<HMODULE>( GetModulePtr( uut ) );

			SetModulePtr( uut , nullptr );
		}

		std::string l_line;
		std::vector<std::string> l_line_vector;

		while ( std::getline( m_log , l_line ) )
		{
			l_line_vector.push_back( l_line );
		}

		EXPECT_EQ( l_line_vector.size( ) , 1 );

		std::regex re { "de::os::module::~module @ [0-9]+ \\| !EXCEPTION! FreeLibrary failed. GetLastError\\(0000:007E\\) = The specified module could not be found\\." };

		EXPECT_TRUE( std::regex_match( l_line_vector[ 0 ] , re ) ) << l_line_vector[ 0 ];
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

TEST_F( de__os__module__test , set_search_path )
{
	try
	{
		de::os::module::set_search_path( DE_TEST_MODULE_PATH );

		de::os::module uut { DE_TEST_MODULE_NAME };

		uut.get_function_address( "vkGetInstanceProcAddr" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
