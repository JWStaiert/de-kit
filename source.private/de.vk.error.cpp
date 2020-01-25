/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.vk.error.hpp"

#include "de.util.hpp"

#include <vulkan/vulkan.h>

#if (VK_ERROR_OUT_OF_POOL_MEMORY_KHR != VK_ERROR_OUT_OF_POOL_MEMORY)
#error "Need unique string for value VK_ERROR_OUT_OF_POOL_MEMORY_KHR in enum VkStatus."
#endif

#if (VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR != VK_ERROR_INVALID_EXTERNAL_HANDLE)
#error "Need unique string for value VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR in enum VkStatus."
#endif

#if (VK_ERROR_INVALID_DEVICE_ADDRESS_EXT != VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR)
#error "Need unique string for value VK_ERROR_INVALID_DEVICE_ADDRESS_EXT in enum VkStatus."
#endif

#if (VK_RESULT_BEGIN_RANGE != VK_ERROR_FRAGMENTED_POOL)
#error "Need unique strings for new error values in enum VkStatus."
#endif

#if (VK_RESULT_END_RANGE != VK_INCOMPLETE)
#error "Need unique strings for new status values in enum VkStatus."
#endif

namespace de
{
	namespace vk
	{
		/* JWS: This code will be called to populate an exception string so it must be thread safe and free of system calls and memory allocations. */

		/* thread_local makes access thread safe. */
		static thread_local de::util::cstring_array<1024> s_buffer;

		namespace error
		{
			const char * format( VkResult p_result )
			{
				s_buffer.reset( );
				s_buffer.append_cstring( "VkResult(" );
				s_buffer.append_hexadecimal( static_cast<std::int32_t>( p_result ) );
				s_buffer.append_cstring( ")=[" );

				switch ( p_result )
				{
				case VK_SUCCESS:
					s_buffer.append_cstring( "SUCCESS" );
					break;
				case VK_NOT_READY:
					s_buffer.append_cstring( "NOT_READY" );
					break;
				case VK_TIMEOUT:
					s_buffer.append_cstring( "TIMEOUT" );
					break;
				case VK_EVENT_SET:
					s_buffer.append_cstring( "EVENT_SET" );
					break;
				case VK_EVENT_RESET:
					s_buffer.append_cstring( "EVENT_RESET" );
					break;
				case VK_INCOMPLETE:
					s_buffer.append_cstring( "INCOMPLETE" );
					break;
				case VK_ERROR_OUT_OF_HOST_MEMORY:
					s_buffer.append_cstring( "OUT_OF_HOST_MEMORY" );
					break;
				case VK_ERROR_OUT_OF_DEVICE_MEMORY:
					s_buffer.append_cstring( "OUT_OF_DEVICE_MEMORY" );
					break;
				case VK_ERROR_INITIALIZATION_FAILED:
					s_buffer.append_cstring( "INITIALIZATION_FAILED" );
					break;
				case VK_ERROR_DEVICE_LOST:
					s_buffer.append_cstring( "DEVICE_LOST" );
					break;
				case VK_ERROR_MEMORY_MAP_FAILED:
					s_buffer.append_cstring( "MEMORY_MAP_FAILED" );
					break;
				case VK_ERROR_LAYER_NOT_PRESENT:
					s_buffer.append_cstring( "LAYER_NOT_PRESENT" );
					break;
				case VK_ERROR_EXTENSION_NOT_PRESENT:
					s_buffer.append_cstring( "EXTENSION_NOT_PRESENT" );
					break;
				case VK_ERROR_FEATURE_NOT_PRESENT:
					s_buffer.append_cstring( "FEATURE_NOT_PRESENT" );
					break;
				case VK_ERROR_INCOMPATIBLE_DRIVER:
					s_buffer.append_cstring( "INCOMPATIBLE_DRIVER" );
					break;
				case VK_ERROR_TOO_MANY_OBJECTS:
					s_buffer.append_cstring( "TOO_MANY_OBJECTS" );
					break;
				case VK_ERROR_FORMAT_NOT_SUPPORTED:
					s_buffer.append_cstring( "FORMAT_NOT_SUPPORTED" );
					break;
				case VK_ERROR_FRAGMENTED_POOL:
					s_buffer.append_cstring( "FRAGMENTED_POOL" );
					break;
				case VK_ERROR_OUT_OF_POOL_MEMORY:
					s_buffer.append_cstring( "OUT_OF_POOL_MEMORY" );
					break;
				case VK_ERROR_INVALID_EXTERNAL_HANDLE:
					s_buffer.append_cstring( "INVALID_EXTERNAL_HANDLE" );
					break;
				case VK_ERROR_SURFACE_LOST_KHR:
					s_buffer.append_cstring( "SURFACE_LOST_KHR" );
					break;
				case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
					s_buffer.append_cstring( "NATIVE_WINDOW_IN_USE_KHR" );
					break;
				case VK_SUBOPTIMAL_KHR:
					s_buffer.append_cstring( "SUBOPTIMAL_KHR" );
					break;
				case VK_ERROR_OUT_OF_DATE_KHR:
					s_buffer.append_cstring( "OUT_OF_DATE_KHR" );
					break;
				case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
					s_buffer.append_cstring( "INCOMPATIBLE_DISPLAY_KHR" );
					break;
				case VK_ERROR_VALIDATION_FAILED_EXT:
					s_buffer.append_cstring( "VALIDATION_FAILED_EXT" );
					break;
				case VK_ERROR_INVALID_SHADER_NV:
					s_buffer.append_cstring( "INVALID_SHADER_NV" );
					break;
				case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
					s_buffer.append_cstring( "INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT" );
					break;
				case VK_ERROR_FRAGMENTATION_EXT:
					s_buffer.append_cstring( "FRAGMENTATION_EXT" );
					break;
				case VK_ERROR_NOT_PERMITTED_EXT:
					s_buffer.append_cstring( "NOT_PERMITTED_EXT" );
					break;
				case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
					s_buffer.append_cstring( "FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT" );
					break;
				case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR:
					s_buffer.append_cstring( "INVALID_OPAQUE_CAPTURE_ADDRESS_KHR" );
					break;
				default:
					s_buffer.append_cstring( "unrecognized enum" );
					break;
				}

				s_buffer.append_cstring( "]." );

				return s_buffer;
			}
		}
	}
}

/* END */
