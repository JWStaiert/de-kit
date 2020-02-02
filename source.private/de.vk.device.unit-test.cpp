/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.vk.device.hpp"
#include "de.vk.instance.hpp"
#include "de.vk.loader.hpp"

#include "de.log.unit-test.hpp" // JWS: Log unit-test base class. 
#include "de.unit-test.hpp" // JWS: Path to vulkan loader.

#include <regex>
#include <vector>

static const de::vk::instance_configuration s_config {
	"app config debug report utils" ,
	{ 1 , 0 , 0 } ,
	{ "VK_LAYER_LUNARG_standard_validation" } ,
	{ "VK_KHR_surface" , "VK_KHR_win32_surface" , "VK_EXT_debug_report" , "VK_EXT_debug_utils" } ,
};

class de__vk__device_test : public de__log__test
{
public:

	de::vk::loader m_loader;

	de::vk::instance m_instance;

	de::vk::device_configuration m_configuration;

	de__vk__device_test( )
		: de__log__test { }
		, m_loader { DE_VULKAN_LOADER_MODULE_PATHNAME }
		, m_instance { m_loader , s_config }
	{
	}

	virtual ~de__vk__device_test( )
	{
	}

	virtual void SetUp( )
	{
		de__log__test::SetUp( );
	}

	virtual void TearDown( )
	{
		de__log__test::TearDown( );
	}
};

TEST_F( de__vk__device_test , ctor_success )
{
	try
	{
		de::vk::device uut { m_instance, m_configuration };
	}
	catch ( const std::exception & exc )
	{
		FAIL( ) << "Unexpected exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

/* END */
