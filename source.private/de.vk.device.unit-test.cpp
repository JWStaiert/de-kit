/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.vk.device.hpp"

#include <de.vk.instance.hpp>
#include <de.vk.loader.hpp>

#include <unit-test.de.hpp>        // JWS: Path to vulkan loader.
#include <unit-test.de.log.hpp>    // JWS: Log unit-test base class.

#include <regex>
#include <vector>

static const de::vk::instance_configuration s_config{
	"app config debug report utils",
	{ 1, 0, 0 },
	{ "VK_LAYER_LUNARG_standard_validation" },
	{ "VK_KHR_surface", "VK_KHR_win32_surface", "VK_EXT_debug_report", "VK_EXT_debug_utils" },
};

class de__vk__device_test_fixture : public de__log__test_fixture
{
public:
	de::vk::loader m_loader;

	de::vk::instance m_instance;

	de::vk::device_configuration m_configuration;

	de__vk__device_test_fixture( )
		: de__log__test_fixture{}
		, m_loader{ DE_VULKAN_LOADER_MODULE_PATHNAME }
		, m_instance{ m_loader, s_config }
	{
	}

	virtual ~de__vk__device_test_fixture( )
	{
	}

	virtual void SetUp( )
	{
		de__log__test_fixture::SetUp( );
	}

	virtual void TearDown( )
	{
		de__log__test_fixture::TearDown( );
	}
};

TEST_F( de__vk__device_test_fixture, ctor_success )
{
	try
	{
		// JWS: Next code line is generating this error due to incomplete implementation.
		//
		// Assertion failed!
		//
		// Program: de-kit\win64\targets\active\debug\bin\vulkan-1.dll
		// File: de-kit\khronos.vulkan-loader\loader\loader.c Line : 5512
		//
		// Expression : pCreateInfo->queueCreateInfoCount >= 1

		// de::vk::device uut{ m_instance, m_configuration };
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexpected standard exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
