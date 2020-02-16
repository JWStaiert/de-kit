/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.math.vec3.hpp"

#include <cstdint>

using vec3_int32 = de::math::vec3<std::int32_t>;

TEST( de__math__vec3_int32_constexpr, ctor_default )
{
	constexpr vec3_int32 uut{};

	EXPECT_EQ( uut.x, 0 );
	EXPECT_EQ( uut.y, 0 );
	EXPECT_EQ( uut.z, 0 );
}

TEST( de__math__vec3_int32_constexpr, ctor_x )
{
	constexpr vec3_int32 uut{ 1 };

	EXPECT_EQ( uut.x, 1 );
	EXPECT_EQ( uut.y, 0 );
	EXPECT_EQ( uut.z, 0 );
}

TEST( de__math__vec3_int32_constexpr, ctor_x_y )
{
	constexpr vec3_int32 uut{ 1, 2 };

	EXPECT_EQ( uut.x, 1 );
	EXPECT_EQ( uut.y, 2 );
	EXPECT_EQ( uut.z, 0 );
}

TEST( de__math__vec3_int32_constexpr, ctor_x_y_z )
{
	constexpr vec3_int32 uut{ 1, 2, 3 };

	EXPECT_EQ( uut.x, 1 );
	EXPECT_EQ( uut.y, 2 );
	EXPECT_EQ( uut.z, 3 );
}

TEST( de__math__vec3_int32_constexpr, operator_equals )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a == a );
	constexpr bool a_op_b = ( a == b );
	constexpr bool a_op_c = ( a == c );
	constexpr bool a_op_d = ( a == d );
	constexpr bool a_op_e = ( a == e );
	constexpr bool a_op_f = ( a == f );
	constexpr bool a_op_g = ( a == g );
	constexpr bool a_op_h = ( a == h );
	EXPECT_TRUE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );
	EXPECT_FALSE( a_op_e );
	EXPECT_FALSE( a_op_f );
	EXPECT_FALSE( a_op_g );
	EXPECT_FALSE( a_op_h );

	EXPECT_FALSE( b == a );
	EXPECT_TRUE( b == b );
	EXPECT_FALSE( b == c );
	EXPECT_FALSE( b == d );
	EXPECT_FALSE( b == e );
	EXPECT_FALSE( b == f );
	EXPECT_FALSE( b == g );
	EXPECT_FALSE( b == h );

	EXPECT_FALSE( c == a );
	EXPECT_FALSE( c == b );
	EXPECT_TRUE( c == c );
	EXPECT_FALSE( c == d );
	EXPECT_FALSE( c == e );
	EXPECT_FALSE( c == f );
	EXPECT_FALSE( c == g );
	EXPECT_FALSE( c == h );

	EXPECT_FALSE( d == a );
	EXPECT_FALSE( d == b );
	EXPECT_FALSE( d == c );
	EXPECT_TRUE( d == d );
	EXPECT_FALSE( d == e );
	EXPECT_FALSE( d == f );
	EXPECT_FALSE( d == g );
	EXPECT_FALSE( d == h );

	EXPECT_FALSE( e == a );
	EXPECT_FALSE( e == b );
	EXPECT_FALSE( e == c );
	EXPECT_FALSE( e == d );
	EXPECT_TRUE( e == e );
	EXPECT_FALSE( e == f );
	EXPECT_FALSE( e == g );
	EXPECT_FALSE( e == h );

	EXPECT_FALSE( f == a );
	EXPECT_FALSE( f == b );
	EXPECT_FALSE( f == c );
	EXPECT_FALSE( f == d );
	EXPECT_FALSE( f == e );
	EXPECT_TRUE( f == f );
	EXPECT_FALSE( f == g );
	EXPECT_FALSE( f == h );

	EXPECT_FALSE( g == a );
	EXPECT_FALSE( g == b );
	EXPECT_FALSE( g == c );
	EXPECT_FALSE( g == d );
	EXPECT_FALSE( g == e );
	EXPECT_FALSE( g == f );
	EXPECT_TRUE( g == g );
	EXPECT_FALSE( g == h );

	EXPECT_FALSE( h == a );
	EXPECT_FALSE( h == b );
	EXPECT_FALSE( h == c );
	EXPECT_FALSE( h == d );
	EXPECT_FALSE( h == e );
	EXPECT_FALSE( h == f );
	EXPECT_FALSE( h == g );
	EXPECT_TRUE( h == h );
}

