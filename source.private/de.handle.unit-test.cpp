/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.handle.hpp"

struct test_type
{
	bool deleted { false };
};

void test_type_deleter( void * p_handle )
{
	if ( p_handle != nullptr )
	{
		static_cast<test_type *>( p_handle )->deleted = true;
	}
}

TEST( de__handle , dtor_deleter_called )
{
	test_type test_object;

	ASSERT_FALSE( test_object.deleted );

	{
		de::handle<void *> uut { test_type_deleter , nullptr };

		uut = &test_object;
	}

	EXPECT_TRUE( test_object.deleted );
}

TEST( de__handle , cast_operator )
{
	test_type test_object;

	de::handle<void *> uut { test_type_deleter , nullptr };

	uut = &test_object;

	void * uut_ptr = &test_object;

	EXPECT_TRUE( uut == uut_ptr );
}

TEST( de__handle , cast_operator_const )
{
	test_type test_object;

	de::handle<void *> uut { test_type_deleter , nullptr };

	uut = &test_object;

	const void * uut_const_ptr = &test_object;

	EXPECT_TRUE( uut == uut_const_ptr );
}

/* END */
