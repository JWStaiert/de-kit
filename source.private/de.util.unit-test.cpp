/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.util.hpp"

#include <limits>
#include <string>
#include <sstream>

#define DE_UUT_SIZE 4u

constexpr bool DE_ENABLE_RANGE_TESTS = true;

TEST( de__util__functions , is_signed )
{
	EXPECT_TRUE( de::util::functions<std::int8_t>::is_signed( ) );
	EXPECT_TRUE( de::util::functions<std::int16_t>::is_signed( ) );
	EXPECT_TRUE( de::util::functions<std::int32_t>::is_signed( ) );
	EXPECT_TRUE( de::util::functions<std::int64_t>::is_signed( ) );
	EXPECT_FALSE( de::util::functions<std::uint8_t>::is_signed( ) );
	EXPECT_FALSE( de::util::functions<std::uint16_t>::is_signed( ) );
	EXPECT_FALSE( de::util::functions<std::uint32_t>::is_signed( ) );
	EXPECT_FALSE( de::util::functions<std::uint64_t>::is_signed( ) );
}

TEST( de__util__functions , is_signed_constexpr )
{
	constexpr bool uut_int8_t = de::util::functions<std::int8_t>::is_signed( );
	EXPECT_TRUE( uut_int8_t );

	constexpr bool uut_int16_t = de::util::functions<std::int16_t>::is_signed( );
	EXPECT_TRUE( uut_int16_t );

	constexpr bool uut_int32_t = de::util::functions<std::int32_t>::is_signed( );
	EXPECT_TRUE( uut_int32_t );

	constexpr bool uut_int64_t = de::util::functions<std::int64_t>::is_signed( );
	EXPECT_TRUE( uut_int64_t );

	constexpr bool uut_uint8_t = de::util::functions<std::uint8_t>::is_signed( );
	EXPECT_FALSE( uut_uint8_t );

	constexpr bool uut_uint16_t = de::util::functions<std::uint16_t>::is_signed( );
	EXPECT_FALSE( uut_uint16_t );

	constexpr bool uut_uint32_t = de::util::functions<std::uint32_t>::is_signed( );
	EXPECT_FALSE( uut_uint32_t );

	constexpr bool uut_uint64_t = de::util::functions<std::uint64_t>::is_signed( );
	EXPECT_FALSE( uut_uint64_t );
}

TEST( de__util__functions , digits10 )
{
	EXPECT_EQ( 3 , de::util::functions<std::int8_t>::digits10( ) );
	EXPECT_EQ( 5 , de::util::functions<std::int16_t>::digits10( ) );
	EXPECT_EQ( 10 , de::util::functions<std::int32_t>::digits10( ) );
	EXPECT_EQ( 19 , de::util::functions<std::int64_t>::digits10( ) );
	EXPECT_EQ( 3 , de::util::functions<std::uint8_t>::digits10( ) );
	EXPECT_EQ( 5 , de::util::functions<std::uint16_t>::digits10( ) );
	EXPECT_EQ( 10 , de::util::functions<std::uint32_t>::digits10( ) );
	EXPECT_EQ( 20 , de::util::functions<std::uint64_t>::digits10( ) );
}

TEST( de__util__functions , digits10_constexpr )
{
	constexpr int uut_int8_t = de::util::functions<std::int8_t>::digits10( );
	EXPECT_EQ( 3 , uut_int8_t );

	constexpr int uut_int16_t = de::util::functions<std::int16_t>::digits10( );
	EXPECT_EQ( 5 , uut_int16_t );

	constexpr int uut_int32_t = de::util::functions<std::int32_t>::digits10( );
	EXPECT_EQ( 10 , uut_int32_t );

	constexpr int uut_int64_t = de::util::functions<std::int64_t>::digits10( );
	EXPECT_EQ( 19 , uut_int64_t );

	constexpr int uut_uint8_t = de::util::functions<std::uint8_t>::digits10( );
	EXPECT_EQ( 3 , uut_uint8_t );

	constexpr int uut_uint16_t = de::util::functions<std::uint16_t>::digits10( );
	EXPECT_EQ( 5 , uut_uint16_t );

	constexpr int uut_uint32_t = de::util::functions<std::uint32_t>::digits10( );
	EXPECT_EQ( 10 , uut_uint32_t );

	constexpr int uut_uint64_t = de::util::functions<std::uint64_t>::digits10( );
	EXPECT_EQ( 20 , uut_uint64_t );
}

