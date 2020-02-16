/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include <de.app.hpp>
#include <de.version.hpp>

#include <de.os.window.hpp>

#include <de.vk.device.hpp>
#include <de.vk.instance.hpp>
#include <de.vk.loader.hpp>

#include <unit-test.de.hpp>    // JWS: Contains path to vulkan loader.

#include <stdexcept>

#if 0
TEST( de__vk__drawing, initialization_and_render_loop )
{
	try
	{
		/* Initialize application data. */
		de::app l_app{};
		l_app.name        = L"de::vk::drawing test";
		l_app.version     = de::version{ 1, 0, 0 };
		l_app.window_mode = de::window_mode::bordered;

		/* Initialize user interface. */

		/* Initialize Vulkan. */

		de::vk::loader l_loader{ DE_VULKAN_LOADER_MODULE_PATHNAME };

		const de::vk::instance_configuration l_instance_config{};

		de::vk::instance l_instance{ l_loader, l_instance_config };

		const de::vk::device_configuration l_device_config{};

		de::vk::device l_device{ l_instance, l_device_config };

		/* Initialize window. */

		de::os::window l_window{ };

		/* Loop until window should close. */

		while ( l_window.state( ) != de::os::window_state::closed )
		{
			de::os::window_size l_window_size = l_window.size( );

			/* Resize user interface. */

			/* Initialize surface. */

			/* Initialize swap-chain. */

			/* Initialize 2D pipeline. */

			/* Initialize 2D glyph pipeline. */

			/* Initialize 3D pipeline. */

			/* Initialize 3D glyph pipeline. */

			/* Initialize renderer. */

			/* Loop until window has changed or should close. */

			while ( l_window.size( ) == l_window_size )
			{
				/* Process available events. */

				de::os::window_event l_window_event;

				while ( l_window.has_event( l_window_event ) )
				{
					// Pick required. Query renderer.

					// Create UI event from pick result.

					// Pass event to UI.
				}

				/* Process geometry updates. */

				/* Render geometry. */
				// JWS: Command buffers have been properly assembled at this point, so this call ivokes the necessary
				// calls to process those buffers. The swapchain should be updated automatically. This method may block
				// if the CPU is too far ahead of the GPU.
			}
		}
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexcepted exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}
#endif

/* END */
