/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.vk.error.hpp"

#include <regex>
#include <string>

#include <cstring>

#include <vulkan/vulkan.h>

TEST( de__vk__error , format_UNRECOGNIZED )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_RESULT_MAX_ENUM ) ) , "vk_result = 7FFFFFFF = unrecognized enum" );
}

TEST( de__vk__error , format_VK_SUCCESS )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_SUCCESS  ) ) , "vk_result = 00000000 = SUCCESS" );
}

TEST( de__vk__error , format_VK_NOT_READY )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_NOT_READY ) ) , "vk_result = 00000001 = NOT_READY" );
}

TEST( de__vk__error , format_VK_TIMEOUT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_TIMEOUT ) ) , "vk_result = 00000002 = TIMEOUT" );
}

TEST( de__vk__error , format_VK_EVENT_SET )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_EVENT_SET ) ) , "vk_result = 00000003 = EVENT_SET" );
}

TEST( de__vk__error , format_VK_EVENT_RESET )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_EVENT_RESET ) ) , "vk_result = 00000004 = EVENT_RESET" );
}

TEST( de__vk__error , format_VK_INCOMPLETE )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_INCOMPLETE ) ) , "vk_result = 00000005 = INCOMPLETE" );
}

TEST( de__vk__error , format_VK_ERROR_OUT_OF_HOST_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_OUT_OF_HOST_MEMORY ) ) , "vk_result = FFFFFFFF = OUT_OF_HOST_MEMORY" );
}

TEST( de__vk__error , format_VK_ERROR_OUT_OF_DEVICE_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_OUT_OF_DEVICE_MEMORY ) ) , "vk_result = FFFFFFFE = OUT_OF_DEVICE_MEMORY" );
}

TEST( de__vk__error , format_VK_ERROR_INITIALIZATION_FAILED )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INITIALIZATION_FAILED ) ) , "vk_result = FFFFFFFD = INITIALIZATION_FAILED" );
}

TEST( de__vk__error , format_VK_ERROR_DEVICE_LOST )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_DEVICE_LOST ) ) , "vk_result = FFFFFFFC = DEVICE_LOST" );
}

TEST( de__vk__error , format_VK_ERROR_MEMORY_MAP_FAILED )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_MEMORY_MAP_FAILED ) ) , "vk_result = FFFFFFFB = MEMORY_MAP_FAILED" );
}

TEST( de__vk__error , format_VK_ERROR_LAYER_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_LAYER_NOT_PRESENT ) ) , "vk_result = FFFFFFFA = LAYER_NOT_PRESENT" );
}

TEST( de__vk__error , format_VK_ERROR_EXTENSION_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_EXTENSION_NOT_PRESENT ) ) , "vk_result = FFFFFFF9 = EXTENSION_NOT_PRESENT" );
}

TEST( de__vk__error , format_VK_ERROR_FEATURE_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_FEATURE_NOT_PRESENT ) ) , "vk_result = FFFFFFF8 = FEATURE_NOT_PRESENT" );
}

TEST( de__vk__error , format_VK_ERROR_INCOMPATIBLE_DRIVER )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INCOMPATIBLE_DRIVER ) ) , "vk_result = FFFFFFF7 = INCOMPATIBLE_DRIVER" );
}

TEST( de__vk__error , format_VK_ERROR_TOO_MANY_OBJECTS )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_TOO_MANY_OBJECTS ) ) , "vk_result = FFFFFFF6 = TOO_MANY_OBJECTS" );
}

TEST( de__vk__error , format_VK_ERROR_FORMAT_NOT_SUPPORTED )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_FORMAT_NOT_SUPPORTED ) ) , "vk_result = FFFFFFF5 = FORMAT_NOT_SUPPORTED" );
}

TEST( de__vk__error , format_VK_ERROR_FRAGMENTED_POOL )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_FRAGMENTED_POOL ) ) , "vk_result = FFFFFFF4 = FRAGMENTED_POOL" );
}

TEST( de__vk__error , format_VK_ERROR_OUT_OF_POOL_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_OUT_OF_POOL_MEMORY ) ) , "vk_result = C4642878 = OUT_OF_POOL_MEMORY" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_EXTERNAL_HANDLE )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_EXTERNAL_HANDLE ) ) , "vk_result = C4641CBD = INVALID_EXTERNAL_HANDLE" );
}

TEST( de__vk__error , format_VK_ERROR_SURFACE_LOST_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_SURFACE_LOST_KHR ) ) , "vk_result = C4653600 = SURFACE_LOST_KHR" );
}

TEST( de__vk__error , format_VK_ERROR_NATIVE_WINDOW_IN_USE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_NATIVE_WINDOW_IN_USE_KHR ) ) , "vk_result = C46535FF = NATIVE_WINDOW_IN_USE_KHR" );
}

