#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

enum VkResult : int;

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
