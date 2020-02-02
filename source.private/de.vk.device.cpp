/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.vk.device.hpp"

#include "de.vk.error.hpp"
#include "de.vk.instance.hpp"
#include "de.vk.util.hpp"

#include <vulkan/vulkan.h>

static inline VkDevice vk_device( const de::vk::handle & p_handle )
{
	return static_cast<VkDevice>( static_cast<void *>( const_cast<de::vk::handle &>( p_handle ) ) );
}

namespace de
{
	namespace vk
	{
		DE__VK__FUNCTION( vkCreateDevice );

		DE__VK__FUNCTION( vkDestroyDevice );

		DE__VK__FUNCTION( vkGetDeviceProcAddr );

		void device::create_device( )
		{
			DE__VK__FUNCTION_LOAD( vkCreateDevice , m_instance.get_function_address );

			/* Select queues. */
			std::vector<VkDeviceQueueCreateInfo> l_queue_create_infos { };
			// TODO: Implement this.

			/* Create temporary array of pointers to const char *. from configuraiton layer names. */
			std::vector<const char *> l_layer_strings { };
			for ( auto i = 0 ; i < m_instance.configuration( ).layer_names.size( ) ; ++i ) l_layer_strings.push_back( m_instance.configuration( ).layer_names[ i ].c_str( ) );

			/* Create temporary array of pointers to const char *. from configuraiton extension names. */
			std::vector<const char *> l_extension_strings { };
			for ( auto i = 0 ; i < m_instance.configuration( ).extension_names.size( ) ; ++i ) l_extension_strings.push_back( m_instance.configuration( ).extension_names[ i ].c_str( ) );

			/* Enable device features. */
			VkPhysicalDeviceFeatures l_enabled_device_features { };

			/* Create device. */
			VkDeviceCreateInfo l_device_create_info { };
			l_device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			l_device_create_info.flags                   = 0;
			l_device_create_info.pNext                   = nullptr;
			l_device_create_info.queueCreateInfoCount    = static_cast<std::uint32_t>( l_queue_create_infos.size( ) );
			l_device_create_info.pQueueCreateInfos       = l_queue_create_infos.data( );;
			l_device_create_info.enabledLayerCount       = static_cast<std::uint32_t>( l_layer_strings.size( ) );
			l_device_create_info.ppEnabledLayerNames     = l_layer_strings.data( );
			l_device_create_info.enabledExtensionCount   = static_cast<std::uint32_t>( l_extension_strings.size( ) );;
			l_device_create_info.ppEnabledExtensionNames = l_extension_strings.data( );
			l_device_create_info.pEnabledFeatures        = &l_enabled_device_features;

			VkDevice l_device { };

			DE__VK__ERROR__CHECK_RESULT( vkCreateDevice( static_cast<VkPhysicalDevice>( m_configuration.handle ) , &l_device_create_info , nullptr , &l_device ) );

			m_device = l_device;

			DE__VK__FUNCTION_LOAD( vkDestroyDevice , get_function_address );
		}

		static void vk_device_deleter( void * p_device )
		{
			DE__VK__FUNCTION_CALL( vkDestroyDevice( static_cast<VkDevice>( p_device ) , nullptr ) );;
		}

		device::device( const instance & p_instance , const device_configuration & p_configuration )
			: m_instance      { p_instance }
			, m_configuration { p_configuration }
			, m_device        { vk_device_deleter }
		{
			create_device( );
		}

		void * device::get_function_address( const char * p_function_name )
		{
			DE__VK__ERROR__CHECK_AND_RETURN( void * , vkGetDeviceProcAddr( vk_device( m_device ) , p_function_name ) , nullptr , p_function_name );
		}
	}
}

/* END */
