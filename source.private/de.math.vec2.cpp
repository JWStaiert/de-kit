/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.math.vec2.hpp"

#include <cstdint>

using vec2_int32 = de::math::vec2< std::int32_t >;

TEST( de__math__vec2_uint32_constexpr , ctor_default )
{
	constexpr vec2_int32 uut { };

	EXPECT_EQ( uut.x , 0 );
	EXPECT_EQ( uut.y , 0 );
}

TEST( de__math__vec2_uint32_constexpr , ctor_x )
{
	constexpr vec2_int32 uut { 1 };

	EXPECT_EQ( uut.x , 1 );
	EXPECT_EQ( uut.y , 0 );
}

TEST( de__math__vec2_uint32_constexpr , ctor_x_y )
{
	constexpr vec2_int32 uut { 1 , 2 };

	EXPECT_EQ( uut.x , 1 );
	EXPECT_EQ( uut.y , 2 );
}

TEST( de__math__vec2_uint32_constexpr , operator_equals )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a == a );
	constexpr bool a_op_b = ( a == b );
	constexpr bool a_op_c = ( a == c );
	constexpr bool a_op_d = ( a == d );
	EXPECT_TRUE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );

	EXPECT_FALSE( b == a );
	EXPECT_TRUE( b == b );
	EXPECT_FALSE( b == c );
	EXPECT_FALSE( b == d );

	EXPECT_FALSE( c == a );
	EXPECT_FALSE( c == b );
	EXPECT_TRUE( c == c );
	EXPECT_FALSE( c == d );

	EXPECT_FALSE( d == a );
	EXPECT_FALSE( d == b );
	EXPECT_FALSE( d == c );
	EXPECT_TRUE( d == d );
}

TEST( de__math__vec2_uint32_constexpr , operator_not_equals )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a != a );
	constexpr bool a_op_b = ( a != b );
	constexpr bool a_op_c = ( a != c );
	constexpr bool a_op_d = ( a != d );
	EXPECT_FALSE( a_op_a );
	EXPECT_TRUE( a_op_b );
	EXPECT_TRUE( a_op_c );
	EXPECT_TRUE( a_op_d );

	EXPECT_TRUE( b != a );
	EXPECT_FALSE( b != b );
	EXPECT_TRUE( b != c );
	EXPECT_TRUE( b != d );

	EXPECT_TRUE( c != a );
	EXPECT_TRUE( c != b );
	EXPECT_FALSE( c != c );
	EXPECT_TRUE( c != d );

	EXPECT_TRUE( d != a );
	EXPECT_TRUE( d != b );
	EXPECT_TRUE( d != c );
	EXPECT_FALSE( d != d );
}

TEST( de__math__vec2_uint32_constexpr , operator_less_than )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a < a );
	constexpr bool a_op_b = ( a < b );
	constexpr bool a_op_c = ( a < c );
	constexpr bool a_op_d = ( a < d );
	EXPECT_FALSE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_TRUE( a_op_d );

	EXPECT_FALSE( b < a );
	EXPECT_FALSE( b < b );
	EXPECT_FALSE( b < c );
	EXPECT_FALSE( b < d );

	EXPECT_FALSE( c < a );
	EXPECT_FALSE( c < b );
	EXPECT_FALSE( c < c );
	EXPECT_FALSE( c < d );

	EXPECT_FALSE( d < a );
	EXPECT_FALSE( d < b );
	EXPECT_FALSE( d < c );
	EXPECT_FALSE( d < d );
}

TEST( de__math__vec2_uint32_constexpr , operator_less_than_equals )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a <= a );
	constexpr bool a_op_b = ( a <= b );
	constexpr bool a_op_c = ( a <= c );
	constexpr bool a_op_d = ( a <= d );
	EXPECT_TRUE( a_op_a );
	EXPECT_TRUE( a_op_b );
	EXPECT_TRUE( a_op_c );
	EXPECT_TRUE( a_op_d );

	EXPECT_FALSE( b <= a );
	EXPECT_TRUE( b <= b );
	EXPECT_FALSE( b <= c );
	EXPECT_TRUE( b <= d );

	EXPECT_FALSE( c <= a );
	EXPECT_FALSE( c <= b );
	EXPECT_TRUE( c <= c );
	EXPECT_TRUE( c <= d );

	EXPECT_FALSE( d <= a );
	EXPECT_FALSE( d <= b );
	EXPECT_FALSE( d <= c );
	EXPECT_TRUE( d <= d );
}

