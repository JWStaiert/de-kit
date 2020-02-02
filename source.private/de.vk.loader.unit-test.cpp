/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.vk.loader.hpp"

#include "de.unit-test.hpp" // JWS: Contains path to vulkan loader.

#include <regex>
#include <vector>

TEST( de__vk__loader , ctor_success )
{
	try
	{
		de::vk::loader uut { DE_TEST_MODULE_PATHNAME };

		/* API Version. */
		EXPECT_EQ( uut.api_version( ) , "5.50.500" );

		/* GLOBAL Extensions. */
		ASSERT_EQ( uut.extensions( ).size( ) , 3 );
		EXPECT_EQ( uut.extensions( )[ 0 ].name , "GLOBAL_EXTENSION_1" );
		EXPECT_EQ( uut.extensions( )[ 0 ].spec_version , "1.2.3" );

		EXPECT_EQ( uut.extensions( )[ 1 ].name , "GLOBAL_EXTENSION_2" );
		EXPECT_EQ( uut.extensions( )[ 1 ].spec_version , "2.4.6" );

		EXPECT_EQ( uut.extensions( )[ 2 ].name , "GLOBAL_EXTENSION_3" );
		EXPECT_EQ( uut.extensions( )[ 2 ].spec_version , "3.6.9" );

		/* LAYERs */
		ASSERT_EQ( uut.layers( ).size( ) , 2 );
		EXPECT_EQ( uut.layers( )[ 0 ].name , "LAYER_1" );
		EXPECT_EQ( uut.layers( )[ 0 ].spec_version , "1.10.100" );
		EXPECT_EQ( uut.layers( )[ 0 ].implementation_version , "2.20.200" );
		EXPECT_EQ( uut.layers( )[ 0 ].description , "First unit test layer." );
		ASSERT_EQ( uut.layers( )[ 0 ].extensions.size( ) , 2 );

		EXPECT_EQ( uut.layers( )[ 0 ].extensions[ 0 ].name , "LAYER_1_EXTENSION_1" );
		EXPECT_EQ( uut.layers( )[ 0 ].extensions[ 0 ].spec_version , "4.8.12" );

		EXPECT_EQ( uut.layers( )[ 0 ].extensions[ 1 ].name , "LAYER_1_EXTENSION_2" );
		EXPECT_EQ( uut.layers( )[ 0 ].extensions[ 1 ].spec_version , "5.10.15" );

		EXPECT_EQ( uut.layers( )[ 1 ].name , "LAYER_2" );
		EXPECT_EQ( uut.layers( )[ 1 ].spec_version , "1.2.3" );
		EXPECT_EQ( uut.layers( )[ 1 ].implementation_version , "2.4.6" );
		EXPECT_EQ( uut.layers( )[ 1 ].description , "Second unit test layer." );
		EXPECT_EQ( uut.layers( )[ 1 ].extensions.size( ) , 0 );
	}
	catch ( const std::runtime_error & exc )
	{
		FAIL( ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__vk__loader , get_function_address_throws )
{
	try
	{
		de::vk::loader uut { DE_TEST_MODULE_PATHNAME };

		uut.get_function_address( "" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "de::vk::loader::get_function_address@[0-9]+\\| Expression indicates failure: \\( vk_return_value = de::vk::_vkGetInstanceProcAddr\\( nullptr , p_function_name \\) \\) == nullptr \\| p_function_name = \"\"" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__vk__loader__real_vulkan , ctor_success )
{
	try
	{
		de::vk::loader uut { DE_VULKAN_LOADER_MODULE_PATHNAME };

		/* Verify real vulkan support has necessary layers for unit testing. */
		std::vector<std::string> uut_layers { };
		for ( auto layer : uut.layers( ) ) uut_layers.push_back( layer.name );
		//for ( auto i : uut_layers ) std::cout << i << std::endl;
		EXPECT_TRUE( std::end( uut_layers ) != std::find( std::begin( uut_layers ) , std::end( uut_layers  ) , std::string( "VK_LAYER_LUNARG_standard_validation" ) ) );

		/* Verify real vulkan support has necessary extensions for unit testing. */
		std::vector<std::string> uut_extensions { };
		for ( auto extension : uut.extensions( ) ) uut_extensions.push_back( extension.name );
		//for ( auto i : uut_extensions ) std::cout << i << std::endl;
		EXPECT_TRUE( std::end( uut_extensions ) != std::find( std::begin( uut_extensions ) , std::end( uut_extensions ) , std::string( "VK_KHR_surface" ) ) );
		EXPECT_TRUE( std::end( uut_extensions ) != std::find( std::begin( uut_extensions ) , std::end( uut_extensions ) , std::string( "VK_KHR_win32_surface" ) ) );
		EXPECT_TRUE( std::end( uut_extensions ) != std::find( std::begin( uut_extensions ) , std::end( uut_extensions ) , std::string( "VK_EXT_debug_report" ) ) );
		EXPECT_TRUE( std::end( uut_extensions ) != std::find( std::begin( uut_extensions ) , std::end( uut_extensions ) , std::string( "VK_EXT_debug_utils" ) ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