TEST( de__math__vec3_int32_constexpr, operator_not_equals )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a != a );
	constexpr bool a_op_b = ( a != b );
	constexpr bool a_op_c = ( a != c );
	constexpr bool a_op_d = ( a != d );
	constexpr bool a_op_e = ( a != e );
	constexpr bool a_op_f = ( a != f );
	constexpr bool a_op_g = ( a != g );
	constexpr bool a_op_h = ( a != h );
	EXPECT_FALSE( a_op_a );
	EXPECT_TRUE( a_op_b );
	EXPECT_TRUE( a_op_c );
	EXPECT_TRUE( a_op_d );
	EXPECT_TRUE( a_op_e );
	EXPECT_TRUE( a_op_f );
	EXPECT_TRUE( a_op_g );
	EXPECT_TRUE( a_op_h );

	EXPECT_TRUE( b != a );
	EXPECT_FALSE( b != b );
	EXPECT_TRUE( b != c );
	EXPECT_TRUE( b != d );
	EXPECT_TRUE( b != e );
	EXPECT_TRUE( b != f );
	EXPECT_TRUE( b != g );
	EXPECT_TRUE( b != h );

	EXPECT_TRUE( c != a );
	EXPECT_TRUE( c != b );
	EXPECT_FALSE( c != c );
	EXPECT_TRUE( c != d );
	EXPECT_TRUE( c != e );
	EXPECT_TRUE( c != f );
	EXPECT_TRUE( c != g );
	EXPECT_TRUE( c != h );

	EXPECT_TRUE( d != a );
	EXPECT_TRUE( d != b );
	EXPECT_TRUE( d != c );
	EXPECT_FALSE( d != d );
	EXPECT_TRUE( d != e );
	EXPECT_TRUE( d != f );
	EXPECT_TRUE( d != g );
	EXPECT_TRUE( d != h );

	EXPECT_TRUE( e != a );
	EXPECT_TRUE( e != b );
	EXPECT_TRUE( e != c );
	EXPECT_TRUE( e != d );
	EXPECT_FALSE( e != e );
	EXPECT_TRUE( e != f );
	EXPECT_TRUE( e != g );
	EXPECT_TRUE( e != h );

	EXPECT_TRUE( f != a );
	EXPECT_TRUE( f != b );
	EXPECT_TRUE( f != c );
	EXPECT_TRUE( f != d );
	EXPECT_TRUE( f != e );
	EXPECT_FALSE( f != f );
	EXPECT_TRUE( f != g );
	EXPECT_TRUE( f != h );

	EXPECT_TRUE( g != a );
	EXPECT_TRUE( g != b );
	EXPECT_TRUE( g != c );
	EXPECT_TRUE( g != d );
	EXPECT_TRUE( g != e );
	EXPECT_TRUE( g != f );
	EXPECT_FALSE( g != g );
	EXPECT_TRUE( g != h );

	EXPECT_TRUE( h != a );
	EXPECT_TRUE( h != b );
	EXPECT_TRUE( h != c );
	EXPECT_TRUE( h != d );
	EXPECT_TRUE( h != e );
	EXPECT_TRUE( h != f );
	EXPECT_TRUE( h != g );
	EXPECT_FALSE( h != h );
}

