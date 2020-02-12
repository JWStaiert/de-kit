/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.window.hpp"

#include <de.app.hpp>
#include <de.log.hpp>

#include <de.os.error.hpp>

#include <string>

#include <Windows.h>

#ifndef UNICODE
#	error "This module expects UNICODE to be defined. In Visual Studio 2017 the Character Set option must be 'Use Unicode Character Set'."
#endif

namespace de
{
	namespace os
	{
		const wchar_t* window::CLASS_NAME = L"de::os::window";

		static void process_close_message( window* p_window_ptr ) noexcept
		{
			p_window_ptr->m_state = de::os::window_state::closed;
		}

		static void process_resized_message( window* p_window_ptr, window_state p_state, std::uint16_t p_width, std::uint16_t p_height ) noexcept
		{
			if ( p_window_ptr->m_state != window_state::open )
			{
				p_window_ptr->m_state = p_state;
				p_window_ptr->m_size  = window_size{ p_width, p_height };
			}
		}

		static void process_show_message( window* p_window_ptr, window_state p_state ) noexcept
		{
			p_window_ptr->m_state = p_state;
		}

		static LRESULT CALLBACK wind_proc( HWND p_wnd, UINT p_msg, WPARAM p_wparam, LPARAM p_lparam )
		{
			de::os::window* l_window_ptr = reinterpret_cast<de::os::window*>( GetWindowLongPtrW( p_wnd, GWLP_USERDATA ) );

			LRESULT l_rv = 0;

			switch ( p_msg )
			{
			case WM_SIZE:
				switch ( p_wparam )
				{
				case SIZE_RESTORED:
					process_resized_message( l_window_ptr, window_state::visible, LOWORD( p_lparam ), HIWORD( p_lparam ) );
					break;
				case SIZE_MAXIMIZED:
					process_resized_message( l_window_ptr, window_state::visible_maximized, LOWORD( p_lparam ), HIWORD( p_lparam ) );
					break;
				case SIZE_MINIMIZED:
					process_resized_message( l_window_ptr, window_state::visible_minimized, LOWORD( p_lparam ), HIWORD( p_lparam ) );
					break;
				default:
					l_rv = DefWindowProcW( p_wnd, p_msg, p_wparam, p_lparam );
					break;
				}
				break;
			case WM_SHOWWINDOW:
				process_show_message( l_window_ptr, ( ( p_wparam == TRUE ) ? window_state::visible : window_state::open ) );
				break;
			case WM_CLOSE:
				process_close_message( l_window_ptr );
				break;
			default:
				l_rv = DefWindowProcW( p_wnd, p_msg, p_wparam, p_lparam );
				break;
			}

			return l_rv;
		}

		void window::initialize_diagnostics( )
		{
			_CrtSetDbgFlag( ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_LEAK_CHECK_DF ) );
		}

		static void class_deleter( std::uint16_t p_class ) noexcept
		{
			if ( p_class != 0 )
			{
				DE__OS__ERROR__LOG( UnregisterClassW( de::os::window::CLASS_NAME, NULL ) != TRUE );
			}
		}

		void window::create_class( void* p_hinstance )
		{
			WNDCLASSW l_window_class{};
			l_window_class.style         = ( CS_DBLCLKS | CS_OWNDC );
			l_window_class.lpfnWndProc   = wind_proc;
			l_window_class.hInstance     = static_cast<HINSTANCE>( p_hinstance );
			l_window_class.lpszClassName = CLASS_NAME;

			DE__OS__ERROR__CHECK( ( m_class = RegisterClassW( &l_window_class ) ) == 0 );
		}

		static void window_deleter( void* p_hwnd ) noexcept
		{
			if ( p_hwnd != nullptr )
			{
				DE__OS__ERROR__LOG( DestroyWindow( static_cast<HWND>( p_hwnd ) ) != TRUE );
			}
		}

