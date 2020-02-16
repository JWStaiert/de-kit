/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.vk.instance.hpp"

#include <de.log.hpp>
#include <de.util.hpp>

#include <de.vk.error.hpp>
#include <de.vk.function.hpp>
#include <de.vk.loader.hpp>

#include <algorithm>
#include <iostream>

#include <vulkan/vulkan.h>

namespace de
{
	namespace vk
	{
		DE__VK__FUNCTION_EXTERN( vkGetInstanceProcAddr );

		DE__VK__FUNCTION( vkCreateInstance );

		DE__VK__FUNCTION( vkCreateDebugReportCallbackEXT );

		DE__VK__FUNCTION( vkCreateDebugUtilsMessengerEXT );

		DE__VK__FUNCTION( vkDestroyDebugReportCallbackEXT );

		DE__VK__FUNCTION( vkDestroyDebugUtilsMessengerEXT );

		DE__VK__FUNCTION( vkDestroyInstance );

		DE__VK__FUNCTION( vkEnumeratePhysicalDevices );

		DE__VK__FUNCTION( vkGetPhysicalDeviceProperties );

		DE__VK__FUNCTION( vkGetPhysicalDeviceFeatures );

		DE__VK__FUNCTION( vkGetPhysicalDeviceMemoryProperties );

		DE__VK__FUNCTION( vkGetPhysicalDeviceQueueFamilyProperties );

		DE__VK__FUNCTION( vkEnumerateDeviceLayerProperties );

		DE__VK__FUNCTION( vkEnumerateDeviceExtensionProperties );

		DE__VK__FUNCTION( vkGetPhysicalDeviceFormatProperties );

		DE__VK__FUNCTION( vkGetPhysicalDeviceImageFormatProperties );

		void instance::assert_layers_available( )
		{
			layer_names l_available_layers{};
			for ( auto layer : m_loader.layers( ) )
				l_available_layers.push_back( layer.name );

			for ( auto layer_name : m_configuration.layer_names )
			{
				DE__EXCEPTION__ASSERT( std::find( std::begin( l_available_layers ), std::end( l_available_layers ), layer_name ) != std::end( l_available_layers ) );
			}
		}

		void instance::assert_extensions_available( )
		{
			layer_names l_available_extensions{};
			for ( auto extension : m_loader.extensions( ) )
				l_available_extensions.push_back( extension.name );

			for ( auto layer : m_loader.layers( ) )
			{
				for ( auto layer_extension : layer.extensions )
					l_available_extensions.push_back( layer_extension.name );
			}

			for ( auto extension_name : m_configuration.extension_names )
			{
				DE__EXCEPTION__ASSERT( std::find( std::begin( l_available_extensions ), std::end( l_available_extensions ), extension_name ) != std::end( l_available_extensions ) );
			}
		}

		void instance::create_instance( )
		{
			DE__VK__FUNCTION_LOAD( vkCreateInstance, m_loader.get_function_address );

			VkApplicationInfo l_app_info{};
			l_app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			;
			l_app_info.pApplicationName   = m_configuration.application_name.c_str( );
			l_app_info.applicationVersion = m_configuration.application_version.raw( );
			l_app_info.pEngineName        = "de-kit";
			l_app_info.engineVersion      = VK_MAKE_VERSION( 0, 0, 0 );
			l_app_info.apiVersion         = m_configuration.api_version.raw( );

			/* Create temporary array of pointers to const char *. from configuraiton layer names. */
			std::vector<const char*> l_layer_strings{};
			for ( auto i = 0; i < m_configuration.layer_names.size( ); ++i )
				l_layer_strings.push_back( m_configuration.layer_names[ i ].c_str( ) );

			/* Create temporary array of pointers to const char *. from configuraiton extension names. */
			std::vector<const char*> l_extension_strings{};
			for ( auto i = 0; i < m_configuration.extension_names.size( ); ++i )
				l_extension_strings.push_back( m_configuration.extension_names[ i ].c_str( ) );

			VkInstanceCreateInfo l_create_info{};
			l_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			l_create_info.pApplicationInfo        = &l_app_info;
			l_create_info.enabledLayerCount       = static_cast<std::uint32_t>( l_layer_strings.size( ) );
			l_create_info.ppEnabledLayerNames     = l_layer_strings.data( );
			l_create_info.enabledExtensionCount   = static_cast<std::uint32_t>( l_extension_strings.size( ) );
			l_create_info.ppEnabledExtensionNames = l_extension_strings.data( );

			VkInstance l_instance{};

			DE__VK__ERROR__CHECK_RESULT( vkCreateInstance( &l_create_info, nullptr, &l_instance ) );

			m_instance = l_instance;

			DE__VK__FUNCTION_LOAD( vkDestroyInstance, get_function_address );
		}

