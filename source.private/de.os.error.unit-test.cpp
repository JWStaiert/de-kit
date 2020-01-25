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

TEST( de__os__error , format_00000000 )
{
	SetLastError( 0 );
	EXPECT_EQ( std::string( de::os::error::format( "null" ) ), "Expression (null) indicates failure. GetLastError(00000000)=[The operation completed successfully]." );
}

TEST( de__os__error , format_00000001 )
{
	SetLastError( 1 );
	EXPECT_EQ( std::string( de::os::error::format( "null" ) ) , "Expression (null) indicates failure. GetLastError(00000001)=[Incorrect function]." );
}

TEST( de__os__error , format_0000000A )
{
	SetLastError( 0xA );
	EXPECT_EQ( std::string( de::os::error::format( "null" ) ) , "Expression (null) indicates failure. GetLastError(0000000A)=[The environment is incorrect]." );
}

TEST( de__os__error , format_FFFFFFF )
{
	SetLastError( 0xFFFFFFFF );
	EXPECT_EQ( std::string( de::os::error::format( "null" ) ) , "Expression (null) indicates failure. GetLastError(FFFFFFFF)=[FormatMessageA failed]." );
}

TEST( de__os__error , _DE__OS__ERROR__CHECK_AND_THROW_success )
{
	try
	{
		DE__OS__ERROR__CHECK_AND_THROW( false );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__os__error , _DE__OS__ERROR__CHECK_AND_THROW_failure )
{
	try
	{
		SetLastError( 1 );
		DE__OS__ERROR__CHECK_AND_THROW( true );

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		std::regex re { "de__os__error__DE__OS__ERROR__CHECK_AND_THROW_failure_Test::TestBody@[0-9]+\\| Expression \\(true\\) indicates failure\\. GetLastError\\(00000001\\)=\\[Incorrect function\\]\\." };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST_F( de__os__error__test , _DE__OS__ERROR__CHECK_AND_LOG_success )
{
	DE__OS__ERROR__CHECK_AND_LOG( false );

	ProcessLog( );

	EXPECT_EQ( m_log_lines.size( ) , 0 );
}

TEST_F( de__os__error__test , _DE__OS__ERROR__CHECK_AND_LOG_failure )
{
	SetLastError( 0xAF );
	DE__OS__ERROR__CHECK_AND_LOG( true );

	ProcessLog( );

	EXPECT_EQ( m_log_lines.size( ) , 1 );

	std::regex re { "de__os__error__test__DE__OS__ERROR__CHECK_AND_LOG_failure_Test::TestBody@[0-9]+\\| !EXCEPTION! Expression \\(true\\) indicates failure\\. GetLastError\\(000000AF\\)=\\[FormatMessageA failed\\]\\." };

	EXPECT_TRUE( std::regex_match( m_log_lines[ 0 ] , re ) ) << m_log_lines[ 0 ];
}

/* END */
