/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.app.hpp"
#include "de.os.window.hpp"
#include "de.ui.button.glyph.hpp"
#include "de.ui.button.label.hpp"
#include "de.ui.dialog.modal.hpp"
#include "de.ui.manager.hpp"
#include "de.ui.page.hpp"
#include "de.ui.text.edit.hpp"
#include "de.ui.text.label.hpp"
#include "de.ui.view.model.hpp"
#include "de.version.hpp"

#include "de.vk.device.hpp"
#include "de.vk.loader.hpp"
#include "de.vk.instance.hpp"
#include "de.vk.pipeline2D.hpp"
#include "de.vk.pipeline2Dglyph.hpp"
#include "de.vk.pipeline3D.hpp"
#include "de.vk.pipeline3Dglyph.hpp"
#include "de.vk.renderer.hpp"
#include "de.vk.surface.hpp"
#include "de.vk.swapchain.hpp"

#include "de.unit-test.hpp" // JWS: Contains path to vulkan loader.

#include <stdexcept>

TEST( de__vk__drawing , initialization_and_render_loop )
{
	try
	{
		/* Initialize application data. */
		de::app l_app { };
		l_app.name        = "de::vk::drawing test";
		l_app.version     = de::version { 1 , 0 , 0 };
		l_app.window_mode = de::window_mode::bordered;

		/* Initialize user interface. */

		de::ui::button::glyph l_glyph_button { };
		de::ui::button::label l_label_button { };
		de::ui::dialog::modal l_modal_dialog { };
		de::ui::text::edit  l_edit_text { };
		de::ui::text::label l_label_text { };
		de::ui::view::model l_model_view { };

		de::ui::page l_page { &l_glyph_button , &l_label_button , &l_modal_dialog , &l_edit_text , &l_label_text , &l_model_view };

		de::ui::manager l_ui_manager { &l_page };

		/* Initialize Vulkan. */

		de::vk::loader l_loader { DE_VULKAN_LOADER_MODULE_PATHNAME };

		const de::vk::instance_configuration l_instance_config { };

		de::vk::instance l_instance { l_loader , l_instance_config };

		const de::vk::device_configuration l_device_config { };

		de::vk::device l_device { l_instance, l_device_config };

		/* Initialize window. */

		de::os::window l_window { l_app };

		/* Loop until window should close. */

		while ( !l_window.should_close( ) )
		{
			/* Resize user interface. */

			l_ui_manager.resize( l_window.size( ) );

			/* Initialize surface. */

			de::vk::surface l_surface { l_device };

			/* Initialize swap-chain. */

			de::vk::swapchain l_swapchain { l_device , l_surface };

			/* Initialize 2D pipeline. */
			// JWS: This is a pipeline designed specifically to efficiently render geometry2D content.

			de::vk::pipeline2D l_pipeline2D { l_device };

			/* Initialize 2D glyph pipeline. */
			// JWS: This is a pipeline designed specifically to efficiently render geometry2Dglyph content.

			de::vk::pipeline2Dglyph l_pipeline2Dglyph { l_device };

			/* Initialize 3D pipeline. */
			// JWS: This is a pipeline designed specifically to efficiently render geometry3D content.

			de::vk::pipeline3D l_pipeline3D { l_device };

			/* Initialize 3D glyph pipeline. */
			// JWS: This is a pipeline designed specifically to efficiently render geometry3Dglyph content.

			de::vk::pipeline3Dglyph l_pipeline3Dglyph { l_device };

			/* Initialize renderer. */
			// JWS: Order of rendering:
			// JWS: Stage 1: 3D geometry with depth testing.
			// JWS: Stage 2: 3D glyph geometry alpha blended and depth tested. (signed distance field)
			// JWS: Stage 3: 2D geometry no depth testing but alpha blended. geometry is pre-sorted.
			// JWS: Stage 4: 2D glyph geometry no depth testing but alpha blended. geometry is pre-sorted.
			// JWS: Option Stage 5: sets 2D geometry and 2D glyph geometry in single render order list
			// allowing proper rendering of overlapping geometry with different z-orders.

			de::vk::renderer l_renderer { l_device , l_surface , l_swapchain , l_pipeline2D , l_pipeline2Dglyph , l_pipeline3D , l_pipeline3Dglyph };

			/* Loop until window has changed or should close. */

			while ( !l_window.has_changed( ) )
			{
				/* Process available events. */

				de::os::event l_event;

				while ( l_window.has_events( l_event ) )
				{
					// Pick required. Query renderer.
					de::pick l_pick = l_renderer.query( x , y );
					// Update event with pick result.
					l_event.set_pick( l_pick );
					// Pass pick to UI.
					l_ui_manager.process_event( l_event );
				}

				/* Process user input events. */
				// JWS: Option 1: Pass const reference to events owned by window. (improved memory and cpu efficiency)
				// JWS: Option 2: Pass local copy of events. (allows for inline inserting, sorting, and filtering on events)
				// JWS: Option 3: Pass reference to events owned by window. (improved memory and cpu efficiency and allows
				// inline inserting, sorting, and filtering, but potentially breaks window interface)
				// JWS: Inserting, sorting, and filtering seems like a useful ability, especially for testing.
				// JWS: A dynamic allocation every frame is required by Option 2, and since there is not fixed upper limit
				// on how large the event vector may be (as many messages as can be pushed into the application from OS
				// during one frame.)
				// JWS: Option 1 and 3 may require a dynamic allocation during a render cycle if the current cycles event
				// count exceeds that of previous cycles.
				l_ui_manager.process_events( l_window.events( ) );

				/* Process geometry updates. */
				// JWS: Option 1: Pass const reference to updates owned by geometry*. (improved memory and cpu efficiency)
				// JWS: Option 2: Pass local copy of updates. (allows for inline inserting, sorting, and filtering on events)
				// JWS: Option 3: Pass reference to update owned by geometry*. (improved memory and cpu efficiency and allows
				// inline inserting, sorting, and filtering, but potentially breaks geometry* interface)
				// JWS: Unsure when inserting, sorting, and filtering might be useful in this context.
				// JWS: A dynamic allocation every frame is required by Option 2, but the maximum size is fixed at the size
				// of half the geometry buffer (worst-case is every other element in buffer has changed since contiguous
				// elements are merged into a single update record.)
				// JWS: Option 1 and 3 can be implemented so a dynamic allocation is never required during a render cycle since
				// the update buffer max size is fixed at half the geometry buffer (see previous note for why this is.)
				// JWS: These calls may be replaced by a single geometry buffer allowing sets of 2D geometry and 2D glyph
				// to be mixed in the rendering order.
				// JWS: These calls could be handled in other threads.
				l_renderer.process_geometry2D_updates( l_ui_manager.geometry2D_updates( ) );
				l_renderer.process_geometry2Dglyph_updates( l_ui_manager.geometry2Dglyph_updates( ) );
				l_renderer.process_geometry3D_updates( l_ui_manager.geometry3D_updates( ) );
				l_renderer.process_geometry3Dglyph_updates( l_ui_manager.geometry3Dglyph_updates( ) );

				/* Render geometry. */
				// JWS: Command buffers have been properly assembled at this point, so this call ivokes the necessary
				// calls to process those buffers. The swapchain should be updated automatically. This method may block
				// if the CPU is too far ahead of the GPU.
				l_renderer.render( );
			}
		}
	}
	catch ( const std::exception & exc )
	{
		FAIL( ) << "Unexcepted exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

/* END */