		/* thread_local makes access thread safe. */
		static thread_local de::util::cstring_array<1024> s_debug_report_callback_buffer;

		static VkBool32 debug_report_callback( [[maybe_unused]] VkDebugReportFlagsEXT flags, [[maybe_unused]] VkDebugReportObjectTypeEXT objectType, [[maybe_unused]] uint64_t object, [[maybe_unused]] size_t location, [[maybe_unused]] int32_t messageCode, [[maybe_unused]] const char* pLayerPrefix, [[maybe_unused]] const char* pMessage, [[maybe_unused]] void* pUserData )
		{
			s_debug_report_callback_buffer.reset( );

			// TODO: Implement and test this function.
			std::cerr << pMessage << std::endl;

			return true;
		}

		void instance::create_debug_report( )
		{
			if ( std::find( std::begin( m_configuration.extension_names ), std::end( m_configuration.extension_names ), std::string( "VK_EXT_debug_report" ) ) != std::end( m_configuration.extension_names ) )
			{
				DE__VK__FUNCTION_LOAD( vkCreateDebugReportCallbackEXT, get_function_address );

				VkDebugReportCallbackCreateInfoEXT l_create_info{};
				l_create_info.sType       = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
				l_create_info.flags       = ( VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_ERROR_BIT_EXT );
				l_create_info.pfnCallback = debug_report_callback;
				l_create_info.pUserData   = this;

				VkDebugReportCallbackEXT l_callback = nullptr;

				DE__VK__ERROR__CHECK_RESULT( vkCreateDebugReportCallbackEXT( m_instance, &l_create_info, nullptr, &l_callback ) );

				DE__VK__FUNCTION_LOAD( vkDestroyDebugReportCallbackEXT, get_function_address );

				DE__LOG__INFO( "Layer [VK_EXT_debug_report] enabled." << std::endl );
			}
		}

		/* thread_local makes access thread safe. */
		static thread_local de::util::cstring_array<1024> s_debug_messenger_callback_buffer;

		static VkBool32 debug_messenger_callback( [[maybe_unused]] VkDebugUtilsMessageSeverityFlagBitsEXT p_messageSeverity, [[maybe_unused]] VkDebugUtilsMessageTypeFlagsEXT p_messageTypes, [[maybe_unused]] const VkDebugUtilsMessengerCallbackDataEXT* p_pCallbackData, [[maybe_unused]] void* p_pUserData )
		{
			s_debug_messenger_callback_buffer.reset( );

// TODO: Implement and test this function.
#if 0
			if ( p_messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT )
			{
				DE__LOG__INFO( static_cast<const char *>( s_debug_messenger_callback_buffer ) << std::endl );
			}
			else if ( p_messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT )
			{
				DE__LOG__WARNING( static_cast<const char *>( s_debug_messenger_callback_buffer ) << std::endl );
			}
			else if ( p_messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT )
			{
				DE__LOG__EXCEPTION( static_cast<const char *>( s_debug_messenger_callback_buffer ) << std::endl );
			}
			else
			{
				DE__LOG__EXCEPTION( static_cast<const char *>( s_debug_messenger_callback_buffer ) << std::endl );
			}
#endif

			return true;
		}

		void instance::create_debug_messenger( )
		{
			if ( std::find( std::begin( m_configuration.extension_names ), std::end( m_configuration.extension_names ), std::string( "VK_EXT_debug_utils" ) ) != std::end( m_configuration.extension_names ) )
			{
				DE__VK__FUNCTION_LOAD( vkCreateDebugUtilsMessengerEXT, get_function_address );

				VkDebugUtilsMessengerCreateInfoEXT l_create_info{};
				l_create_info.sType           = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
				l_create_info.messageSeverity = ( VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT );
				l_create_info.messageType     = ( VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT );
				l_create_info.pfnUserCallback = debug_messenger_callback;
				l_create_info.pUserData       = this;

				VkDebugUtilsMessengerEXT l_messenger = nullptr;

				DE__VK__ERROR__CHECK_RESULT( vkCreateDebugUtilsMessengerEXT( m_instance, &l_create_info, nullptr, &l_messenger ) );

				DE__VK__FUNCTION_LOAD( vkDestroyDebugUtilsMessengerEXT, get_function_address );

				DE__LOG__INFO( "Layer [VK_EXT_debug_utils] enabled." << std::endl );
			}
		}

		void instance::enumerate_physical_devices( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumeratePhysicalDevices, get_function_address );

