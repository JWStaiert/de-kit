#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.handle.hpp"

#include "de.math.vec2.hpp"

#include <cstdint>

namespace de
{
	struct app;

	namespace os
	{
		enum struct window_state
		{
			open ,
			visible ,
			visible_maximized ,
			visible_minimized ,
			closed ,
		};

		using window_size = de::math::vec2<std::uint16_t>;

		class window
		{
		private:

			friend void process_close_message( window * ) noexcept;
			friend void process_resized_message( window * , window_state , std::uint16_t , std::uint16_t ) noexcept;

			de::handle< std::uint16_t > m_class;

			de::handle< void * > m_handle;

			window_state m_state;

			window_size m_size;

		public:

			window( ) = delete;

			window( const app & , bool = false );

			window( const window & ) = delete;

			~window( ) noexcept = default;

			window & operator=( const window & ) = delete;

			window_state state( ) const noexcept { return m_state; }

			window_size size( ) const noexcept { return m_size; }

			bool has_event( ) noexcept;

			void show( ) noexcept;
		};
	}
}

/* END */
