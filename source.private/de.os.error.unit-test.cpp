/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.os.error.hpp"

#include "de.log.unit-test.hpp"

#include <string>
#include <regex>

#include <windows.h>

class de__os__error__test : public de__log__test
{
public:

	de__os__error__test( )
		: de__log__test { }
	{
	}

	~de__os__error__test( )
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
};

TEST( de__os__error , get_message_00000000 )
{
	SetLastError( 0 );
	EXPECT_EQ( std::string( de::os::error::get_message( ) ), "GetLastError(00000000)=[The operation completed successfully]" );
}

TEST( de__os__error , get_message_00000001 )
{
	SetLastError( 1 );
	EXPECT_EQ( std::string( de::os::error::get_message( ) ) , "GetLastError(00000001)=[Incorrect function]" );
}

TEST( de__os__error , get_message_0000000A )
{
	SetLastError( 0xA );
	EXPECT_EQ( std::string( de::os::error::get_message( ) ) , "GetLastError(0000000A)=[The environment is incorrect]" );
}

TEST( de__os__error , get_message_FFFFFFF )
{
	SetLastError( 0xFFFFFFFF );
	EXPECT_EQ( std::string( de::os::error::get_message( ) ) , "GetLastError(FFFFFFFF)=[FormatMessageA failed]" );
}

enum class ATOM_result
{
	success ,
	failure
};

static ATOM test_function_ATOM_rv( ATOM_result p_success )
{
	ATOM l_rv = 0;

	if ( p_success == ATOM_result::success )
	{
		l_rv = 1;
	}

	return l_rv;
}

TEST( de__os__error , DE__OS__ERROR__CHECK__ATOM_rv__success )
{
	try
	{
		DE__OS__ERROR__CHECK( 0 == test_function_ATOM_rv( ATOM_result::success ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__os__error , DE__OS__ERROR__CHECK__ATOM_rv__failure )
{
	try
	{
		SetLastError( 1 );
		DE__OS__ERROR__CHECK( 0 == test_function_ATOM_rv( ATOM_result::failure ) );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "de__os__error_DE__OS__ERROR__CHECK__ATOM_rv__failure_Test::TestBody@[0-9]+ \\| Condition indicates failure: 0 == test_function_ATOM_rv\\( ATOM_result::failure \\) \\| GetLastError\\(00000001\\)=\\[Incorrect function\\]" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

enum class BOOL_result
{
	success ,
	failure
};

static BOOL test_function_BOOL_rv( BOOL_result p_success )
{
	BOOL l_rv = FALSE;

	if ( p_success == BOOL_result::success )
	{
		l_rv = TRUE;
	}

	return l_rv;
}

TEST( de__os__error , DE__OS__ERROR__CHECK__BOOL_rv__success )
{
	try
	{
		DE__OS__ERROR__CHECK( FALSE == test_function_BOOL_rv( BOOL_result::success ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__os__error , DE__OS__ERROR__CHECK__BOOL_rv__failure )
{
	try
	{
		SetLastError( 1 );
		DE__OS__ERROR__CHECK( FALSE == test_function_BOOL_rv( BOOL_result::failure ) );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "de__os__error_DE__OS__ERROR__CHECK__BOOL_rv__failure_Test::TestBody@[0-9]+ \\| Condition indicates failure: 0 == test_function_BOOL_rv\\( BOOL_result::failure \\) \\| GetLastError\\(00000001\\)=\\[Incorrect function\\]" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

enum class HRESULT_result
{
	success ,
	failure
};

static HRESULT test_function_HRESULT_rv( HRESULT_result p_success )
{
	HRESULT l_rv = E_FAIL;

	if ( p_success == HRESULT_result::success )
	{
		l_rv = S_OK;
	}

	return l_rv;
}

TEST( de__os__error , DE__OS__ERROR__CHECK__HRESULT_rv__success )
{
	try
	{
		DE__OS__ERROR__CHECK( S_OK != test_function_HRESULT_rv( HRESULT_result::success ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__os__error , DE__OS__ERROR__CHECK__HRESULT_rv__failure )
{
	try
	{
		SetLastError( 1 );
		DE__OS__ERROR__CHECK( S_OK != test_function_HRESULT_rv( HRESULT_result::failure ) );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "de__os__error_DE__OS__ERROR__CHECK__HRESULT_rv__failure_Test::TestBody@[0-9]+ \\| Condition indicates failure: \\(\\(HRESULT\\)0L\\) != test_function_HRESULT_rv\\( HRESULT_result::failure \\) \\| GetLastError\\(00000001\\)=\\[Incorrect function\\]" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__error__test , DE__OS__ERROR__LOG_success )
{
	DE__OS__ERROR__LOG( 0 == test_function_ATOM_rv( ATOM_result::success ) );

	ProcessLog( );

	EXPECT_EQ( m_log_lines.size( ) , 0 );
}

TEST_F( de__os__error__test , DE__OS__ERROR__LOG_failure )
{
	SetLastError( 0xAF );
	DE__OS__ERROR__LOG( 0 == test_function_ATOM_rv( ATOM_result::failure ) );

	ProcessLog( );

	EXPECT_EQ( m_log_lines.size( ) , 1 );

	std::regex re { "de__os__error__test_DE__OS__ERROR__LOG_failure_Test::TestBody@[0-9]+ \\| !EXCEPTION! \\| Program violates condition: 0 == test_function_ATOM_rv\\( ATOM_result::failure \\) \\| GetLastError\\(000000AF\\)=\\[FormatMessageA failed\\]" };

	EXPECT_TRUE( std::regex_match( m_log_lines[ 0 ] , re ) ) << m_log_lines[ 0 ];

	ClearLog( );
}

/* END */
