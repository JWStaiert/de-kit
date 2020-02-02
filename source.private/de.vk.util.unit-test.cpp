/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.vk.util.hpp"

#include <vulkan/vulkan.h>

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

TEST( de__vk__handle , dtor_calls_deleter )
{
	test_type uut_object;

	{
		de::vk::handle uut { test_type_deleter };

		uut = &uut_object;
	}

	EXPECT_TRUE( uut_object.deleted );
}

/* END */
