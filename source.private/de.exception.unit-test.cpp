/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.exception.hpp"

#include <string>

TEST( de__exceptions , _DE__EXCEPTIONS__THROW_RUNTIME_ERROR_throws )
{
	try
	{
		DE__EXCEPTION__THROW_RUNTIME_ERROR( "cstring" );

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exceptions__DE__EXCEPTIONS__THROW_RUNTIME_ERROR_throws_Test::TestBody@13| cstring" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exceptions , _DE__EXCEPTIONS__CHECK_AND_THROW_RUNTIME_ERROR_success )
{
	try
	{
		DE__EXCEPTION__CHECK_AND_THROW_RUNTIME_ERROR( false , "cstring" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__exceptions , _DE__EXCEPTIONS__CHECK_AND_THROW_RUNTIME_ERROR_failure )
{
	try
	{
		DE__EXCEPTION__CHECK_AND_THROW_RUNTIME_ERROR( true , "cstring" );

		FAIL( ) << "Expected exception.";
	}
	catch ( std::runtime_error & exc )
	{
		EXPECT_EQ( exc.what( ) , std::string( "de__exceptions__DE__EXCEPTIONS__CHECK_AND_THROW_RUNTIME_ERROR_failure_Test::TestBody@43| Expression (true) indicates failure. cstring" ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