		void window::create_window( void* p_hinstance, const window_properties& p_properties )
		{
			HWND l_window = CreateWindowExW( ( false ? WS_EX_TOPMOST : 0 ), CLASS_NAME, p_properties.name.c_str( ), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, static_cast<HINSTANCE>( p_hinstance ), NULL );

			DE__OS__ERROR__CHECK( l_window == NULL );

			m_window = l_window;

			DE__OS__ERROR__CHECK( SetWindowLongPtrW( static_cast<HWND>( m_window.value( ) ), GWLP_USERDATA, reinterpret_cast<LONG_PTR>( this ) ) != 0 );    // JWS: The previous value should always be zero after window creation so this function always succeeds.
		}

		static void menu_deleter( HMENU p_menu ) noexcept    // JWS: Not necessary once assigned to window.
		{
			if ( p_menu != nullptr )
			{
				DE__OS__ERROR__LOG( DestroyMenu( p_menu ) != TRUE );
			}
		}

		void window::create_menu( const window_properties& p_properties )
		{
			if ( p_properties.menus.size( ) != 0 )
			{
				de::handle<HMENU> l_menu{ menu_deleter, NULL };

				DE__OS__ERROR__CHECK( ( l_menu = CreateMenu( ) ) == NULL );

				for ( auto menu = std::rbegin( p_properties.menus ); menu != std::rend( p_properties.menus ); ++menu )
				{
					if ( ( *menu ).items.size( ) != 0 )
					{
						// Adding a popup menu.

						de::handle<HMENU> l_popup{ menu_deleter, NULL };

						DE__OS__ERROR__CHECK( ( l_popup = CreatePopupMenu( ) ) == NULL );

						for ( auto item = std::rbegin( ( *menu ).items ); item != std::rend( ( *menu ).items ); ++item )
						{
							switch ( ( *item ).type )
							{
							case de::os::window_menu_type::separator:
							{
								MENUITEMINFOW l_item_info{};
								l_item_info.cbSize = sizeof( MENUITEMINFOW );
								l_item_info.fMask  = MIIM_TYPE;
								l_item_info.fType  = MFT_SEPARATOR;

								DE__OS__ERROR__CHECK( InsertMenuItemW( l_popup, 0, TRUE, &l_item_info ) == FALSE );
							}
							break;

							case de::os::window_menu_type::checkbox:
							{
								MENUITEMINFOW l_item_info{};
								l_item_info.cbSize     = sizeof( MENUITEMINFOW );
								l_item_info.fMask      = ( MIIM_FTYPE | MIIM_STATE | MIIM_STRING | MIIM_ID );
								l_item_info.fType      = MFT_RADIOCHECK;
								l_item_info.fState     = MFS_UNCHECKED;
								l_item_info.dwTypeData = const_cast<wchar_t*>( ( *item ).name.c_str( ) );
								l_item_info.wID        = ( *item ).id;

								DE__OS__ERROR__CHECK( InsertMenuItemW( l_popup, 0, TRUE, &l_item_info ) == FALSE );
							}
							break;

							case de::os::window_menu_type::command:
							{
								MENUITEMINFOW l_item_info{};
								l_item_info.cbSize     = sizeof( MENUITEMINFOW );
								l_item_info.fMask      = ( MIIM_FTYPE | MIIM_STRING | MIIM_ID );
								l_item_info.fType      = MFT_STRING;
								l_item_info.dwTypeData = const_cast<wchar_t*>( ( *item ).name.c_str( ) );
								l_item_info.wID        = ( *item ).id;

								DE__OS__ERROR__CHECK( InsertMenuItemW( l_popup, 0, TRUE, &l_item_info ) == FALSE );
							}
							break;

							default:

								break;
							}
						}

						MENUITEMINFOW l_menu_info{};
						l_menu_info.cbSize     = sizeof( MENUITEMINFOW );
						l_menu_info.fMask      = ( MIIM_STRING | MIIM_SUBMENU );
						l_menu_info.dwTypeData = const_cast<wchar_t*>( ( *menu ).name.c_str( ) );
						l_menu_info.hSubMenu   = l_popup;

						DE__OS__ERROR__CHECK( InsertMenuItemW( l_menu, 0, TRUE, &l_menu_info ) == FALSE );

						// JWS: Now that the popup pointed to by l_popup has been assigned to the menu we can clear l_popup.
						l_popup = NULL;
					}
					else
					{
						// Adding a menu item.

						MENUITEMINFOW l_menu_item{};
						l_menu_item.cbSize     = sizeof( MENUITEMINFOW );
						l_menu_item.fMask      = ( MIIM_STRING | MIIM_ID );
						l_menu_item.dwTypeData = const_cast<wchar_t*>( ( *menu ).name.c_str( ) );
						l_menu_item.wID        = ( *menu ).id;

						DE__OS__ERROR__CHECK( InsertMenuItemW( l_menu, 0, TRUE, &l_menu_item ) == FALSE );
					}
				}

				// JWS: Add menu to the window. If SetMenu succeeds the window object will be responsible for deleting the menu.
				// JWS: During testing I found that if the menu was added to the window before the items were added to the menu
				// then the menu items would not be selectable when the window is made visible until after the window was
				// minimized and the made visible again.
				DE__OS__ERROR__CHECK( SetMenu( static_cast<HWND>( m_window.value( ) ), l_menu ) == FALSE );

				// JWS: We can no clear l_menu.
				l_menu = NULL;
			}
		}

