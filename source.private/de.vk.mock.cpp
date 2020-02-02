/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

#include <map>
#include <string>
#include <vector>

#include <cstring>

#ifdef _WINDOWS
#define DE_DLL_EXPORT _declspec( dllexport )
#endif

extern "C"
{
	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceVersion( uint32_t* pApiVersion )
	{
		if ( pApiVersion != nullptr )
		{
			*pApiVersion = VK_MAKE_VERSION( 5 , 50 , 500 );

			return VK_SUCCESS;
		}

		return VK_RESULT_MAX_ENUM;
	}

	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties( uint32_t* pPropertyCount , VkLayerProperties* pProperties )
	{
		static const std::vector<VkLayerProperties> s_layers {
			{ "LAYER_1" , VK_MAKE_VERSION( 1 , 10 , 100 ) , VK_MAKE_VERSION( 2 , 20 , 200 ) , "First unit test layer."   },
			{ "LAYER_2" , VK_MAKE_VERSION( 1 , 2  , 3   ) , VK_MAKE_VERSION( 2 , 4  , 6   ) , "Second unit test layer."  },
		};

		if ( pPropertyCount != nullptr )
		{
			if ( pProperties != nullptr )
			{
				if ( *pPropertyCount != s_layers.size( ) )
				{
					return VK_RESULT_MAX_ENUM;
				}
				else
				{
					for ( auto i = 0u ; i < *pPropertyCount ; ++i )
					{
						pProperties[ i ] = s_layers[ i ];
					}

					return VK_SUCCESS;
				}
			}
			else
			{
				*pPropertyCount = static_cast<uint32_t>( s_layers.size( ) );

				return VK_SUCCESS;
			}
		}

		return VK_RESULT_MAX_ENUM;
	}

	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties( const char* pLayerName , uint32_t* pPropertyCount , VkExtensionProperties* pProperties )
	{
		static const std::vector<VkExtensionProperties> s_global_extensions {
			{ "GLOBAL_EXTENSION_1" , VK_MAKE_VERSION( 1 , 2 , 3 ) } ,
			{ "GLOBAL_EXTENSION_2" , VK_MAKE_VERSION( 2 , 4 , 6 ) } ,
			{ "GLOBAL_EXTENSION_3" , VK_MAKE_VERSION( 3 , 6 , 9 ) } ,
		};

		static const std::vector<VkExtensionProperties> s_layer_1_extensions {
			{ "LAYER_1_EXTENSION_1" , VK_MAKE_VERSION( 4 , 8  , 12 ) } ,
			{ "LAYER_1_EXTENSION_2" , VK_MAKE_VERSION( 5 , 10 , 15 ) } ,
		};

		static const std::map< const std::string , const std::vector< VkExtensionProperties> > s_layer_extensions {
			{ "LAYER_1" , s_layer_1_extensions } ,
		};

		if ( pLayerName != nullptr )
		{
			if ( pPropertyCount != nullptr )
			{
				if ( pProperties != nullptr )
				{
					if ( *pPropertyCount != s_layer_extensions.at( pLayerName ).size( ) )
					{
						return VK_RESULT_MAX_ENUM;
					}
					else
					{
						for ( auto i = 0u ; i < *pPropertyCount ; ++i )
						{
							pProperties[ i ] = s_layer_extensions.at( pLayerName )[ i ];
						}

						return VK_SUCCESS;
					}
				}
				else
				{
					if ( s_layer_extensions.count( std::string( pLayerName ) ) != 0 )
					{
						*pPropertyCount = static_cast<uint32_t>( s_layer_extensions.at( pLayerName ).size( ) );

						return VK_SUCCESS;
					}
					else
					{
						*pPropertyCount = 0;

						return VK_SUCCESS;
					}
				}
			}
		}
		else
		{
			if ( pPropertyCount != nullptr )
			{
				if ( pProperties != nullptr )
				{
					if ( *pPropertyCount != s_global_extensions.size( ) )
					{
						return VK_RESULT_MAX_ENUM;
					}
					else
					{
						for ( auto i = 0u ; i < *pPropertyCount ; ++i )
						{
							pProperties[ i ] = s_global_extensions[ i ];
						}

						return VK_SUCCESS;
					}
				}
				else
				{
					*pPropertyCount = static_cast<uint32_t>( s_global_extensions.size( ) );

					return VK_SUCCESS;
				}
			}
		}

		return VK_RESULT_MAX_ENUM;
	}

	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
		const VkInstanceCreateInfo*                 /*pCreateInfo*/ ,
		const VkAllocationCallbacks*                /*pAllocator*/ ,
		VkInstance*                                 /*pInstance*/
	)
	{
		return VK_RESULT_MAX_ENUM;
	}

	DE_DLL_EXPORT VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(
		VkInstance                                  /*instance*/ ,
		const VkAllocationCallbacks*                /*pAllocator*/
	)
	{
	}

	DE_DLL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr( VkInstance /*instance*/ , const char* pName )
	{
		if ( std::strcmp( pName , "vkEnumerateInstanceVersion" ) == 0 )
		{
			return (PFN_vkVoidFunction) vkEnumerateInstanceVersion;
		}
		else if ( std::strcmp( pName , "vkEnumerateInstanceLayerProperties" ) == 0 )
		{
			return (PFN_vkVoidFunction) vkEnumerateInstanceLayerProperties;
		}
		else if ( std::strcmp( pName , "vkEnumerateInstanceExtensionProperties" ) == 0 )
		{
			return (PFN_vkVoidFunction) vkEnumerateInstanceExtensionProperties;
		}
		else if ( std::strcmp( pName , "vkCreateInstance" ) == 0 )
		{
			return (PFN_vkVoidFunction) vkCreateInstance;
		}
		else
		{
			return nullptr;
		}
	}
}
