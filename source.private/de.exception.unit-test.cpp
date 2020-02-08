/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.exception.hpp"

#include <regex>
#include <string>

#define UUT_INT_VALUE 9

TEST( de__exception, DE__EXCEPTION__STRINGIFY_works )
{
	EXPECT_EQ( std::string{ DE__EXCEPTION__STRINGIFY( UUT_INT_VALUE ) }, "UUT_INT_VALUE" );
}

TEST( de__exception, DE__EXCEPTION__TO_STRING_works )
{
	EXPECT_EQ( std::string{ DE__EXCEPTION__TO_STRING( UUT_INT_VALUE ) }, "9" );
}

TEST( de__exception, DE__EXCEPTION__PREFIX_works )
{
	EXPECT_EQ( std::string{ DE__EXCEPTION__PREFIX }, "de__exception_DE__EXCEPTION__PREFIX_works_Test::TestBody@24 | " );
}

TEST( de__exception, format_logic_error )
{
	EXPECT_EQ( std::string{ de::exception::format_logic_error( "prefix", "condition" ) }, "prefixProgram violates condition: condition" );
}

TEST( de__exception, format_logic_error_with_message )
{
	EXPECT_EQ( std::string{ de::exception::format_logic_error_with_message( "prefix", "condition", "message" ) }, "prefixProgram violates condition: condition | message" );
}

TEST( de__exception, format_runtime_error )
{
	EXPECT_EQ( std::string{ de::exception::format_runtime_error( "prefix", "condition" ) }, "prefixCondition indicates failure: condition" );
}

TEST( de__exception, format_runtime_error_with_message )
{
	EXPECT_EQ( std::string{ de::exception::format_runtime_error_with_message( "prefix", "condition", "message" ) }, "prefixCondition indicates failure: condition | message" );
}

TEST( de__exception, DE__EXCEPTION__THROW_LOGIC_ERROR_throws )
{
	try
	{
		DE__EXCEPTION__THROW_LOGIC_ERROR( "a != b" );
	}
	catch ( const std::logic_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__THROW_LOGIC_ERROR_throws_Test::TestBody@[0-9]+ \\| Program violates condition: a != b" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__THROW_LOGIC_ERROR_WITH_MESSAGE_throws )
{
	try
	{
		DE__EXCEPTION__THROW_LOGIC_ERROR_WITH_MESSAGE( "a != b", "message" );
	}
	catch ( const std::logic_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__THROW_LOGIC_ERROR_WITH_MESSAGE_throws_Test::TestBody@[0-9]+ \\| Program violates condition: a != b \\| message" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__THROW_RUNTIME_ERROR_throws )
{
	try
	{
		DE__EXCEPTION__THROW_RUNTIME_ERROR( "a != b" );
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__THROW_RUNTIME_ERROR_throws_Test::TestBody@[0-9]+ \\| Condition indicates failure: a != b" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__THROW_RUNTIME_ERROR_WITH_MESSAGE_throws )
{
	try
	{
		DE__EXCEPTION__THROW_RUNTIME_ERROR_WITH_MESSAGE( "a != b", "message" );
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__THROW_RUNTIME_ERROR_WITH_MESSAGE_throws_Test::TestBody@[0-9]+ \\| Condition indicates failure: a != b \\| message" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

static int frp( int p_parameter )    // JWS: frp = Function Returns Parameter. Compiler should refuse to compile constant conditions, when it does, wrap one expression argument in a call to this function.
{
	return p_parameter;
}

TEST( de__exception, DE__EXCEPTION__ASSERT_success )
{
	try
	{
		DE__EXCEPTION__ASSERT( 0 < frp( 1 ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__ASSERT_failure )
{
	try
	{
		DE__EXCEPTION__ASSERT( 1 < frp( 0 ) );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::logic_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__ASSERT_failure_Test::TestBody@[0-9]+ \\| Program violates condition: 1 < frp\\( 0 \\)" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__ASSERT_WITH_MESSAGE_success )
{
	try
	{
		DE__EXCEPTION__ASSERT_WITH_MESSAGE( 0 < frp( 1 ), "message" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__ASSERT_WITH_MESSAGE_failure )
{
	try
	{
		DE__EXCEPTION__ASSERT_WITH_MESSAGE( 1 < frp( 0 ), "message" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::logic_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__ASSERT_WITH_MESSAGE_failure_Test::TestBody@[0-9]+ \\| Program violates condition: 1 < frp\\( 0 \\) \\| message" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__CHECK_success )
{
	try
	{
		DE__EXCEPTION__CHECK( false );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__CHECK_failure )
{
	try
	{
		DE__EXCEPTION__CHECK( true );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__CHECK_failure_Test::TestBody@[0-9]+ \\| Condition indicates failure: true" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__CHECK_WITH_MESSAGE_success )
{
	try
	{
		DE__EXCEPTION__CHECK_WITH_MESSAGE( false, "message" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception, DE__EXCEPTION__CHECK_WITH_MESSAGE_failure )
{
	try
	{
		DE__EXCEPTION__CHECK_WITH_MESSAGE( true, "message" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error& exc )
	{
		std::regex re{ "de__exception_DE__EXCEPTION__CHECK_WITH_MESSAGE_failure_Test::TestBody@[0-9]+ \\| Condition indicates failure: true \\| message" };

		EXPECT_TRUE( std::regex_match( exc.what( ), re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