TEST( de__util__functions , digits16 )
{
	EXPECT_EQ( 2 , de::util::functions<std::int8_t>::digits16( ) );
	EXPECT_EQ( 4 , de::util::functions<std::int16_t>::digits16( ) );
	EXPECT_EQ( 8 , de::util::functions<std::int32_t>::digits16( ) );
	EXPECT_EQ( 16 , de::util::functions<std::int64_t>::digits16( ) );
	EXPECT_EQ( 2 , de::util::functions<std::uint8_t>::digits16( ) );
	EXPECT_EQ( 4 , de::util::functions<std::uint16_t>::digits16( ) );
	EXPECT_EQ( 8 , de::util::functions<std::uint32_t>::digits16( ) );
	EXPECT_EQ( 16 , de::util::functions<std::uint64_t>::digits16( ) );
}

TEST( de__util__functions , digits16_constexpr )
{
	constexpr int uut_int8_t = de::util::functions<std::int8_t>::digits16( );
	EXPECT_EQ( 2 , uut_int8_t );

	constexpr int uut_int16_t = de::util::functions<std::int16_t>::digits16( );
	EXPECT_EQ( 4 , uut_int16_t );

	constexpr int uut_int32_t = de::util::functions<std::int32_t>::digits16( );
	EXPECT_EQ( 8 , uut_int32_t );

	constexpr int uut_int64_t = de::util::functions<std::int64_t>::digits16( );
	EXPECT_EQ( 16 , uut_int64_t );

	constexpr int uut_uint8_t = de::util::functions<std::uint8_t>::digits16( );
	EXPECT_EQ( 2 , uut_uint8_t );

	constexpr int uut_uint16_t = de::util::functions<std::uint16_t>::digits16( );
	EXPECT_EQ( 4 , uut_uint16_t );

	constexpr int uut_uint32_t = de::util::functions<std::uint32_t>::digits16( );
	EXPECT_EQ( 8 , uut_uint32_t );

	constexpr int uut_uint64_t = de::util::functions<std::uint64_t>::digits16( );
	EXPECT_EQ( 16 , uut_uint64_t );
}

