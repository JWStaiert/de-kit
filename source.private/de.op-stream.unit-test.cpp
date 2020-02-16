/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.op-ostream.hpp"

#include <de.version.hpp>

#include <sstream>

TEST( de__op_stream , de__version__ostream )
{
	std::stringstream l_ostream{};

	de::version uut{ 1, 2, 3 };

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "1.2.3" );
}

/* END */
