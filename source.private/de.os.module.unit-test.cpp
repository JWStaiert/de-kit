/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.os.module.hpp"

#include <de.log.hpp>

#include <unit-test.de.hpp>
#include <unit-test.de.log.hpp>

#include <regex>
#include <string>

#include <Windows.h>

class de__os__module__test_fixture : public de__log__test_fixture
{
public:
	de__os__module__test_fixture( )
		: de__log__test_fixture{}
	{
	}

	~de__os__module__test_fixture( )
	{
	}

	void SetUp( )
	{
		de__log__test_fixture::SetUp( );

		de::log::start( "stdout" );
	}

	void TearDown( )
	{
		de::log::stop( );

		de__log__test_fixture::TearDown( );
	}

	void* GetModulePtr( de::os::module& p_uut )
	{
		return p_uut.m_module;
	}

	void SetModulePtr( de::os::module& p_uut, void* p_value )
	{
		p_uut.m_module = p_value;
	}
};

TEST_F( de__os__module__test_fixture, ctor_failure )
{
	try
	{
		de::os::module uut{ "" };

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de::os::module::module@[0-9]+ \\| Condition indicates failure: l_module == 0 \\| GetLastError\\(00000057\\)=\\[The parameter is incorrect\\]" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test_fixture, dtor_failure )
{
	HMODULE l_module = NULL;

	try
	{
		{
			de::os::module uut{ DE_TEST_MODULE_PATHNAME };

			l_module = static_cast<HMODULE>( GetModulePtr( uut ) );

			SetModulePtr( uut, nullptr );
		}

		ProcessLog( );

		EXPECT_EQ( m_log_lines.size( ), 1 );

		std::regex re{ "de::os::module::~module@[0-9]+ \\| !EXCEPTION! \\| Program violates condition: !FreeLibrary\\( l_module \\) \\| GetLastError\\(0000007E\\)=\\[The specified module could not be found\\]" };

		EXPECT_TRUE( std::regex_match( m_log_lines[ 0 ], re ) ) << m_log_lines[ 0 ];

		ClearLog( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}

	if ( l_module != NULL )
	{
		FreeLibrary( l_module );
	}
}

TEST_F( de__os__module__test_fixture, get_function_address_failure )
{
	try
	{
		de::os::module uut{ DE_TEST_MODULE_PATHNAME };

		uut.get_function_address( "" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de::os::module::get_function_address@[0-9]+ \\| Condition indicates failure: l_proc == 0 \\| GetLastError\\(0000007F\\)=\\[The specified procedure could not be found\\]" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__module__test_fixture, _get_function_address_success )
{
	EXPECT_NO_THROW( {
		de::os::module uut{ DE_TEST_MODULE_PATHNAME };
		uut.get_function_address( "vkGetInstanceProcAddr" );
	} );
}

#if 0
// JWS: new/delete testing. This belongs in a new/delete test.
TEST( de__os__module, operator_new )
{
	try
	{
		/* new */
		de::os::module* uut_new = new de::os::module{ DE_TEST_MODULE_PATHNAME };

		delete uut_new;

		/* new array */
		de::os::module* uut_new_array = new de::os::module[ 4 ]{ { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME } };

		delete[] uut_new_array;

		/* no throw new */
		de::os::module* uut_new_no_throw = new ( std::nothrow ) de::os::module{ DE_TEST_MODULE_PATHNAME };

		delete uut_new_no_throw;

		/* no throw new array */
		de::os::module* uut_new_no_throw_array = new ( std::nothrow ) de::os::module[ 4 ]{ { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME } };

		delete[] uut_new_no_throw_array;

		/* placement new */
		alignas( de::os::module ) std::uint8_t uut_new_placement_memory[ sizeof( de::os::module ) ];

		de::os::module* uut_new_placement = new ( uut_new_placement_memory ) de::os::module{ DE_TEST_MODULE_PATHNAME };

		uut_new_placement->~module( );

		/* placement new array */
		alignas( de::os::module[4] ) std::uint8_t uut_new_placement_array_memory[ sizeof( de::os::module ) * 4 ];

		// JWS: Placement array new adds overhead, two bytes on my development system. This causes the line below to overrun
		// uut_new_placement_array_memory and thus corrupt the stack. Overhead added by array new operators is allowed by
		// the standard but is not specified, so there isn't a portable (or even future proof) way of sizing
		// uut_new_placement_array_memory. If placement array new is needed, then it will be necessary to override placement
		// array new and placement array delete to guarantee overhead byte count. Note: the overheadd bytes may be used by
		// array new implementations to record the number of elements in the array that have had their constructors called,
		// which allows delete to call the destructor only on those elements that have been constructed in situations where
		// explicit destructor calls are not possible (as when array new encounters an exception.)
		de::os::module* uut_new_placement_array = new ( uut_new_placement_array_memory ) de::os::module[ 4 ]{ { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME }, { DE_TEST_MODULE_PATHNAME } };

		EXPECT_EQ( static_cast<void*>( uut_new_placement_array_memory ), static_cast<void*>( uut_new_placement_array ) ); // JWS: This fails.

		uut_new_placement_array[ 0 ].~module( );
		uut_new_placement_array[ 1 ].~module( );
		uut_new_placement_array[ 2 ].~module( );
		uut_new_placement_array[ 3 ].~module( );

		SUCCEED( );
	}
	catch ( std::exception& exc )
	{
		FAIL( ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}
#endif

/* END */
