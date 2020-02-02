/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.version.hpp"

#include <string>
#include <regex>

#include <vulkan/vulkan.h>

TEST( de__version , ctor_default_success )
{
	de::version uut { };

	EXPECT_EQ( uut , 0u );
}

TEST( de__version , ctor_std_uint32_t_success )
{
	const std::uint32_t l_version = VK_MAKE_VERSION( 1 , 2 , 4 );

	de::version uut { l_version };

	EXPECT_EQ( uut , l_version );
}

TEST( de__version , ctor_major_minor_patch_success )
{
	std::uint32_t l_major = 3;
	std::uint32_t l_minor = 6;
	std::uint32_t l_patch = 9;
	const std::uint32_t l_version = VK_MAKE_VERSION( l_major , l_minor , l_patch );

	de::version uut { l_major , l_minor , l_patch };

	EXPECT_EQ( uut , l_version );
}

TEST( de__version , ctor_major_minor_patch_failure_on_major )
{
	try
	{
		de::version uut { 1024 , 6 , 9 };

		FAIL( ) << "Expected exception.";
	}
	catch ( std::logic_error & exc )
	{
		std::regex re { "de::version::version@[0-9]+\\| Program violates assertion: p_major < 1024" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__version , ctor_major_minor_patch_failure_on_minor )
{
	try
	{
		de::version uut { 3 , 1024 , 9 };

		FAIL( ) << "Expected exception.";
	}
	catch ( std::logic_error & exc )
	{
		std::regex re { "de::version::version@[0-9]+\\| Program violates assertion: p_minor < 1024" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__version , ctor_major_minor_patch_failure_on_patch )
{
	try
	{
		de::version uut { 3 , 6 , 4096 };

		FAIL( ) << "Expected exception.";
	}
	catch ( std::logic_error & exc )
	{
		std::regex re { "de::version::version@[0-9]+\\| Program violates assertion: p_patch < 4096" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__version , assignment_operator_default )
{
	const std::uint32_t l_version_a = VK_MAKE_VERSION( 1 , 2 , 4 );
	const std::uint32_t l_version_b = VK_MAKE_VERSION( 3 , 6 , 0 );

	de::version uut_a { l_version_a };
	de::version uut_b { l_version_b };

	EXPECT_TRUE( uut_a == l_version_a );
	EXPECT_TRUE( uut_b == l_version_b );
	EXPECT_FALSE( uut_a == uut_b );

	uut_a = uut_b;

	EXPECT_TRUE( uut_a == uut_b );
}

TEST( de__version , assignment_operator_std_uint32_t )
{
	const std::uint32_t l_version = VK_MAKE_VERSION( 1 , 2 , 4 );
	const std::uint32_t l_version_assigned = VK_MAKE_VERSION( 3 , 6 , 0 );

	de::version uut { l_version };

	EXPECT_EQ( uut , l_version );

	uut = l_version_assigned;

	EXPECT_EQ( uut , l_version_assigned );
}

TEST( de__version , cast_to_std_string )
{
	const std::uint32_t l_version = VK_MAKE_VERSION( 1 , 2 , 4 );

	de::version uut { l_version };

	EXPECT_EQ( uut , "1.2.4" );
}

TEST( de__version , operator_boolean_equality )
{
	const std::uint32_t a[ 3 ] = { 1 , 2 ,4 };
	const std::uint32_t b[ 3 ] = { 3 , 5 ,9 };

	de::version uut_a { a[0] , a[1] , a[2] };
	de::version uut_b { b[0] , b[1] , b[2] };

	/* Sanity checks and true operator== result. */
	EXPECT_TRUE( uut_a == uut_a );
	EXPECT_TRUE( uut_a == VK_MAKE_VERSION( a[ 0 ] , a[ 1 ] , a[ 2 ] ) );
	EXPECT_TRUE( VK_MAKE_VERSION( a[ 0 ] , a[ 1 ] , a[ 2 ] ) == uut_a );
	EXPECT_TRUE( uut_a == "1.2.4" );
	EXPECT_TRUE( "1.2.4" == uut_a );

	EXPECT_TRUE( uut_b == uut_b );
	EXPECT_TRUE( uut_b == VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) );
	EXPECT_TRUE( VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) == uut_b );
	EXPECT_TRUE( uut_b == "3.5.9" );
	EXPECT_TRUE( "3.5.9" == uut_b );

	/* False operator== result. */
	EXPECT_FALSE( uut_a == uut_b );
	EXPECT_FALSE( uut_a == VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) );
	EXPECT_FALSE( VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) == uut_a );
	EXPECT_FALSE( uut_a == "3.5.9" );
	EXPECT_FALSE( "3.5.9" == uut_a );

	/* True operator!= result. */
	EXPECT_TRUE( uut_a != uut_b );
	EXPECT_TRUE( uut_a != VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) );
	EXPECT_TRUE( VK_MAKE_VERSION( b[ 0 ] , b[ 1 ] , b[ 2 ] ) != uut_a );
	EXPECT_TRUE( uut_a != "3.5.9" );
	EXPECT_TRUE( "3.5.9" != uut_a );

	/* False operator!= result. */
	EXPECT_FALSE( uut_a != uut_a );
	EXPECT_FALSE( uut_a != VK_MAKE_VERSION( a[ 0 ] , a[ 1 ] , a[ 2 ] ) );
	EXPECT_FALSE( VK_MAKE_VERSION( a[ 0 ] , a[ 1 ] , a[ 2 ] ) != uut_a );
	EXPECT_FALSE( uut_a != "1.2.4" );
	EXPECT_FALSE( "1.2.4" != uut_a );
}


/* END */
