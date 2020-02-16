/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.native-types.hpp"

#include <limits>

TEST( de__float32 , size )
{
	EXPECT_EQ( sizeof( de::float32 ), 4 );
}

TEST( de__float32, is_iec559 )
{
	EXPECT_TRUE( std::numeric_limits<de::float32>::is_iec559 );
}

TEST( de__float64, size )
{
	EXPECT_EQ( sizeof( de::float64 ), 8 );
}

TEST( de__float64, is_iec559 )
{
	EXPECT_TRUE( std::numeric_limits<de::float64>::is_iec559 );
}

/* END */