TEST( de__math__vec3_int32_constexpr, operator_less_than )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a < a );
	constexpr bool a_op_b = ( a < b );
	constexpr bool a_op_c = ( a < c );
	constexpr bool a_op_d = ( a < d );
	constexpr bool a_op_e = ( a < e );
	constexpr bool a_op_f = ( a < f );
	constexpr bool a_op_g = ( a < g );
	constexpr bool a_op_h = ( a < h );
	EXPECT_FALSE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );
	EXPECT_FALSE( a_op_e );
	EXPECT_FALSE( a_op_f );
	EXPECT_FALSE( a_op_g );
	EXPECT_TRUE( a_op_h );

	EXPECT_FALSE( b < a );
	EXPECT_FALSE( b < b );
	EXPECT_FALSE( b < c );
	EXPECT_FALSE( b < d );
	EXPECT_FALSE( b < e );
	EXPECT_FALSE( b < f );
	EXPECT_FALSE( b < g );
	EXPECT_FALSE( b < h );

	EXPECT_FALSE( c < a );
	EXPECT_FALSE( c < b );
	EXPECT_FALSE( c < c );
	EXPECT_FALSE( c < d );
	EXPECT_FALSE( c < e );
	EXPECT_FALSE( c < f );
	EXPECT_FALSE( c < g );
	EXPECT_FALSE( c < h );

	EXPECT_FALSE( d < a );
	EXPECT_FALSE( d < b );
	EXPECT_FALSE( d < c );
	EXPECT_FALSE( d < d );
	EXPECT_FALSE( d < e );
	EXPECT_FALSE( d < f );
	EXPECT_FALSE( d < g );
	EXPECT_FALSE( d < h );

	EXPECT_FALSE( e < a );
	EXPECT_FALSE( e < b );
	EXPECT_FALSE( e < c );
	EXPECT_FALSE( e < d );
	EXPECT_FALSE( e < e );
	EXPECT_FALSE( e < f );
	EXPECT_FALSE( e < g );
	EXPECT_FALSE( e < h );

	EXPECT_FALSE( f < a );
	EXPECT_FALSE( f < b );
	EXPECT_FALSE( f < c );
	EXPECT_FALSE( f < d );
	EXPECT_FALSE( f < e );
	EXPECT_FALSE( f < f );
	EXPECT_FALSE( f < g );
	EXPECT_FALSE( f < h );

	EXPECT_FALSE( g < a );
	EXPECT_FALSE( g < b );
	EXPECT_FALSE( g < c );
	EXPECT_FALSE( g < d );
	EXPECT_FALSE( g < e );
	EXPECT_FALSE( g < f );
	EXPECT_FALSE( g < g );
	EXPECT_FALSE( g < h );

	EXPECT_FALSE( h < a );
	EXPECT_FALSE( h < b );
	EXPECT_FALSE( h < c );
	EXPECT_FALSE( h < d );
	EXPECT_FALSE( h < e );
	EXPECT_FALSE( h < f );
	EXPECT_FALSE( h < g );
	EXPECT_FALSE( h < h );
}

