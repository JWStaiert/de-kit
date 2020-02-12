/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.os.string.hpp"

#include <vector>

static const std::vector<std::string> UTF8_TEST_STRINGS{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789)!@#$%^&*(-_=+[{]}\\|`~;:,<.>/?\'\"" };

static const std::vector<std::wstring> UTF16_TEST_STRINGS{ L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789)!@#$%^&*(-_=+[{]}\\|`~;:,<.>/?\'\"" };

TEST( de__os__string, UTF8_to_UTF16 )
{
	for ( auto i = 0; i < UTF8_TEST_STRINGS.size( ); ++i )
	{
		std::wstring l_converted_str = de::os::string::UTF8_to_UTF16( UTF8_TEST_STRINGS[ i ] );

		EXPECT_EQ( l_converted_str.size( ), UTF16_TEST_STRINGS[ i ].size( ) );
		EXPECT_EQ( std::wcslen( l_converted_str.c_str( ) ) , 94 );
		EXPECT_EQ( l_converted_str[ 93 ], L'"' );
		EXPECT_EQ( l_converted_str[ 94 ], 0 );
		EXPECT_EQ( l_converted_str, UTF16_TEST_STRINGS[ i ] );

		std::string l_re_converted_str = de::os::string::UTF16_to_UTF8( l_converted_str );

		EXPECT_EQ( l_re_converted_str.size( ), UTF8_TEST_STRINGS[ i ].size( ) );
		EXPECT_EQ( std::strlen( l_re_converted_str.c_str( ) ), 94 );
		EXPECT_EQ( l_re_converted_str[ 93 ], '"' );
		EXPECT_EQ( l_re_converted_str[ 94 ], 0 );
		EXPECT_EQ( l_re_converted_str, UTF8_TEST_STRINGS[ i ] );
	}
}

TEST( de__os__string, UTF16_to_UTF8 )
{
	for ( auto i = 0; i < UTF16_TEST_STRINGS.size( ); ++i )
	{
		std::string l_converted_str = de::os::string::UTF16_to_UTF8( UTF16_TEST_STRINGS[ i ] );

		EXPECT_EQ( l_converted_str.size( ), UTF8_TEST_STRINGS[ i ].size( ) );
		EXPECT_EQ( std::strlen( l_converted_str.c_str( ) ), 94 );
		EXPECT_EQ( l_converted_str[ 93 ], L'"' );
		EXPECT_EQ( l_converted_str[ 94 ], 0 );
		EXPECT_EQ( l_converted_str, UTF8_TEST_STRINGS[ i ] );

		std::wstring l_re_converted_str = de::os::string::UTF8_to_UTF16( l_converted_str );

		EXPECT_EQ( l_re_converted_str.size( ), UTF16_TEST_STRINGS[ i ].size( ) );
		EXPECT_EQ( std::wcslen( l_re_converted_str.c_str( ) ), 94 );
		EXPECT_EQ( l_re_converted_str[ 93 ], L'"' );
		EXPECT_EQ( l_re_converted_str[ 94 ], 0 );
		EXPECT_EQ( l_re_converted_str, UTF16_TEST_STRINGS[ i ] );
	}
}

/* END */
