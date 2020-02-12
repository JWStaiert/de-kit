/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.vk.instance.hpp"

#include <de.vk.loader.hpp>

#include <unit-test.de.hpp>        // JWS: Path to vulkan loader.
#include <unit-test.de.log.hpp>    // JWS: Log unit-test base class.

#include <regex>
#include <vector>

static const de::vk::instance_configuration s_config_simple{
	"app config simple",
	{ 1, 0, 0 },
	{ "VK_LAYER_LUNARG_standard_validation" },
	{ "VK_KHR_surface", "VK_KHR_win32_surface" },
};

static const de::vk::instance_configuration s_config_debug_report{
	"app config debug report",
	{ 1, 1, 0 },
	{ "VK_LAYER_LUNARG_standard_validation" },
	{ "VK_KHR_surface", "VK_KHR_win32_surface", "VK_EXT_debug_report" },
};

static const de::vk::instance_configuration s_config_debug_utils{
	"app config debug utils",
	{ 1, 2, 0 },
	{ "VK_LAYER_LUNARG_standard_validation" },
	{ "VK_KHR_surface", "VK_KHR_win32_surface", "VK_EXT_debug_utils" },
};

static const de::vk::instance_configuration s_config_debug_report_utils{
	"app config debug report utils",
	{ 1, 3, 0 },
	{ "VK_LAYER_LUNARG_standard_validation" },
	{ "VK_KHR_surface", "VK_KHR_win32_surface", "VK_EXT_debug_report", "VK_EXT_debug_utils" },
};

class de__vk__instance_test_fixture : public de__log__test_fixture
{
public:
	de::vk::loader m_loader;

	de__vk__instance_test_fixture( )
		: de__log__test_fixture{}
		, m_loader{ DE_VULKAN_LOADER_MODULE_PATHNAME }
	{
	}

	virtual ~de__vk__instance_test_fixture( )
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

#if 0
TEST_F( de__vk__instance_test , ctor_simple_config_success )
{
	try
	{
		de::vk::instance uut { m_loader , s_config_simple };
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

TEST_F( de__vk__instance_test , ctor_invalid_layer_failure )
{
	try
	{
		de::vk::instance_configuration l_invalid_layer_config { s_config_simple };
		l_invalid_layer_config.layer_names.push_back( "SOME_INVALID_LAYER" );

		de::vk::instance uut { m_loader , l_invalid_layer_config };

		FAIL( ) << "Expected exception.";
	}
	catch ( [ [ maybe_unused ] ] const std::logic_error & exc )
	{
		SUCCEED( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

TEST_F( de__vk__instance_test , ctor_invalid_extension_failure )
{
	try
	{
		de::vk::instance_configuration l_invalid_extension_config { s_config_simple };
		l_invalid_extension_config.extension_names.push_back( "SOME_INVALID_EXTENSION" );

		de::vk::instance uut { m_loader , l_invalid_extension_config };

		FAIL( ) << "Expected exception.";
	}
	catch ( [ [ maybe_unused ] ] const std::logic_error & exc )
	{
		SUCCEED( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

TEST_F( de__vk__instance_test , ctor_debug_report_config_success )
{
	try
	{
		de::vk::instance uut { m_loader , s_config_debug_report };

		ProcessLog( );

		EXPECT_EQ( m_log_lines.size( ) , 1 );
		EXPECT_EQ( m_log_lines[ 0 ] , "Layer [VK_EXT_debug_report] enabled." );

		ClearLog( );
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
#endif

TEST_F( de__vk__instance_test_fixture, ctor_debug_utils_config_success )
{
	try
	{
		de::vk::instance uut{ m_loader, s_config_debug_utils };

#if 0
		for ( auto device : uut.physical_devices( ) )
		{
			std::cerr << device.name << std::endl;
			std::cerr << std::string( device.api_version ) << std::endl;

			for ( auto extension : device.extension_names )
			{
				std::cerr << extension << std::endl;
			}
		}
#endif

		ProcessLog( );

		EXPECT_EQ( m_log_lines.size( ), 1 );
		EXPECT_EQ( m_log_lines[ 0 ], "Layer [VK_EXT_debug_utils] enabled." );

		ClearLog( );
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexpected exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

TEST_F( de__vk__instance_test_fixture, ctor_debug_report_utils_config_success )
{
	try
	{
		de::vk::instance uut{ m_loader, s_config_debug_report_utils };

		ProcessLog( );

		EXPECT_EQ( m_log_lines.size( ), 2 );
		EXPECT_EQ( m_log_lines[ 0 ], "Layer [VK_EXT_debug_report] enabled." );
		EXPECT_EQ( m_log_lines[ 1 ], "Layer [VK_EXT_debug_utils] enabled." );

		ClearLog( );
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexpected exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

/* END */