			std::uint32_t                 l_device_count = 0u;
			std::vector<VkPhysicalDevice> l_devices;
			DE__VK__ERROR__CHECK_RESULT( vkEnumeratePhysicalDevices( m_instance, &l_device_count, nullptr ) );
			l_devices.resize( l_device_count );
			DE__VK__ERROR__CHECK_RESULT( vkEnumeratePhysicalDevices( m_instance, &l_device_count, l_devices.data( ) ) );

			for ( auto device : l_devices )
			{
				physical_device l_physical_device{};

				l_physical_device.handle = device;

				m_physical_devices.push_back( l_physical_device );
			}
		}

		void instance::get_physical_device_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkGetPhysicalDeviceProperties, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				VkPhysicalDeviceProperties l_device_properties{};
				DE__VK__FUNCTION_CALL( vkGetPhysicalDeviceProperties( m_physical_devices[ i ].handle, &l_device_properties ) );

				m_physical_devices[ i ].name           = l_device_properties.deviceName;
				m_physical_devices[ i ].api_version    = l_device_properties.apiVersion;
				m_physical_devices[ i ].driver_version = l_device_properties.driverVersion;
			}
		}

		void instance::get_physical_device_features( )
		{
			DE__VK__FUNCTION_LOAD( vkGetPhysicalDeviceFeatures, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				VkPhysicalDeviceFeatures l_device_features{};
				DE__VK__FUNCTION_CALL( vkGetPhysicalDeviceFeatures( m_physical_devices[ i ].handle, &l_device_features ) );
			}
		}

		void instance::get_physical_device_memory_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkGetPhysicalDeviceMemoryProperties, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				VkPhysicalDeviceMemoryProperties l_device_memory_properties{};
				DE__VK__FUNCTION_CALL( vkGetPhysicalDeviceMemoryProperties( m_physical_devices[ i ].handle, &l_device_memory_properties ) );

				/* Process memory heaps. */

				m_physical_devices[ i ].memory_heaps.resize( l_device_memory_properties.memoryHeapCount );

				for ( auto j = 0u; j < l_device_memory_properties.memoryHeapCount; ++j )
				{
					m_physical_devices[ i ].memory_heaps[ j ].size           = l_device_memory_properties.memoryHeaps[ j ].size;
					m_physical_devices[ i ].memory_heaps[ j ].device_local   = ( ( VK_MEMORY_HEAP_DEVICE_LOCAL_BIT & l_device_memory_properties.memoryHeaps[ j ].flags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ j ].multi_instance = ( ( VK_MEMORY_HEAP_MULTI_INSTANCE_BIT & l_device_memory_properties.memoryHeaps[ j ].flags ) != 0 );
				}

				/* Process memory types. */

				for ( auto j = 0u; j < l_device_memory_properties.memoryTypeCount; ++j )
				{
					auto heap_index = l_device_memory_properties.memoryTypes[ j ].heapIndex;

					m_physical_devices[ i ].memory_heaps[ heap_index ].type.device_coherent  = ( ( VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.device_local     = ( ( VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.device_uncached  = ( ( VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.host_cached      = ( ( VK_MEMORY_PROPERTY_HOST_CACHED_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.host_coherent    = ( ( VK_MEMORY_PROPERTY_HOST_COHERENT_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.host_visible     = ( ( VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.lazily_allocated = ( ( VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
					m_physical_devices[ i ].memory_heaps[ heap_index ].type.protected_memory = ( ( VK_MEMORY_PROPERTY_PROTECTED_BIT & l_device_memory_properties.memoryTypes[ j ].propertyFlags ) != 0 );
				}
			}
		}

		void instance::get_physical_device_queue_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkGetPhysicalDeviceQueueFamilyProperties, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				std::uint32_t                        l_device_queue_families_count = 0;
				std::vector<VkQueueFamilyProperties> l_device_queue_families;
				DE__VK__FUNCTION_CALL( vkGetPhysicalDeviceQueueFamilyProperties( m_physical_devices[ i ].handle, &l_device_queue_families_count, nullptr ) );
				l_device_queue_families.resize( l_device_queue_families_count );
				DE__VK__FUNCTION_CALL( vkGetPhysicalDeviceQueueFamilyProperties( m_physical_devices[ i ].handle, &l_device_queue_families_count, l_device_queue_families.data( ) ) );

				/* Process queue families. */

				for ( auto queue : l_device_queue_families )
				{
					queue_family l_queue_family{};

					l_queue_family.count = queue.queueCount;

					l_queue_family.compute          = ( ( VK_QUEUE_COMPUTE_BIT & queue.queueFlags ) != 0 );
					l_queue_family.graphics         = ( ( VK_QUEUE_GRAPHICS_BIT & queue.queueFlags ) != 0 );
					l_queue_family.protected_memory = ( ( VK_QUEUE_PROTECTED_BIT & queue.queueFlags ) != 0 );
					l_queue_family.sparse_binding   = ( ( VK_QUEUE_SPARSE_BINDING_BIT & queue.queueFlags ) != 0 );
					l_queue_family.transfer         = ( ( VK_QUEUE_TRANSFER_BIT & queue.queueFlags ) != 0 );

					m_physical_devices[ i ].queue_families.push_back( l_queue_family );
				}
			}
		}

		void instance::enumerate_physical_device_layer_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumerateDeviceLayerProperties, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				std::uint32_t                  l_layer_count = 0u;
				std::vector<VkLayerProperties> l_layer_properties;
				DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceLayerProperties( m_physical_devices[ i ].handle, &l_layer_count, nullptr ) );
				l_layer_properties.resize( l_layer_count );
				DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceLayerProperties( m_physical_devices[ i ].handle, &l_layer_count, l_layer_properties.data( ) ) );

				for ( auto layer_property : l_layer_properties )
				{
					layer l_layer{};

					l_layer.name                   = layer_property.layerName;
					l_layer.spec_version           = layer_property.specVersion;
					l_layer.implementation_version = layer_property.implementationVersion;
					l_layer.description            = layer_property.description;

					m_physical_devices[ i ].layers.push_back( l_layer );
				}
			}
		}

		void instance::enumerate_physical_device_extension_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumerateDeviceExtensionProperties, get_function_address );

			for ( auto i = 0; i < m_physical_devices.size( ); ++i )
			{
				/* Global extensions. */

				{
					std::uint32_t                      l_extension_count = 0u;
					std::vector<VkExtensionProperties> l_extension_properties;
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceExtensionProperties( m_physical_devices[ i ].handle, nullptr, &l_extension_count, nullptr ) );
					l_extension_properties.resize( l_extension_count );
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceExtensionProperties( m_physical_devices[ i ].handle, nullptr, &l_extension_count, l_extension_properties.data( ) ) );

					for ( auto extension_property : l_extension_properties )
					{
						extension l_extension{};

						l_extension.name         = extension_property.extensionName;
						l_extension.spec_version = extension_property.specVersion;

						m_physical_devices[ i ].extensions.push_back( l_extension );
					}
				}

				/* Layer specific extensions. */

				for ( auto j = 0; j < m_physical_devices[ i ].layers.size( ); ++j )
				{
					std::uint32_t                      l_extension_count = 0u;
					std::vector<VkExtensionProperties> l_extension_properties;
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceExtensionProperties( m_physical_devices[ i ].handle, m_physical_devices[ i ].layers[ j ].name.c_str( ), &l_extension_count, nullptr ) );
					l_extension_properties.resize( l_extension_count );
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateDeviceExtensionProperties( m_physical_devices[ i ].handle, m_physical_devices[ i ].layers[ j ].name.c_str( ), &l_extension_count, l_extension_properties.data( ) ) );

					for ( auto extension_property : l_extension_properties )
					{
						extension l_extension{};

						l_extension.name         = extension_property.extensionName;
						l_extension.spec_version = extension_property.specVersion;

						m_physical_devices[ i ].layers[ j ].extensions.push_back( l_extension );
					}
				}
			}
		}

		static void vk_instance_deleter( VkInstance p_instance )
		{
			DE__VK__FUNCTION_CALL( vkDestroyInstance( p_instance, nullptr ) );
		}

		instance::instance( const loader& p_loader, const de::vk::instance_configuration& p_configuration )
			: m_loader{ p_loader }
			, m_configuration{ p_configuration }
			, m_physical_devices{}
			, m_instance{ vk_instance_deleter, nullptr }
		{
			assert_layers_available( );

			assert_extensions_available( );

			create_instance( );

			create_debug_report( );

			create_debug_messenger( );

			enumerate_physical_devices( );

			get_physical_device_properties( );

			get_physical_device_features( );

			get_physical_device_memory_properties( );

			get_physical_device_queue_properties( );

			enumerate_physical_device_layer_properties( );

			enumerate_physical_device_extension_properties( );
		}

		/* */
		void* instance::get_function_address( const char* p_function_name ) const
		{
			DE__VK__ERROR__CHECK_AND_RETURN( void*, vkGetInstanceProcAddr( m_instance, p_function_name ), nullptr, p_function_name );
		}
	}
}

/* END */
