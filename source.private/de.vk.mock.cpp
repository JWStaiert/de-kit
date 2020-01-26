/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

#ifdef _WINDOWS
#define DE_DLL_EXPORT _declspec( dllexport )
#endif

extern "C"
{
	DE_DLL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr( VkInstance /*instance*/ , const char* /*pName*/ )
	{
		return nullptr;
	}

	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties( uint32_t* /*pPropertyCount*/ , VkLayerProperties* /*pProperties*/ )
	{
		return VK_NOT_READY;
	}

	DE_DLL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties( const char* /*pLayerName*/ , uint32_t* /*pPropertyCount*/ , VkExtensionProperties* /*pProperties*/ )
	{
		return VK_NOT_READY;
	}
}
