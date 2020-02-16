#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.handle.hpp>
#include <de.version.hpp>

#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace de
{
	namespace vk
	{
		struct device_configuration
		{
			void* handle{ nullptr };
		};

		class instance;

		class device
		{
			const instance& m_instance;

			const device_configuration& m_configuration;

			de::handle<VkDevice> m_device;

			void create_device( );

		public:
			device( ) = delete;

			device( const instance&, const device_configuration& );

			device( const device& ) = delete;

			~device( ) = default;

			device& operator=( const device& ) = delete;

			const device_configuration& configuration( ) const noexcept
			{
				return m_configuration;
			}

			void* get_function_address( const char* p_function_name );
		};
	}
}

/* END */