		window::window( const window_properties& p_properties )
			: m_class{ class_deleter, 0u }
			, m_window{ window_deleter, nullptr }
			, m_state{ window_state::open }
			, m_size{}
		{
			HMODULE l_hinstance = GetModuleHandleW( NULL );

			initialize_diagnostics( );

			create_class( l_hinstance );

			create_window( l_hinstance, p_properties );

			create_menu( p_properties );
		}

		bool window::has_event( window_event& p_event ) noexcept
		{
			MSG l_msg{};

			if ( PeekMessageW( &l_msg, static_cast<HWND>( m_window.value( ) ), 0, 0, PM_REMOVE ) )
			{
				switch ( l_msg.message )
				{
				/* Menu Command */
				case WM_COMMAND:
					p_event.type = window_event::command_type;
					p_event.id   = LOWORD( l_msg.wParam );
					break;
					/* Mouse Button Left */
				case WM_LBUTTONDBLCLK:
					break;
				case WM_LBUTTONDOWN:
					break;
				case WM_LBUTTONUP:
					break;
				/* Mouse Button Middle */
				case WM_MBUTTONDBLCLK:
					break;
				case WM_MBUTTONDOWN:
					break;
				case WM_MBUTTONUP:
					break;
				/* Mouse Button Right */
				case WM_RBUTTONDBLCLK:
					break;
				case WM_RBUTTONDOWN:
					break;
				case WM_RBUTTONUP:
					break;
				/* Mouse Wheel */
				case WM_MOUSEHWHEEL:
					break;
				/* Mouse Move */
				case WM_MOUSEMOVE:
					break;
				/* Keydown */
				case WM_KEYDOWN:
					TranslateMessage( &l_msg );
					break;
				/* Keydown */
				case WM_CHAR:
					char l_mb[ 5 ];
					l_mb[ 0 ] = 0;
					l_mb[ 1 ] = 0;
					l_mb[ 2 ] = 0;
					l_mb[ 3 ] = 0;
					l_mb[ 4 ] = 0;
					WideCharToMultiByte( CP_UTF7, 0, reinterpret_cast<LPCWCH>( &l_msg.wParam ), 1, l_mb, 4, NULL, NULL );
					DE__LOG__INFO( "char " << l_mb << std::endl );
					break;
				/* Default - dispath message. */
				default:
					DispatchMessageW( &l_msg );
					break;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		void window::show( ) noexcept
		{
			ShowWindow( static_cast<HWND>( m_window.value( ) ), SW_SHOW );
		}

		void window::check_menu_item( const std::int32_t id )
		{
			HMENU l_menu = GetMenu( static_cast<HWND>( m_window.value( ) ) );

			CheckMenuItem( l_menu, static_cast<UINT>( id ), ( MF_BYCOMMAND | MF_CHECKED ) );
		}

		void window::uncheck_menu_item( const std::int32_t id )
		{
			HMENU l_menu = GetMenu( static_cast<HWND>( m_window.value( ) ) );

			CheckMenuItem( l_menu, static_cast<UINT>( id ), ( MF_BYCOMMAND | MF_UNCHECKED ) );
		}
	}
}

/* END */
