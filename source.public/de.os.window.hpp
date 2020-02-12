#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.handle.hpp>

#include <de.math.vec2.hpp>

#include <string>
#include <vector>

#include <cstdint>

class de__os__window__test_fixture;

namespace std
{
	namespace filesystem
	{
		class path;
	}
}

namespace de
{
	namespace os
	{
		enum struct window_menu_type
		{
			command,
			checkbox,
			separator,
		};

		struct window_menu_item
		{
			const window_menu_type type{ window_menu_type::separator };
			const std::wstring     name{ L"" };
			const std::int32_t     id{ -1 };
		};

		struct window_menu
		{
			const std::wstring                          name;
			const std::vector<de::os::window_menu_item> items;
			const std::int32_t                          id{ -1 };
		};

		struct window_properties
		{
			const std::wstring                     name{ L"default application name" };
			const std::vector<de::os::window_menu> menus;
		};

		enum struct window_state
		{
			open,
			visible,
			visible_maximized,
			visible_minimized,
			closed,
		};

		using window_size = de::math::vec2<std::uint16_t>;

		struct window_event
		{
			enum event_type
			{
				command_type,
			};

			event_type type;

			std::int32_t id;
		};

		struct window_open_file_dialog
		{
			std::wstring filter;
			std::wstring filter_user;
		};

		struct window_save_file_dialog
		{
		};

		class window
		{
		private:
			friend class de__os__window__test_fixture;
			friend static void process_close_message( window* ) noexcept;
			friend static void process_resized_message( window*, window_state, std::uint16_t, std::uint16_t ) noexcept;
			friend static void process_show_message( window*, window_state ) noexcept;
			friend static void class_deleter( std::uint16_t p_class ) noexcept;

			de::handle<std::uint16_t> m_class;

			de::handle<void*> m_window;

			window_state m_state;

			window_size m_size;

			void initialize_diagnostics( );

			void create_class( void* );

			void create_window( void*, const window_properties& );

			void create_menu( const window_properties& );

			static const wchar_t* CLASS_NAME;

		public:
			//window( ) = delete;

			window( const window_properties& = {} );

			window( const window& ) = delete;

			window( window&& ) = delete;

			~window( ) noexcept = default;

			window& operator=( const window& ) = delete;

			window& operator=( window&& ) = delete;

			window_state state( ) const noexcept
			{
				return m_state;
			}

			window_size size( ) const noexcept
			{
				return m_size;
			}

			bool has_event( window_event& ) noexcept;

			void show( ) noexcept;

			void check_menu_item( const std::int32_t id );

			void uncheck_menu_item( const std::int32_t id );
		};
	}
}

/* END */
