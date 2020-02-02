/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.exception.hpp"

#include <string>

TEST( de__exception , DE__EXCEPTION__ASSERT_success )
{
	try
	{
		DE__EXCEPTION__ASSERT( 0 < 1 );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__ASSERT_failure )
{
	try
	{
		DE__EXCEPTION__ASSERT( 1 < 0 );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::logic_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exception_DE__EXCEPTION__ASSERT_failure_Test::TestBody@25| Program violates assertion: 1 < 0" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__ASSERT_WITH_MESSAGE_success )
{
	try
	{
		DE__EXCEPTION__ASSERT_WITH_MESSAGE( 0 < 1 , "message" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__ASSERT_WITH_MESSAGE_failure )
{
	try
	{
		DE__EXCEPTION__ASSERT_WITH_MESSAGE( 1 < 0 , "message" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::logic_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exception_DE__EXCEPTION__ASSERT_WITH_MESSAGE_failure_Test::TestBody@55| Program violates assertion: 1 < 0 | message" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__CHECK_success )
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

TEST( de__exception , DE__EXCEPTION__CHECK_failure )
{
	try
	{
		DE__EXCEPTION__CHECK( true );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exception_DE__EXCEPTION__CHECK_failure_Test::TestBody@85| Expression indicates failure: true" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__CHECK_WITH_MESSAGE_success )
{
	try
	{
		DE__EXCEPTION__CHECK_WITH_MESSAGE( false , "message" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exception , DE__EXCEPTION__CHECK_WITH_MESSAGE_failure )
{
	try
	{
		DE__EXCEPTION__CHECK_WITH_MESSAGE( true , "message" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exception_DE__EXCEPTION__CHECK_WITH_MESSAGE_failure_Test::TestBody@115| Expression indicates failure: true | message" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
