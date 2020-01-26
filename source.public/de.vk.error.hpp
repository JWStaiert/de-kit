#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

enum VkResult : int;

#include "de.exception.hpp"

#define DE__VK__ERROR__CHECK_AND_THROW_RUNTIME_ERROR( expression ) { VkResult l_result = expression; DE__EXCEPTION__CHECK_AND_THROW_RUNTIME_ERROR( l_result != VK_SUCCESS , de::vk::error::format( l_result ) ); }

namespace de
{
	namespace vk
	{
		namespace error
		{
			const char * format( VkResult p_result );
		}
	}
}

/* END */