TEST( de__math__vec2_uint32_constexpr , operator_greater_than )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a > a );
	constexpr bool a_op_b = ( a > b );
	constexpr bool a_op_c = ( a > c );
	constexpr bool a_op_d = ( a > d );
	EXPECT_FALSE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );

	EXPECT_FALSE( b > a );
	EXPECT_FALSE( b > b );
	EXPECT_FALSE( b > c );
	EXPECT_FALSE( b > d );

	EXPECT_FALSE( c > a );
	EXPECT_FALSE( c > b );
	EXPECT_FALSE( c > c );
	EXPECT_FALSE( c > d );

	EXPECT_TRUE( d > a );
	EXPECT_FALSE( d > b );
	EXPECT_FALSE( d > c );
	EXPECT_FALSE( d > d );
}

TEST( de__math__vec2_uint32_constexpr , operator_greater_than_equals )
{
	constexpr vec2_int32 a { 1 , 1 };
	constexpr vec2_int32 b { 1 , 2 };
	constexpr vec2_int32 c { 2 , 1 };
	constexpr vec2_int32 d { 2 , 2 };

	constexpr bool a_op_a = ( a >= a );
	constexpr bool a_op_b = ( a >= b );
	constexpr bool a_op_c = ( a >= c );
	constexpr bool a_op_d = ( a >= d );
	EXPECT_TRUE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );

	EXPECT_TRUE( b >= a );
	EXPECT_TRUE( b >= b );
	EXPECT_FALSE( b >= c );
	EXPECT_FALSE( b >= d );

	EXPECT_TRUE( c >= a );
	EXPECT_FALSE( c >= b );
	EXPECT_TRUE( c >= c );
	EXPECT_FALSE( c >= d );

	EXPECT_TRUE( d >= a );
	EXPECT_TRUE( d >= b );
	EXPECT_TRUE( d >= c );
	EXPECT_TRUE( d >= d );
}

TEST( de__math__vec2_uint32 , operator_assignment )
{
	constexpr vec2_int32 uut_const { 2 , 4 };
	vec2_int32 uut { 1 , 2 };
	uut = uut_const;

	EXPECT_EQ( uut.x , 2 );
	EXPECT_EQ( uut.y , 4 );
}

TEST( de__math__vec2_uint32 , operator_assignment_add )
{
	constexpr vec2_int32 uut_const { 2 , 4 };
	vec2_int32 uut { 1 , 2 };
	uut += uut_const;

	EXPECT_EQ( uut.x , 3 );
	EXPECT_EQ( uut.y , 6 );
}

TEST( de__math__vec2_uint32 , operator_assignment_subtract )
{
	constexpr vec2_int32 uut_const { 2 , 4 };
	vec2_int32 uut { 1 , 2 };
	uut -= uut_const;

	EXPECT_EQ( uut.x , -1 );
	EXPECT_EQ( uut.y , -2 );
}

TEST( de__math__vec2_uint32 , operator_assignment_multiply )
{
	constexpr vec2_int32 uut_const { 2 , 4 };
	vec2_int32 uut { 1 , 2 };
	uut *= uut_const;

	EXPECT_EQ( uut.x , 2 );
	EXPECT_EQ( uut.y , 8 );
}

TEST( de__math__vec2_uint32 , operator_assignment_divide )
{
	constexpr vec2_int32 uut_const { 2 , 4 };
	vec2_int32 uut { 2 , 8 };
	uut /= uut_const;

	EXPECT_EQ( uut.x , 1 );
	EXPECT_EQ( uut.y , 2 );
}

TEST( de__math__vec2_uint32 , operator_assignment_multiply_scalar )
{
	vec2_int32 uut { 1 , 2 };
	uut *= 2;

	EXPECT_EQ( uut.x , 2 );
	EXPECT_EQ( uut.y , 4 );
}

TEST( de__math__vec2_uint32 , operator_assignment_divide_scalar )
{
	vec2_int32 uut { 2 , 4 };
	uut /= 2;

	EXPECT_EQ( uut.x , 1 );
	EXPECT_EQ( uut.y , 2 );
}

/* END */
