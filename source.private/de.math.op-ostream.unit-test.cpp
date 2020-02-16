/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.math.op-ostream.hpp"

#include <de.math.vec2.hpp>
#include <de.math.vec3.hpp>

#include <sstream>

#include <cstdint>

TEST( de__math__op_ostream, vec2_int8_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::int8_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_int16_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::int16_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_int32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::int32_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_int64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::int64_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_uint8_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::uint8_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_uint16_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::uint16_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_uint32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::uint32_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_uint64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<std::uint64_t> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 }" );
}

TEST( de__math__op_ostream, vec2_float32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<de::float32> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1.0e^0 , y = 2.0e^0 }" );
	FAIL( ) << "TODO: Decimal portion must contain proper number of zero digits for 32-bit floating point type." << std::endl
			<< "TODO: negative infinity test" << std::endl
			<< "TODO: negative subnormal maximum test" << std::endl
			<< "TODO: negative subnormal minimum test" << std::endl
			<< "TODO: negative normal maximum test" << std::endl
			<< "TODO: negative normal minimum test" << std::endl
			<< "TODO: negative zero test" << std::endl
			<< "TODO: positive zero test" << std::endl
			<< "TODO: positive subnormal minimum test" << std::endl
			<< "TODO: positive subnormal maximum test" << std::endl
			<< "TODO: positive normal minimum test" << std::endl
			<< "TODO: positive normal maximum test" << std::endl
			<< "TODO: positive infinity test";
}

TEST( de__math__op_ostream, vec2_float64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec2<de::float64> uut{ 1, 2 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1.0e^0 , y = 2.0e^0 }" );
	FAIL( ) << "TODO: Decimal portion must contain proper number of zero digits for 64-bit floating point type." << std::endl
			<< "TODO: negative infinity test" << std::endl
			<< "TODO: negative subnormal maximum test" << std::endl
			<< "TODO: negative subnormal minimum test" << std::endl
			<< "TODO: negative normal maximum test" << std::endl
			<< "TODO: negative normal minimum test" << std::endl
			<< "TODO: negative zero test" << std::endl
			<< "TODO: positive zero test" << std::endl
			<< "TODO: positive subnormal minimum test" << std::endl
			<< "TODO: positive subnormal maximum test" << std::endl
			<< "TODO: positive normal minimum test" << std::endl
			<< "TODO: positive normal maximum test" << std::endl
			<< "TODO: positive infinity test";
}

TEST( de__math__op_ostream, vec3_int8_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::int8_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_int16_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::int16_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_int32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::int32_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_int64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::int64_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_uint8_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::uint8_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_uint16_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::uint16_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_uint32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::uint32_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_uint64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<std::uint64_t> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1 , y = 2 , z = 3 }" );
}

TEST( de__math__op_ostream, vec3_float32_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<de::float32> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1.0e^0 , y = 2.0e^0 , z = 3.0e^0 }" );
	FAIL( ) << "TODO: Decimal portion must contain proper number of zero digits for 32-bit floating point type." << std::endl
			<< "TODO: negative infinity test" << std::endl
			<< "TODO: negative subnormal maximum test" << std::endl
			<< "TODO: negative subnormal minimum test" << std::endl
			<< "TODO: negative normal maximum test" << std::endl
			<< "TODO: negative normal minimum test" << std::endl
			<< "TODO: negative zero test" << std::endl
			<< "TODO: positive zero test" << std::endl
			<< "TODO: positive subnormal minimum test" << std::endl
			<< "TODO: positive subnormal maximum test" << std::endl
			<< "TODO: positive normal minimum test" << std::endl
			<< "TODO: positive normal maximum test" << std::endl
			<< "TODO: positive infinity test";
}

TEST( de__math__op_ostream, vec3_float64_operator_ostream )
{
	std::stringstream l_ostream{};

	de::math::vec3<de::float64> uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "{ x = 1.0e^0 , y = 2.0e^0 , z = 3.0e^0 }" );
	FAIL( ) << "TODO: Decimal portion must contain proper number of zero digits for 64-bit floating point type." << std::endl
			<< "TODO: negative infinity test" << std::endl
			<< "TODO: negative subnormal maximum test" << std::endl
			<< "TODO: negative subnormal minimum test" << std::endl
			<< "TODO: negative normal maximum test" << std::endl
			<< "TODO: negative normal minimum test" << std::endl
			<< "TODO: negative zero test" << std::endl
			<< "TODO: positive zero test" << std::endl
			<< "TODO: positive subnormal minimum test" << std::endl
			<< "TODO: positive subnormal maximum test" << std::endl
			<< "TODO: positive normal minimum test" << std::endl
			<< "TODO: positive normal maximum test" << std::endl
			<< "TODO: positive infinity test";
}

/* END */