TEST( de__util__functions , is_positive )
{
	EXPECT_TRUE( de::util::functions<std::int8_t>::is_positive( 0x7F ) );
	EXPECT_TRUE( de::util::functions<std::int16_t>::is_positive( 0x7FFF ) );
	EXPECT_TRUE( de::util::functions<std::int32_t>::is_positive( 0x7FFFFFFF ) );
	EXPECT_TRUE( de::util::functions<std::int64_t>::is_positive( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_TRUE( de::util::functions<std::uint8_t>::is_positive( 0xFFu ) );
	EXPECT_TRUE( de::util::functions<std::uint16_t>::is_positive( 0xFFFFu ) );
	EXPECT_TRUE( de::util::functions<std::uint32_t>::is_positive( 0xFFFFFFFFu ) );
	EXPECT_TRUE( de::util::functions<std::uint64_t>::is_positive( 0xFFFFFFFFFFFFFFFFu ) );

	EXPECT_TRUE( de::util::functions<std::int8_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::int16_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::int32_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::int64_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::uint8_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::uint16_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::uint32_t>::is_positive( 0 ) );
	EXPECT_TRUE( de::util::functions<std::uint64_t>::is_positive( 0 ) );

	EXPECT_FALSE( de::util::functions<std::int8_t>::is_positive( 0x80u ) );
	EXPECT_FALSE( de::util::functions<std::int16_t>::is_positive( 0x8000u ) );
	EXPECT_FALSE( de::util::functions<std::int32_t>::is_positive( 0x80000000u ) );
	EXPECT_FALSE( de::util::functions<std::int64_t>::is_positive( 0x8000000000000000u ) );
}

TEST( de__util__functions , is_positive_constexpr )
{
	constexpr bool uut_int8_t_7F = de::util::functions<std::int8_t>::is_positive( 0x7F );
	EXPECT_TRUE( uut_int8_t_7F );

	constexpr bool uut_int16_t_7FFF = de::util::functions<std::int16_t>::is_positive( 0x7FFF );
	EXPECT_TRUE( uut_int16_t_7FFF );

	constexpr bool uut_int32_t_7FFFFFFF = de::util::functions<std::int32_t>::is_positive( 0x7FFFFFFF );
	EXPECT_TRUE( uut_int32_t_7FFFFFFF );

	constexpr bool uut_int64_t_7FFFFFFFFFFFFFFF = de::util::functions<std::int64_t>::is_positive( 0x7FFFFFFFFFFFFFFF );
	EXPECT_TRUE( uut_int64_t_7FFFFFFFFFFFFFFF );

	constexpr bool uut_int8_t_FF = de::util::functions<std::uint8_t>::is_positive( 0xFFu );
	EXPECT_TRUE( uut_int8_t_FF );

	constexpr bool uut_int16_t_FFFF = de::util::functions<std::uint16_t>::is_positive( 0xFFFFu );
	EXPECT_TRUE( uut_int16_t_FFFF );

	constexpr bool uut_int32_t_FFFFFFFF = de::util::functions<std::uint32_t>::is_positive( 0xFFFFFFFFu );
	EXPECT_TRUE( uut_int32_t_FFFFFFFF );

	constexpr bool uut_int64_t_FFFFFFFFFFFFFFFF = de::util::functions<std::uint64_t>::is_positive( 0xFFFFFFFFFFFFFFFFu );
	EXPECT_TRUE( uut_int64_t_FFFFFFFFFFFFFFFF );

	constexpr bool uut_int8_t_0 = de::util::functions<std::int8_t>::is_positive( 0 );
	EXPECT_TRUE( uut_int8_t_0 );

	constexpr bool uut_int16_t_0 = de::util::functions<std::int16_t>::is_positive( 0 );
	EXPECT_TRUE( uut_int16_t_0 );

	constexpr bool uut_int32_t_0 = de::util::functions<std::int32_t>::is_positive( 0 );
	EXPECT_TRUE( uut_int32_t_0 );

	constexpr bool uut_int64_t_0 = de::util::functions<std::int64_t>::is_positive( 0 );
	EXPECT_TRUE( uut_int64_t_0 );

	constexpr bool uut_uint8_t_0 = de::util::functions<std::uint8_t>::is_positive( 0 );
	EXPECT_TRUE( uut_uint8_t_0 );

	constexpr bool uut_uint16_t_0 = de::util::functions<std::uint16_t>::is_positive( 0 );
	EXPECT_TRUE( uut_uint16_t_0 );

	constexpr bool uut_uint32_t_0 = de::util::functions<std::uint32_t>::is_positive( 0 );
	EXPECT_TRUE( uut_uint32_t_0 );

	constexpr bool uut_uint64_t_0 = de::util::functions<std::uint64_t>::is_positive( 0 );
	EXPECT_TRUE( uut_uint64_t_0 );

	constexpr bool uut_int8_t_80u = de::util::functions<std::int8_t>::is_positive( 0x80u );
	EXPECT_FALSE( uut_int8_t_80u );

	constexpr bool uut_int16_t_8000u = de::util::functions<std::int16_t>::is_positive( 0x8000u );
	EXPECT_FALSE( uut_int16_t_8000u );

	constexpr bool uut_int32_t_80000000u = de::util::functions<std::int32_t>::is_positive( 0x80000000u );
	EXPECT_FALSE( uut_int32_t_80000000u );

	constexpr bool uut_int64_t_8000000000000000u = de::util::functions<std::int64_t>::is_positive( 0x8000000000000000u );
	EXPECT_FALSE( uut_int64_t_8000000000000000u );
}

TEST( de__util__functions , is_negative )
{
	EXPECT_FALSE( de::util::functions<std::int8_t>::is_negative( 0x7F ) );
	EXPECT_FALSE( de::util::functions<std::int16_t>::is_negative( 0x7FFF ) );
	EXPECT_FALSE( de::util::functions<std::int32_t>::is_negative( 0x7FFFFFFF ) );
	EXPECT_FALSE( de::util::functions<std::int64_t>::is_negative( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_FALSE( de::util::functions<std::uint8_t>::is_negative( 0xFFu ) );
	EXPECT_FALSE( de::util::functions<std::uint16_t>::is_negative( 0xFFFFu ) );
	EXPECT_FALSE( de::util::functions<std::uint32_t>::is_negative( 0xFFFFFFFFu ) );
	EXPECT_FALSE( de::util::functions<std::uint64_t>::is_negative( 0xFFFFFFFFFFFFFFFFu ) );

	EXPECT_FALSE( de::util::functions<std::int8_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::int16_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::int32_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::int64_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::uint8_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::uint16_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::uint32_t>::is_negative( 0 ) );
	EXPECT_FALSE( de::util::functions<std::uint64_t>::is_negative( 0 ) );

	EXPECT_TRUE( de::util::functions<std::int8_t>::is_negative( 0x80u ) );
	EXPECT_TRUE( de::util::functions<std::int16_t>::is_negative( 0x8000u ) );
	EXPECT_TRUE( de::util::functions<std::int32_t>::is_negative( 0x80000000u ) );
	EXPECT_TRUE( de::util::functions<std::int64_t>::is_negative( 0x8000000000000000u ) );
}

TEST( de__util__functions , is_negative_constexpr )
{
	constexpr bool uut_int8_t_7F = de::util::functions<std::int8_t>::is_negative( 0x7F );
	EXPECT_FALSE( uut_int8_t_7F );

	constexpr bool uut_int16_t_7FFF = de::util::functions<std::int16_t>::is_negative( 0x7FFF );
	EXPECT_FALSE( uut_int16_t_7FFF );

	constexpr bool uut_int32_t_7FFFFFFF = de::util::functions<std::int32_t>::is_negative( 0x7FFFFFFF );
	EXPECT_FALSE( uut_int32_t_7FFFFFFF );

	constexpr bool uut_int64_t_7FFFFFFFFFFFFFFF = de::util::functions<std::int64_t>::is_negative( 0x7FFFFFFFFFFFFFFF );
	EXPECT_FALSE( uut_int64_t_7FFFFFFFFFFFFFFF );

	constexpr bool uut_int8_t_FF = de::util::functions<std::uint8_t>::is_negative( 0xFFu );
	EXPECT_FALSE( uut_int8_t_FF );

	constexpr bool uut_int16_t_FFFF = de::util::functions<std::uint16_t>::is_negative( 0xFFFFu );
	EXPECT_FALSE( uut_int16_t_FFFF );

	constexpr bool uut_int32_t_FFFFFFFF = de::util::functions<std::uint32_t>::is_negative( 0xFFFFFFFFu );
	EXPECT_FALSE( uut_int32_t_FFFFFFFF );

	constexpr bool uut_int64_t_FFFFFFFFFFFFFFFF = de::util::functions<std::uint64_t>::is_negative( 0xFFFFFFFFFFFFFFFFu );
	EXPECT_FALSE( uut_int64_t_FFFFFFFFFFFFFFFF );

	constexpr bool uut_int8_t_0 = de::util::functions<std::int8_t>::is_negative( 0 );
	EXPECT_FALSE( uut_int8_t_0 );

	constexpr bool uut_int16_t_0 = de::util::functions<std::int16_t>::is_negative( 0 );
	EXPECT_FALSE( uut_int16_t_0 );

	constexpr bool uut_int32_t_0 = de::util::functions<std::int32_t>::is_negative( 0 );
	EXPECT_FALSE( uut_int32_t_0 );

	constexpr bool uut_int64_t_0 = de::util::functions<std::int64_t>::is_negative( 0 );
	EXPECT_FALSE( uut_int64_t_0 );

	constexpr bool uut_uint8_t_0 = de::util::functions<std::uint8_t>::is_negative( 0 );
	EXPECT_FALSE( uut_uint8_t_0 );

	constexpr bool uut_uint16_t_0 = de::util::functions<std::uint16_t>::is_negative( 0 );
	EXPECT_FALSE( uut_uint16_t_0 );

	constexpr bool uut_uint32_t_0 = de::util::functions<std::uint32_t>::is_negative( 0 );
	EXPECT_FALSE( uut_uint32_t_0 );

	constexpr bool uut_uint64_t_0 = de::util::functions<std::uint64_t>::is_negative( 0 );
	EXPECT_FALSE( uut_uint64_t_0 );

	constexpr bool uut_int8_t_80u = de::util::functions<std::int8_t>::is_negative( 0x80u );
	EXPECT_TRUE( uut_int8_t_80u );

	constexpr bool uut_int16_t_8000u = de::util::functions<std::int16_t>::is_negative( 0x8000u );
	EXPECT_TRUE( uut_int16_t_8000u );

	constexpr bool uut_int32_t_80000000u = de::util::functions<std::int32_t>::is_negative( 0x80000000u );
	EXPECT_TRUE( uut_int32_t_80000000u );

	constexpr bool uut_int64_t_8000000000000000u = de::util::functions<std::int64_t>::is_negative( 0x8000000000000000u );
	EXPECT_TRUE( uut_int64_t_8000000000000000u );
}

TEST( de__util__constants , is_signed )
{
	EXPECT_TRUE( de::util::constants<std::int8_t>::is_signed );
	EXPECT_TRUE( de::util::constants<std::int16_t>::is_signed );
	EXPECT_TRUE( de::util::constants<std::int32_t>::is_signed );
	EXPECT_TRUE( de::util::constants<std::int64_t>::is_signed );
	EXPECT_FALSE( de::util::constants<std::uint8_t>::is_signed );
	EXPECT_FALSE( de::util::constants<std::uint16_t>::is_signed );
	EXPECT_FALSE( de::util::constants<std::uint32_t>::is_signed );
	EXPECT_FALSE( de::util::constants<std::uint64_t>::is_signed );
}

TEST( de__util__constants , is_signed_constexpr )
{
	constexpr bool uut_int8_t = de::util::constants<std::int8_t>::is_signed;
	EXPECT_TRUE( uut_int8_t );

	constexpr bool uut_int16_t = de::util::constants<std::int16_t>::is_signed;
	EXPECT_TRUE( uut_int16_t );

	constexpr bool uut_int32_t = de::util::constants<std::int32_t>::is_signed;
	EXPECT_TRUE( uut_int32_t );

	constexpr bool uut_int64_t = de::util::constants<std::int64_t>::is_signed;
	EXPECT_TRUE( uut_int64_t );

	constexpr bool uut_uint8_t = de::util::constants<std::uint8_t>::is_signed;
	EXPECT_FALSE( uut_uint8_t );

	constexpr bool uut_uint16_t = de::util::constants<std::uint16_t>::is_signed;
	EXPECT_FALSE( uut_uint16_t );

	constexpr bool uut_uint32_t = de::util::constants<std::uint32_t>::is_signed;
	EXPECT_FALSE( uut_uint32_t );

	constexpr bool uut_uint64_t = de::util::constants<std::uint64_t>::is_signed;
	EXPECT_FALSE( uut_uint64_t );
}

TEST( de__util__constants , digits10 )
{
	EXPECT_EQ( 3 , de::util::constants<std::int8_t>::digits10 );
	EXPECT_EQ( 5 , de::util::constants<std::int16_t>::digits10 );
	EXPECT_EQ( 10 , de::util::constants<std::int32_t>::digits10 );
	EXPECT_EQ( 19 , de::util::constants<std::int64_t>::digits10 );
	EXPECT_EQ( 3 , de::util::constants<std::uint8_t>::digits10 );
	EXPECT_EQ( 5 , de::util::constants<std::uint16_t>::digits10 );
	EXPECT_EQ( 10 , de::util::constants<std::uint32_t>::digits10 );
	EXPECT_EQ( 20 , de::util::constants<std::uint64_t>::digits10 );
}


TEST( de__util__constants , digits10_constexpr )
{
	constexpr int uut_int8_t = de::util::constants<std::int8_t>::digits10;
	EXPECT_EQ( 3 , uut_int8_t );

	constexpr int uut_int16_t = de::util::constants<std::int16_t>::digits10;
	EXPECT_EQ( 5 , uut_int16_t );

	constexpr int uut_int32_t = de::util::constants<std::int32_t>::digits10;
	EXPECT_EQ( 10 , uut_int32_t );

	constexpr int uut_int64_t = de::util::constants<std::int64_t>::digits10;
	EXPECT_EQ( 19 , uut_int64_t );

	constexpr int uut_uint8_t = de::util::constants<std::uint8_t>::digits10;
	EXPECT_EQ( 3 , uut_uint8_t );

	constexpr int uut_uint16_t = de::util::constants<std::uint16_t>::digits10;
	EXPECT_EQ( 5 , uut_uint16_t );

	constexpr int uut_uint32_t = de::util::constants<std::uint32_t>::digits10;
	EXPECT_EQ( 10 , uut_uint32_t );

	constexpr int uut_uint64_t = de::util::constants<std::uint64_t>::digits10;
	EXPECT_EQ( 20 , uut_uint64_t );
}

TEST( de__util__constants , digits16 )
{
	EXPECT_EQ( 2 , de::util::constants<std::int8_t>::digits16 );
	EXPECT_EQ( 4 , de::util::constants<std::int16_t>::digits16 );
	EXPECT_EQ( 8 , de::util::constants<std::int32_t>::digits16 );
	EXPECT_EQ( 16 , de::util::constants<std::int64_t>::digits16 );
	EXPECT_EQ( 2 , de::util::constants<std::uint8_t>::digits16 );
	EXPECT_EQ( 4 , de::util::constants<std::uint16_t>::digits16 );
	EXPECT_EQ( 8 , de::util::constants<std::uint32_t>::digits16 );
	EXPECT_EQ( 16 , de::util::constants<std::uint64_t>::digits16 );
}

TEST( de__util__constants , digits16_constexpr )
{
	constexpr int uut_int8_t = de::util::constants<std::int8_t>::digits16;
	EXPECT_EQ( 2 , uut_int8_t );

	constexpr int uut_int16_t = de::util::constants<std::int16_t>::digits16;
	EXPECT_EQ( 4 , uut_int16_t );

	constexpr int uut_int32_t = de::util::constants<std::int32_t>::digits16;
	EXPECT_EQ( 8 , uut_int32_t );

	constexpr int uut_int64_t = de::util::constants<std::int64_t>::digits16;
	EXPECT_EQ( 16 , uut_int64_t );

	constexpr int uut_uint8_t = de::util::constants<std::uint8_t>::digits16;
	EXPECT_EQ( 2 , uut_uint8_t );

	constexpr int uut_uint16_t = de::util::constants<std::uint16_t>::digits16;
	EXPECT_EQ( 4 , uut_uint16_t );

	constexpr int uut_uint32_t = de::util::constants<std::uint32_t>::digits16;
	EXPECT_EQ( 8 , uut_uint32_t );

	constexpr int uut_uint64_t = de::util::constants<std::uint64_t>::digits16;
	EXPECT_EQ( 16 , uut_uint64_t );
}

/* cstring_basic */

TEST( de__util__cstring_basic , append_char )
{
	char buffer[ DE_UUT_SIZE ];

	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_char( '0' );
	EXPECT_EQ( std::string( uut ) , "0" );

	uut.append_char( '1' );
	EXPECT_EQ( std::string( uut ) , "01" );

	uut.append_char( '2' );
	EXPECT_EQ( std::string( uut ) , "012" );

	uut.append_char( '4' );
	EXPECT_EQ( std::string( uut ) , "012" ); // JWS: Last char in buffer must always be null terminator.
}

TEST( de__util__cstring_basic , append_digit10 )
{
	char buffer[ DE_UUT_SIZE ];

	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_digit10( 0 );
	EXPECT_EQ( std::string( uut ) , "0" );

	uut.append_digit10( 3 );
	EXPECT_EQ( std::string( uut ) , "03" );

	uut.append_digit10( 9 );
	EXPECT_EQ( std::string( uut ) , "039" );

	uut.append_digit10( 8 );
	EXPECT_EQ( std::string( uut ) , "039" ); // JWS: Last char in buffer must always be null terminator.
}

TEST( de__util__cstring_basic , append_digit16 )
{
	char buffer[ DE_UUT_SIZE + 1 ];

	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_digit16( 0x0 );
	EXPECT_EQ( std::string( uut ) , "0" );

	uut.append_digit16( 0x9 );
	EXPECT_EQ( std::string( uut ) , "09" );

	uut.append_digit16( 0xA );
	EXPECT_EQ( std::string( uut ) , "09A" );

	uut.append_digit16( 0xF );
	EXPECT_EQ( std::string( uut ) , "09AF" );

	uut.append_digit16( 0xD );
	EXPECT_EQ( std::string( uut ) , "09AF" ); // JWS: Last char in buffer must always be null terminator.
}

TEST( de__util__cstring_basic , append_cstring )
{
	char buffer[ DE_UUT_SIZE ];

	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_cstring( "01" );
	EXPECT_EQ( std::string( uut ) , "01" );

	uut.append_cstring( "23" );
	EXPECT_EQ( std::string( uut ) , "012" ); // JWS: Last char in buffer must always be null terminator.
}

TEST( de__util__cstring_basic , append_decimal )
{
	std::stringstream expected { };

	char buffer[ 8 * DE_UUT_SIZE ];
	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	/* int8_t */

	uut.append_decimal( static_cast<std::int8_t>( 0x80u ) );
	EXPECT_EQ( std::string( uut ) , "-128" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int8_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int8_t>( 0x7F ) );
	EXPECT_EQ( std::string( uut ) , "127" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::int8_t i = std::numeric_limits<std::int8_t>::min( ) ; i < std::numeric_limits<std::int8_t>::max( ) ; ++i )
		{
			expected << static_cast<std::int16_t>( i ); // JWS: Cast required otherwise an ASCII code will be appended.
			uut.append_decimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* int16_t */

	uut.append_decimal( static_cast<std::int16_t>( 0x8000u ) );
	EXPECT_EQ( std::string( uut ) , "-32768" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int16_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int16_t>( 0x7FFF ) );
	EXPECT_EQ( std::string( uut ) , "32767" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::int16_t i = std::numeric_limits<std::int16_t>::min( ) ; i < std::numeric_limits<std::int16_t>::max( ) ; ++i )
		{
			expected << i;
			uut.append_decimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* int32_t */

	uut.append_decimal( static_cast<std::int32_t>( 0x80000000u ) );
	EXPECT_EQ( std::string( uut ) , "-2147483648" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int32_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int32_t>( 0x7FFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "2147483647" );
	uut.reset( );

	/* int64_t */

	uut.append_decimal( static_cast<std::int64_t>( 0x8000000000000000u ) );
	EXPECT_EQ( std::string( uut ) , "-9223372036854775808" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int64_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::int64_t>( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "9223372036854775807" );
	uut.reset( );

	/* uint8_t */

	uut.append_decimal( static_cast<std::uint8_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint8_t>( 0x7F ) );
	EXPECT_EQ( std::string( uut ) , "127" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint8_t>( 0xFF ) );
	EXPECT_EQ( std::string( uut ) , "255" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::uint8_t i = std::numeric_limits<std::uint8_t>::min( ) ; i < std::numeric_limits<std::uint8_t>::max( ) ; ++i )
		{
			expected << static_cast<std::uint16_t>( i ); // JWS: Cast required otherwise an ASCII code will be appended.
			uut.append_decimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* uint16_t */

	uut.append_decimal( static_cast<std::uint16_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint16_t>( 0x7FFF ) );
	EXPECT_EQ( std::string( uut ) , "32767" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint16_t>( 0xFFFF ) );
	EXPECT_EQ( std::string( uut ) , "65535" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::uint16_t i = std::numeric_limits<std::uint16_t>::min( ) ; i < std::numeric_limits<std::uint16_t>::max( ) ; ++i )
		{
			expected << i;
			uut.append_decimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* uint32_t */

	uut.append_decimal( static_cast<std::uint32_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint32_t>( 0x7FFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "2147483647" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint32_t>( 0xFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "4294967295" );
	uut.reset( );

	/* uint64_t */

	uut.append_decimal( static_cast<std::uint64_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint64_t>( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "9223372036854775807" );
	uut.reset( );

	uut.append_decimal( static_cast<std::uint64_t>( 0xFFFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "18446744073709551615" );
	uut.reset( );
}

TEST( de__util__cstring_basic , append_hexadecimal )
{
	std::stringstream expected { };
	expected << std::hex << std::uppercase << std::setfill( '0' );

	char buffer[ 8 * DE_UUT_SIZE ];
	de::util::cstring_basic uut { buffer , sizeof( buffer ) };

	EXPECT_EQ( std::string( uut ) , "" );

	/* int8_t */

	uut.append_hexadecimal( static_cast<std::int8_t>( 0x80u ) );
	EXPECT_EQ( std::string( uut ) , "80" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int8_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "00" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int8_t>( 0x7F ) );
	EXPECT_EQ( std::string( uut ) , "7F" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::int8_t i = std::numeric_limits<std::int8_t>::min( ) ; i < std::numeric_limits<std::int8_t>::max( ) ; ++i )
		{
			expected << std::setw( 2 );
			expected << (static_cast<std::uint16_t>( i ) & 0x00FF); // JWS: Cast required otherwise an ASCII code will be appended. Mask required to get the expected number of digits.
			uut.append_hexadecimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* int16_t */

	uut.append_hexadecimal( static_cast<std::int16_t>( 0x8000u ) );
	EXPECT_EQ( std::string( uut ) , "8000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int16_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int16_t>( 0x7FFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFF" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::int16_t i = std::numeric_limits<std::int16_t>::min( ) ; i < std::numeric_limits<std::int16_t>::max( ) ; ++i )
		{
			expected << std::setw( 4 );
			expected << i;
			uut.append_hexadecimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* int32_t */

	uut.append_hexadecimal( static_cast<std::int32_t>( 0x80000000u ) );
	EXPECT_EQ( std::string( uut ) , "80000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int32_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "00000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int32_t>( 0x7FFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFFFFFF" );
	uut.reset( );

	/* int64_t */

	uut.append_hexadecimal( static_cast<std::int64_t>( 0x8000000000000000u ) );
	EXPECT_EQ( std::string( uut ) , "8000000000000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int64_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0000000000000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::int64_t>( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFFFFFFFFFFFFFF" );
	uut.reset( );

	/* uint8_t */

	uut.append_hexadecimal( static_cast<std::uint8_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "00" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint8_t>( 0x7F ) );
	EXPECT_EQ( std::string( uut ) , "7F" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint8_t>( 0xFF ) );
	EXPECT_EQ( std::string( uut ) , "FF" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::uint8_t i = std::numeric_limits<std::uint8_t>::min( ) ; i < std::numeric_limits<std::uint8_t>::max( ) ; ++i )
		{
			expected << std::setw( 2 );
			expected << static_cast<std::uint16_t>( i ); // JWS: Cast required otherwise an ASCII code will be appended.
			uut.append_hexadecimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* uint16_t */

	uut.append_hexadecimal( static_cast<std::uint16_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint16_t>( 0x7FFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFF" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint16_t>( 0xFFFF ) );
	EXPECT_EQ( std::string( uut ) , "FFFF" );
	uut.reset( );

	if ( DE_ENABLE_RANGE_TESTS )
	{
		// JWS: Force index type rather than use auto. Guarantee test is using correct type.
		for ( std::uint16_t i = std::numeric_limits<std::uint16_t>::min( ) ; i < std::numeric_limits<std::uint16_t>::max( ) ; ++i )
		{
			expected << std::setw( 4 );
			expected << i;
			uut.append_hexadecimal( i );
			ASSERT_EQ( std::string( uut ) , expected.str( ) );
			uut.reset( );
			expected.str( std::string { } );
		}
	}

	/* uint32_t */

	uut.append_hexadecimal( static_cast<std::uint32_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "00000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint32_t>( 0x7FFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFFFFFF" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint32_t>( 0xFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "FFFFFFFF" );
	uut.reset( );

	/* uint64_t */

	uut.append_hexadecimal( static_cast<std::uint64_t>( 0 ) );
	EXPECT_EQ( std::string( uut ) , "0000000000000000" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint64_t>( 0x7FFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "7FFFFFFFFFFFFFFF" );
	uut.reset( );

	uut.append_hexadecimal( static_cast<std::uint64_t>( 0xFFFFFFFFFFFFFFFF ) );
	EXPECT_EQ( std::string( uut ) , "FFFFFFFFFFFFFFFF" );
	uut.reset( );
}

/* cstring_array */

TEST( de__util__cstring_array , append_char )
{
	de::util::cstring_array<DE_UUT_SIZE> uut { };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_char( '0' );
	EXPECT_EQ( std::string( uut ) , "0" );

	uut.append_char( '1' );
	EXPECT_EQ( std::string( uut ) , "01" );

	uut.append_char( '2' );
	EXPECT_EQ( std::string( uut ) , "012" );

	uut.append_char( '4' );
	EXPECT_EQ( std::string( uut ) , "012" ); // JWS: Last char in buffer must always be null terminator.
}

TEST( de__util__cstring_array , append_cstring )
{
	de::util::cstring_array<DE_UUT_SIZE> uut { };

	EXPECT_EQ( std::string( uut ) , "" );

	uut.append_cstring( "01" );
	EXPECT_EQ( std::string( uut ) , "01" );

	uut.append_cstring( "23" );
	EXPECT_EQ( std::string( uut ) , "012" ); // JWS: Last char in buffer must always be null terminator.
}

/* END */