TEST( de__math__vec3_int32_constexpr, operator_less_than_equals )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a <= a );
	constexpr bool a_op_b = ( a <= b );
	constexpr bool a_op_c = ( a <= c );
	constexpr bool a_op_d = ( a <= d );
	constexpr bool a_op_e = ( a <= e );
	constexpr bool a_op_f = ( a <= f );
	constexpr bool a_op_g = ( a <= g );
	constexpr bool a_op_h = ( a <= h );
	EXPECT_TRUE( a_op_a );
	EXPECT_TRUE( a_op_b );
	EXPECT_TRUE( a_op_c );
	EXPECT_TRUE( a_op_d );
	EXPECT_TRUE( a_op_e );
	EXPECT_TRUE( a_op_f );
	EXPECT_TRUE( a_op_g );
	EXPECT_TRUE( a_op_h );

	EXPECT_FALSE( b <= a );
	EXPECT_TRUE( b <= b );
	EXPECT_FALSE( b <= c );
	EXPECT_TRUE( b <= d );
	EXPECT_FALSE( b <= e );
	EXPECT_TRUE( b <= f );
	EXPECT_FALSE( b <= g );
	EXPECT_TRUE( b <= h );

	EXPECT_FALSE( c <= a );
	EXPECT_FALSE( c <= b );
	EXPECT_TRUE( c <= c );
	EXPECT_TRUE( c <= d );
	EXPECT_FALSE( c <= e );
	EXPECT_FALSE( c <= f );
	EXPECT_TRUE( c <= g );
	EXPECT_TRUE( c <= h );

	EXPECT_FALSE( d <= a );
	EXPECT_FALSE( d <= b );
	EXPECT_FALSE( d <= c );
	EXPECT_TRUE( d <= d );
	EXPECT_FALSE( d <= e );
	EXPECT_FALSE( d <= f );
	EXPECT_FALSE( d <= g );
	EXPECT_TRUE( d <= h );

	EXPECT_FALSE( e <= a );
	EXPECT_FALSE( e <= b );
	EXPECT_FALSE( e <= c );
	EXPECT_FALSE( e <= d );
	EXPECT_TRUE( e <= e );
	EXPECT_TRUE( e <= f );
	EXPECT_TRUE( e <= g );
	EXPECT_TRUE( e <= h );

	EXPECT_FALSE( f <= a );
	EXPECT_FALSE( f <= b );
	EXPECT_FALSE( f <= c );
	EXPECT_FALSE( f <= d );
	EXPECT_FALSE( f <= e );
	EXPECT_TRUE( f <= f );
	EXPECT_FALSE( f <= g );
	EXPECT_TRUE( f <= h );

	EXPECT_FALSE( g <= a );
	EXPECT_FALSE( g <= b );
	EXPECT_FALSE( g <= c );
	EXPECT_FALSE( g <= d );
	EXPECT_FALSE( g <= e );
	EXPECT_FALSE( g <= f );
	EXPECT_TRUE( g <= g );
	EXPECT_TRUE( g <= h );

	EXPECT_FALSE( h <= a );
	EXPECT_FALSE( h <= b );
	EXPECT_FALSE( h <= c );
	EXPECT_FALSE( h <= d );
	EXPECT_FALSE( h <= e );
	EXPECT_FALSE( h <= f );
	EXPECT_FALSE( h <= g );
	EXPECT_TRUE( h <= h );
}

TEST( de__math__vec3_int32_constexpr, operator_greater_than )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a > a );
	constexpr bool a_op_b = ( a > b );
	constexpr bool a_op_c = ( a > c );
	constexpr bool a_op_d = ( a > d );
	constexpr bool a_op_e = ( a > e );
	constexpr bool a_op_f = ( a > f );
	constexpr bool a_op_g = ( a > g );
	constexpr bool a_op_h = ( a > h );
	EXPECT_FALSE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );
	EXPECT_FALSE( a_op_e );
	EXPECT_FALSE( a_op_f );
	EXPECT_FALSE( a_op_g );
	EXPECT_FALSE( a_op_h );

	EXPECT_FALSE( b > a );
	EXPECT_FALSE( b > b );
	EXPECT_FALSE( b > c );
	EXPECT_FALSE( b > d );
	EXPECT_FALSE( b > e );
	EXPECT_FALSE( b > f );
	EXPECT_FALSE( b > g );
	EXPECT_FALSE( b > h );

	EXPECT_FALSE( c > a );
	EXPECT_FALSE( c > b );
	EXPECT_FALSE( c > c );
	EXPECT_FALSE( c > d );
	EXPECT_FALSE( c > e );
	EXPECT_FALSE( c > f );
	EXPECT_FALSE( c > g );
	EXPECT_FALSE( c > h );

	EXPECT_FALSE( d > a );
	EXPECT_FALSE( d > b );
	EXPECT_FALSE( d > c );
	EXPECT_FALSE( d > d );
	EXPECT_FALSE( d > e );
	EXPECT_FALSE( d > f );
	EXPECT_FALSE( d > g );
	EXPECT_FALSE( d > h );

	EXPECT_FALSE( e > a );
	EXPECT_FALSE( e > b );
	EXPECT_FALSE( e > c );
	EXPECT_FALSE( e > d );
	EXPECT_FALSE( e > e );
	EXPECT_FALSE( e > f );
	EXPECT_FALSE( e > g );
	EXPECT_FALSE( e > h );

	EXPECT_FALSE( f > a );
	EXPECT_FALSE( f > b );
	EXPECT_FALSE( f > c );
	EXPECT_FALSE( f > d );
	EXPECT_FALSE( f > e );
	EXPECT_FALSE( f > f );
	EXPECT_FALSE( f > g );
	EXPECT_FALSE( f > h );

	EXPECT_FALSE( g > a );
	EXPECT_FALSE( g > b );
	EXPECT_FALSE( g > c );
	EXPECT_FALSE( g > d );
	EXPECT_FALSE( g > e );
	EXPECT_FALSE( g > f );
	EXPECT_FALSE( g > g );
	EXPECT_FALSE( g > h );

	EXPECT_TRUE( h > a );
	EXPECT_FALSE( h > b );
	EXPECT_FALSE( h > c );
	EXPECT_FALSE( h > d );
	EXPECT_FALSE( h > e );
	EXPECT_FALSE( h > f );
	EXPECT_FALSE( h > g );
	EXPECT_FALSE( h > h );
}