TEST( de__vk__error , format_VK_SUBOPTIMAL_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_SUBOPTIMAL_KHR ) ) , "vk_result = 3B9ACDEB = SUBOPTIMAL_KHR" );
}

TEST( de__vk__error , format_VK_ERROR_OUT_OF_DATE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_OUT_OF_DATE_KHR ) ) , "vk_result = C4653214 = OUT_OF_DATE_KHR" );
}

TEST( de__vk__error , format_VK_ERROR_INCOMPATIBLE_DISPLAY_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INCOMPATIBLE_DISPLAY_KHR ) ) , "vk_result = C4652A47 = INCOMPATIBLE_DISPLAY_KHR" );
}

TEST( de__vk__error , format_VK_ERROR_VALIDATION_FAILED_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_VALIDATION_FAILED_EXT ) ) , "vk_result = C4650B07 = VALIDATION_FAILED_EXT" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_SHADER_NV )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_SHADER_NV ) ) , "vk_result = C4650720 = INVALID_SHADER_NV" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT ) ) , "vk_result = C462CCD0 = INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT" );
}

TEST( de__vk__error , format_VK_ERROR_FRAGMENTATION_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_FRAGMENTATION_EXT ) ) , "vk_result = C462C118 = FRAGMENTATION_EXT" );
}

TEST( de__vk__error , format_VK_ERROR_NOT_PERMITTED_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_NOT_PERMITTED_EXT ) ) , "vk_result = C4628E4F = NOT_PERMITTED_EXT" );
}

TEST( de__vk__error , format_VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT ) ) , "vk_result = C46151E8 = FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR ) ) , "vk_result = C4617CE0 = INVALID_OPAQUE_CAPTURE_ADDRESS_KHR" );
}

TEST( de__vk__error , format_VK_ERROR_OUT_OF_POOL_MEMORY_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_OUT_OF_POOL_MEMORY_KHR ) ) , "vk_result = C4642878 = OUT_OF_POOL_MEMORY" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR ) ) , "vk_result = C4641CBD = INVALID_EXTERNAL_HANDLE" );
}

TEST( de__vk__error , format_VK_ERROR_INVALID_DEVICE_ADDRESS_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format_result( VK_ERROR_INVALID_DEVICE_ADDRESS_EXT ) ) , "vk_result = C4617CE0 = INVALID_OPAQUE_CAPTURE_ADDRESS_KHR" );
}

namespace de
{
	namespace vk
	{
		static VkResult _test_function( VkResult p_rv )
		{
			return p_rv;
		}
	}
}

TEST( de__vk__error , DE__VK__ERROR__CHECK_RESULT_success )
{
	try
	{
		DE__VK__ERROR__CHECK_RESULT( test_function( VK_SUCCESS ) );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__vk__error , DE__VK__ERROR__CHECK_RESULT_failure )
{
	try
	{
		DE__VK__ERROR__CHECK_RESULT( test_function( VK_NOT_READY ) );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "de__vk__error_DE__VK__ERROR__CHECK_RESULT_failure_Test::TestBody@[0-9]+\\| Expression indicates failure: \\( vk_result = de::vk::_test_function\\( VK_NOT_READY \\) \\) != VK_SUCCESS \\| vk_result = 00000001 = NOT_READY" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

namespace de
{
	namespace vk
	{
		static void * _uut_function( const char * p_value )
		{
			if ( ( p_value != nullptr ) && ( std::strcmp( p_value , "success value" ) == 0 ) )
			{
				return _uut_function;
			}
			else
			{
				return nullptr;
			}
		}
	}
}

static void * uut_test_function( const char * p_value )
{
	DE__VK__ERROR__CHECK_AND_RETURN( void * , uut_function( p_value ) , nullptr , p_value );
}

TEST( de__vk__error , DE__VK__ERROR__CHECK_AND_RETURN_success )
{
	try
	{
		uut_test_function( "success value" );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__vk__error , DE__VK__ERROR__CHECK_AND_RETURN_failure )
{
	try
	{
		uut_test_function( "not success value" );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "uut_test_function@[0-9]+\\| Expression indicates failure: \\( vk_return_value = de::vk::_uut_function\\( p_value \\) \\) == nullptr \\| p_value = \"not success value\"" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

TEST( de__vk__error , DE__VK__ERROR__CHECK_AND_RETURN_failure_nullptr )
{
	try
	{
		uut_test_function( nullptr );

		FAIL( ) << "Expected exception.";
	}
	catch ( const std::runtime_error & exc )
	{
		std::regex re { "uut_test_function@[0-9]+\\| Expression indicates failure: \\( vk_return_value = de::vk::_uut_function\\( p_value \\) \\) == nullptr \\| p_value = nullptr" };

		EXPECT_TRUE( std::regex_match( exc.what( ) , re ) ) << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

/* END */
