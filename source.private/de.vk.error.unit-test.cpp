/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.vk.error.hpp"

#include <string>
#include <vulkan/vulkan.h>

TEST( de__vk__error , _format_UNRECOGNIZED )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_RESULT_MAX_ENUM ) ) , "VkResult(7FFFFFFF)=[unrecognized enum]." );
}

TEST( de__vk__error , _format_VK_SUCCESS )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_SUCCESS  ) ) , "VkResult(00000000)=[SUCCESS]." );
}

TEST( de__vk__error , _format_VK_NOT_READY )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_NOT_READY ) ) , "VkResult(00000001)=[NOT_READY]." );
}

TEST( de__vk__error , _format_VK_TIMEOUT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_TIMEOUT ) ) , "VkResult(00000002)=[TIMEOUT]." );
}

TEST( de__vk__error , _format_VK_EVENT_SET )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_EVENT_SET ) ) , "VkResult(00000003)=[EVENT_SET]." );
}

TEST( de__vk__error , _format_VK_EVENT_RESET )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_EVENT_RESET ) ) , "VkResult(00000004)=[EVENT_RESET]." );
}

TEST( de__vk__error , _format_VK_INCOMPLETE )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_INCOMPLETE ) ) , "VkResult(00000005)=[INCOMPLETE]." );
}

TEST( de__vk__error , _format_VK_ERROR_OUT_OF_HOST_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_OUT_OF_HOST_MEMORY ) ) , "VkResult(FFFFFFFF)=[OUT_OF_HOST_MEMORY]." );
}

TEST( de__vk__error , _format_VK_ERROR_OUT_OF_DEVICE_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_OUT_OF_DEVICE_MEMORY ) ) , "VkResult(FFFFFFFE)=[OUT_OF_DEVICE_MEMORY]." );
}

TEST( de__vk__error , _format_VK_ERROR_INITIALIZATION_FAILED )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INITIALIZATION_FAILED ) ) , "VkResult(FFFFFFFD)=[INITIALIZATION_FAILED]." );
}

TEST( de__vk__error , _format_VK_ERROR_DEVICE_LOST )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_DEVICE_LOST ) ) , "VkResult(FFFFFFFC)=[DEVICE_LOST]." );
}

TEST( de__vk__error , _format_VK_ERROR_MEMORY_MAP_FAILED )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_MEMORY_MAP_FAILED ) ) , "VkResult(FFFFFFFB)=[MEMORY_MAP_FAILED]." );
}

TEST( de__vk__error , _format_VK_ERROR_LAYER_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_LAYER_NOT_PRESENT ) ) , "VkResult(FFFFFFFA)=[LAYER_NOT_PRESENT]." );
}

TEST( de__vk__error , _format_VK_ERROR_EXTENSION_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_EXTENSION_NOT_PRESENT ) ) , "VkResult(FFFFFFF9)=[EXTENSION_NOT_PRESENT]." );
}

TEST( de__vk__error , _format_VK_ERROR_FEATURE_NOT_PRESENT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_FEATURE_NOT_PRESENT ) ) , "VkResult(FFFFFFF8)=[FEATURE_NOT_PRESENT]." );
}

TEST( de__vk__error , _format_VK_ERROR_INCOMPATIBLE_DRIVER )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INCOMPATIBLE_DRIVER ) ) , "VkResult(FFFFFFF7)=[INCOMPATIBLE_DRIVER]." );
}

TEST( de__vk__error , _format_VK_ERROR_TOO_MANY_OBJECTS )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_TOO_MANY_OBJECTS ) ) , "VkResult(FFFFFFF6)=[TOO_MANY_OBJECTS]." );
}

TEST( de__vk__error , _format_VK_ERROR_FORMAT_NOT_SUPPORTED )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_FORMAT_NOT_SUPPORTED ) ) , "VkResult(FFFFFFF5)=[FORMAT_NOT_SUPPORTED]." );
}

TEST( de__vk__error , _format_VK_ERROR_FRAGMENTED_POOL )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_FRAGMENTED_POOL ) ) , "VkResult(FFFFFFF4)=[FRAGMENTED_POOL]." );
}

TEST( de__vk__error , _format_VK_ERROR_OUT_OF_POOL_MEMORY )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_OUT_OF_POOL_MEMORY ) ) , "VkResult(C4642878)=[OUT_OF_POOL_MEMORY]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_EXTERNAL_HANDLE )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_EXTERNAL_HANDLE ) ) , "VkResult(C4641CBD)=[INVALID_EXTERNAL_HANDLE]." );
}

TEST( de__vk__error , _format_VK_ERROR_SURFACE_LOST_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_SURFACE_LOST_KHR ) ) , "VkResult(C4653600)=[SURFACE_LOST_KHR]." );
}

TEST( de__vk__error , _format_VK_ERROR_NATIVE_WINDOW_IN_USE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_NATIVE_WINDOW_IN_USE_KHR ) ) , "VkResult(C46535FF)=[NATIVE_WINDOW_IN_USE_KHR]." );
}

TEST( de__vk__error , _format_VK_SUBOPTIMAL_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_SUBOPTIMAL_KHR ) ) , "VkResult(3B9ACDEB)=[SUBOPTIMAL_KHR]." );
}

TEST( de__vk__error , _format_VK_ERROR_OUT_OF_DATE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_OUT_OF_DATE_KHR ) ) , "VkResult(C4653214)=[OUT_OF_DATE_KHR]." );
}

TEST( de__vk__error , _format_VK_ERROR_INCOMPATIBLE_DISPLAY_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INCOMPATIBLE_DISPLAY_KHR ) ) , "VkResult(C4652A47)=[INCOMPATIBLE_DISPLAY_KHR]." );
}

TEST( de__vk__error , _format_VK_ERROR_VALIDATION_FAILED_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_VALIDATION_FAILED_EXT ) ) , "VkResult(C4650B07)=[VALIDATION_FAILED_EXT]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_SHADER_NV )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_SHADER_NV ) ) , "VkResult(C4650720)=[INVALID_SHADER_NV]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT ) ) , "VkResult(C462CCD0)=[INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT]." );
}

TEST( de__vk__error , _format_VK_ERROR_FRAGMENTATION_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_FRAGMENTATION_EXT ) ) , "VkResult(C462C118)=[FRAGMENTATION_EXT]." );
}

TEST( de__vk__error , _format_VK_ERROR_NOT_PERMITTED_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_NOT_PERMITTED_EXT ) ) , "VkResult(C4628E4F)=[NOT_PERMITTED_EXT]." );
}

TEST( de__vk__error , _format_VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT ) ) , "VkResult(C46151E8)=[FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR ) ) , "VkResult(C4617CE0)=[INVALID_OPAQUE_CAPTURE_ADDRESS_KHR]." );
}

TEST( de__vk__error , _format_VK_ERROR_OUT_OF_POOL_MEMORY_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_OUT_OF_POOL_MEMORY_KHR ) ) , "VkResult(C4642878)=[OUT_OF_POOL_MEMORY]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR ) ) , "VkResult(C4641CBD)=[INVALID_EXTERNAL_HANDLE]." );
}

TEST( de__vk__error , _format_VK_ERROR_INVALID_DEVICE_ADDRESS_EXT )
{
	EXPECT_EQ( std::string( de::vk::error::format( VK_ERROR_INVALID_DEVICE_ADDRESS_EXT ) ) , "VkResult(C4617CE0)=[INVALID_OPAQUE_CAPTURE_ADDRESS_KHR]." );
}


/* END */