TEST( de__math__vec3_int32_constexpr, operator_greater_than_equals )
{
	constexpr vec3_int32 a{ 1, 1, 1 };
	constexpr vec3_int32 b{ 1, 2, 1 };
	constexpr vec3_int32 c{ 2, 1, 1 };
	constexpr vec3_int32 d{ 2, 2, 1 };
	constexpr vec3_int32 e{ 1, 1, 2 };
	constexpr vec3_int32 f{ 1, 2, 2 };
	constexpr vec3_int32 g{ 2, 1, 2 };
	constexpr vec3_int32 h{ 2, 2, 2 };

	constexpr bool a_op_a = ( a >= a );
	constexpr bool a_op_b = ( a >= b );
	constexpr bool a_op_c = ( a >= c );
	constexpr bool a_op_d = ( a >= d );
	constexpr bool a_op_e = ( a >= e );
	constexpr bool a_op_f = ( a >= f );
	constexpr bool a_op_g = ( a >= g );
	constexpr bool a_op_h = ( a >= h );
	EXPECT_TRUE( a_op_a );
	EXPECT_FALSE( a_op_b );
	EXPECT_FALSE( a_op_c );
	EXPECT_FALSE( a_op_d );
	EXPECT_FALSE( a_op_e );
	EXPECT_FALSE( a_op_f );
	EXPECT_FALSE( a_op_g );
	EXPECT_FALSE( a_op_h );

	EXPECT_TRUE( b >= a );
	EXPECT_TRUE( b >= b );
	EXPECT_FALSE( b >= c );
	EXPECT_FALSE( b >= d );
	EXPECT_FALSE( b >= e );
	EXPECT_FALSE( b >= f );
	EXPECT_FALSE( b >= g );
	EXPECT_FALSE( b >= h );

	EXPECT_TRUE( c >= a );
	EXPECT_FALSE( c >= b );
	EXPECT_TRUE( c >= c );
	EXPECT_FALSE( c >= d );
	EXPECT_FALSE( c >= e );
	EXPECT_FALSE( c >= f );
	EXPECT_FALSE( c >= g );
	EXPECT_FALSE( c >= h );

	EXPECT_TRUE( d >= a );
	EXPECT_TRUE( d >= b );
	EXPECT_TRUE( d >= c );
	EXPECT_TRUE( d >= d );
	EXPECT_FALSE( d >= e );
	EXPECT_FALSE( d >= f );
	EXPECT_FALSE( d >= g );
	EXPECT_FALSE( d >= h );

	EXPECT_TRUE( e >= a );
	EXPECT_FALSE( e >= b );
	EXPECT_FALSE( e >= c );
	EXPECT_FALSE( e >= d );
	EXPECT_TRUE( e >= e );
	EXPECT_FALSE( e >= f );
	EXPECT_FALSE( e >= g );
	EXPECT_FALSE( e >= h );

	EXPECT_TRUE( f >= a );
	EXPECT_TRUE( f >= b );
	EXPECT_FALSE( f >= c );
	EXPECT_FALSE( f >= d );
	EXPECT_TRUE( f >= e );
	EXPECT_TRUE( f >= f );
	EXPECT_FALSE( f >= g );
	EXPECT_FALSE( f >= h );

	EXPECT_TRUE( g >= a );
	EXPECT_FALSE( g >= b );
	EXPECT_TRUE( g >= c );
	EXPECT_FALSE( g >= d );
	EXPECT_TRUE( g >= e );
	EXPECT_FALSE( g >= f );
	EXPECT_TRUE( g >= g );
	EXPECT_FALSE( g >= h );

	EXPECT_TRUE( h >= a );
	EXPECT_TRUE( h >= b );
	EXPECT_TRUE( h >= c );
	EXPECT_TRUE( h >= d );
	EXPECT_TRUE( h >= e );
	EXPECT_TRUE( h >= f );
	EXPECT_TRUE( h >= g );
	EXPECT_TRUE( h >= h );
}

