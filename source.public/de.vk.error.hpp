#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

enum VkResult : int;

#include "de.exception.hpp"

#define DE__VK__ERROR__CHECK_RESULT( vk_function ) { VkResult vk_result = VK_SUCCESS; DE__EXCEPTION__CHECK_WITH_MESSAGE( ( vk_result = de::vk::_##vk_function ) != VK_SUCCESS , de::vk::error::format_result( vk_result ) ); }

#define DE__VK__ERROR__CHECK_AND_RETURN( vk_return_type , vk_function , vk_fail_rv , vk_parameter ) { vk_return_type vk_return_value = vk_fail_rv; DE__EXCEPTION__CHECK_WITH_MESSAGE( ( vk_return_value = de::vk::_##vk_function ) == vk_fail_rv , de::vk::error::format_parameter( #vk_parameter , vk_parameter ) ); return vk_return_value; }

namespace de
{
	namespace vk
	{
		namespace error
		{
			const char * format_result( VkResult p_result );

			const char * format_parameter( const char * p_parameter , const char * p_value );
		}
	}
}

/* END */
