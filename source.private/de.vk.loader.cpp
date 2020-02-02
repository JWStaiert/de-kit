/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.vk.loader.hpp"
#include "de.vk.error.hpp"
#include "de.vk.util.hpp"

#include "de.exception.hpp"
#include "de.util.hpp"

#include "de.os.module.hpp"

#include <algorithm>
#include <sstream>

#include <vulkan/vulkan.h>

namespace de
{
	namespace vk
	{
		DE__VK__FUNCTION( vkGetInstanceProcAddr );

		DE__VK__FUNCTION( vkEnumerateInstanceVersion );

		DE__VK__FUNCTION( vkEnumerateInstanceLayerProperties );

		DE__VK__FUNCTION( vkEnumerateInstanceExtensionProperties );

		/* */
		void loader::enumerate_api_version( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumerateInstanceVersion , get_function_address );

			std::uint32_t l_api_version = 0;

			DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceVersion( &l_api_version ) );

			m_api_version = l_api_version;
		}

		/* */
		void loader::enumerate_layer_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumerateInstanceLayerProperties , get_function_address );

			std::uint32_t l_layers_count = 0u;
			std::vector<VkLayerProperties> l_layers_properties;

			DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceLayerProperties( &l_layers_count , nullptr ) );

			l_layers_properties.resize( l_layers_count );

			DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceLayerProperties( &l_layers_count , &l_layers_properties[ 0 ] ) );

			m_layers.resize( l_layers_count );

			for ( auto i = 0u ; i < l_layers_count ; ++i )
			{
				m_layers[ i ].name = l_layers_properties[ i ].layerName;

				m_layers[ i ].spec_version = l_layers_properties[ i ].specVersion;

				m_layers[ i ].implementation_version = l_layers_properties[ i ].implementationVersion;

				m_layers[ i ].description = l_layers_properties[ i ].description;
			}
		}

		/* */
		void loader::enumerate_extension_properties( )
		{
			DE__VK__FUNCTION_LOAD( vkEnumerateInstanceExtensionProperties , get_function_address );

			/* Enumerate global extensions. */
			{
				std::uint32_t l_extension_count = 0u;
				std::vector<VkExtensionProperties> l_extension_properties;

				DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceExtensionProperties( nullptr , &l_extension_count , nullptr ) );

				l_extension_properties.resize( l_extension_count );

				if ( l_extension_count > 0 )
				{
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceExtensionProperties( nullptr , &l_extension_count , l_extension_properties.data( ) ) );

					m_extensions.resize( l_extension_count );

					for ( auto i = 0u ; i < l_extension_count ; ++i )
					{
						m_extensions[ i ].name = l_extension_properties[ i ].extensionName;

						m_extensions[ i ].spec_version = l_extension_properties[ i ].specVersion;
					}
				}
			}

			/* Enumerate layer extensions. */
			for ( auto i = 0u ; i < m_layers.size( ) ; ++i )
			{
				std::uint32_t l_extension_count = 0u;
				std::vector<VkExtensionProperties> l_extension_properties;

				DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceExtensionProperties( m_layers[ i ].name.c_str( ) , &l_extension_count , nullptr ) );

				l_extension_properties.resize( l_extension_count );

				if ( l_extension_count > 0 )
				{
					DE__VK__ERROR__CHECK_RESULT( vkEnumerateInstanceExtensionProperties( m_layers[ 0 ].name.c_str( ) , &l_extension_count , l_extension_properties.data( ) ) );

					m_layers[ i ].extensions.resize( l_extension_count );

					for ( auto j = 0u ; j < l_extension_count ; ++j )
					{
						m_layers[ i ].extensions[ j ].name = l_extension_properties[ j ].extensionName;

						m_layers[ i ].extensions[ j ].spec_version = l_extension_properties[ j ].specVersion;
					}
				}
			}
		}

		/* */
		loader::loader( const std::string & p_loader_dll_path )
			: m_module                 { p_loader_dll_path }
			, m_api_version            { 0 }
			, m_layers                 { }
			, m_extensions             { }
		{
			DE__VK__FUNCTION_LOAD( vkGetInstanceProcAddr , m_module.get_function_address );

			enumerate_api_version( );

			enumerate_layer_properties( );

			enumerate_extension_properties( );
		}

		/* */
		void * loader::get_function_address( const char * p_function_name ) const
		{
			DE__VK__ERROR__CHECK_AND_RETURN( void * , vkGetInstanceProcAddr( nullptr , p_function_name ) , nullptr , p_function_name );
		}
	}
}

/* END */
