/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.os.error.hpp"

#include <string>

#include <windows.h>

TEST( de__os__error , ctor_error_00000000 )
{
	SetLastError( 0 );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(0000:0000) = The operation completed successfully." );
}

TEST( de__os__error , ctor_error_00000001 )
{
	SetLastError( 1 );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(0000:0001) = Incorrect function." );
}

TEST( de__os__error , ctor_error_0000000A )
{
	SetLastError( 0xA );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(0000:000A) = The environment is incorrect." );
}

TEST( de__os__error , ctor_error_0000000F )
{
	SetLastError( 0xF );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(0000:000F) = The system cannot find the drive specified." );
}

TEST( de__os__error , ctor_error_11111111 )
{
	SetLastError( 0x11111111 );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(1111:1111) = FormatMessageA failed." );
}

TEST( de__os__error , ctor_error_AAAAAAAA )
{
	SetLastError( 0xAAAAAAAA );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(AAAA:AAAA) = FormatMessageA failed." );
}

TEST( de__os__error , ctor_error_FFFFFFFF )
{
	SetLastError( 0xFFFFFFFF );
	de::os::error err { };
	EXPECT_EQ( std::string( static_cast<const char *>( err ) ) , "GetLastError(FFFF:FFFF) = FormatMessageA failed." );
}

/* END */