TEST( de__math__vec3_int32, operator_assignment )
{
	constexpr vec3_int32 uut_const{ 2, 4, 8 };
	vec3_int32           uut{ 1, 2, 3 };
	uut = uut_const;

	EXPECT_EQ( uut.x, 2 );
	EXPECT_EQ( uut.y, 4 );
	EXPECT_EQ( uut.z, 8 );
}

TEST( de__math__vec3_int32, operator_assignment_add )
{
	constexpr vec3_int32 uut_const{ 2, 4, 8 };
	vec3_int32           uut{ 1, 2, 3 };
	uut += uut_const;

	EXPECT_EQ( uut.x, 3 );
	EXPECT_EQ( uut.y, 6 );
	EXPECT_EQ( uut.z, 11 );
}

TEST( de__math__vec3_int32, operator_assignment_subtract )
{
	constexpr vec3_int32 uut_const{ 2, 4, 8 };
	vec3_int32           uut{ 1, 2, 3 };
	uut -= uut_const;

	EXPECT_EQ( uut.x, -1 );
	EXPECT_EQ( uut.y, -2 );
	EXPECT_EQ( uut.z, -5 );
}

TEST( de__math__vec3_int32, operator_assignment_multiply )
{
	constexpr vec3_int32 uut_const{ 2, 4, 8 };
	vec3_int32           uut{ 1, 2, 3 };
	uut *= uut_const;

	EXPECT_EQ( uut.x, 2 );
	EXPECT_EQ( uut.y, 8 );
	EXPECT_EQ( uut.z, 24 );
}

TEST( de__math__vec3_int32, operator_assignment_divide )
{
	constexpr vec3_int32 uut_const{ 2, 4, 8 };
	vec3_int32           uut{ 2, 8, 24 };
	uut /= uut_const;

	EXPECT_EQ( uut.x, 1 );
	EXPECT_EQ( uut.y, 2 );
	EXPECT_EQ( uut.z, 3 );
}

TEST( de__math__vec3_int32, operator_assignment_multiply_scalar )
{
	vec3_int32 uut{ 1, 2, 3 };
	uut *= 2;

	EXPECT_EQ( uut.x, 2 );
	EXPECT_EQ( uut.y, 4 );
	EXPECT_EQ( uut.z, 6 );
}

TEST( de__math__vec3_int32, operator_assignment_divide_scalar )
{
	vec3_int32 uut{ 2, 4, 8 };
	uut /= 2;

	EXPECT_EQ( uut.x, 1 );
	EXPECT_EQ( uut.y, 2 );
	EXPECT_EQ( uut.z, 4 );
}

/* END */
