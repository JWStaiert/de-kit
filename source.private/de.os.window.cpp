/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.os.window.hpp"

#include "de.os.error.hpp"

#include "de.app.hpp"
#include "de.log.hpp"

#include <Windows.h>

#ifdef UNICODE
#error "This module expects UNICODE to be disabled. In Visual Studio 2017 the Character Set option must be 'Not Set'."
#endif

namespace de
{
	namespace os
	{
		static LRESULT wind_proc( HWND , UINT , WPARAM , LPARAM );
			
		static const char CLASS_NAME[] = "de::os::window";

		static const WNDCLASS WINDOW_CLASS {
			( CS_DBLCLKS | CS_OWNDC ) ,
			wind_proc ,
			0,
			0,
			NULL,
			NULL,
			NULL,
			NULL,
			CLASS_NAME
		};

		void process_close_message( window * p_window_ptr ) noexcept
		{
			p_window_ptr->m_state = de::os::window_state::closed;
		}

		void process_resized_message( window * p_window_ptr , window_state p_state , std::uint16_t p_width , std::uint16_t p_height ) noexcept
		{
			p_window_ptr->m_state = p_state;
			p_window_ptr->m_size = window_size { p_width , p_height };
		}

		static LRESULT CALLBACK wind_proc( HWND p_wnd , UINT p_msg , WPARAM p_wparam , LPARAM p_lparam )
		{
			de::os::window* l_window_ptr = reinterpret_cast<de::os::window *>( GetWindowLongPtrA( p_wnd , GWLP_USERDATA ) );

			LRESULT l_rv = 0;

			switch ( p_msg )
			{
			case WM_SIZE:
				switch ( p_wparam )
				{
				case SIZE_RESTORED:
					process_resized_message( l_window_ptr , window_state::visible , LOWORD( p_lparam ) , HIWORD( p_lparam ) );
					break;
				case SIZE_MAXIMIZED:
					process_resized_message( l_window_ptr , window_state::visible_maximized , LOWORD( p_lparam ) , HIWORD( p_lparam ) );
					break;
				case SIZE_MINIMIZED:
					process_resized_message( l_window_ptr , window_state::visible_minimized , LOWORD( p_lparam ) , HIWORD( p_lparam ) );
					break;
				default:
					break;
				}
				l_rv = DefWindowProcA( p_wnd , p_msg , p_wparam , p_lparam );
				break;
			case WM_CLOSE:
				process_close_message( l_window_ptr );
				break;
			default:
				l_rv = DefWindowProcA( p_wnd , p_msg , p_wparam , p_lparam );
			}

			return l_rv;
		}

		static void class_deleter( std::uint16_t p_class )
		{
			if ( p_class != 0 )
			{
				DE__OS__ERROR__LOG( UnregisterClassA( CLASS_NAME , NULL ) != TRUE );
			}
		}

		static void hwnd_deleter( void * p_hwnd )
		{
			if ( p_hwnd != nullptr )
			{
				DE__OS__ERROR__LOG( DestroyWindow( static_cast<HWND>( p_hwnd ) ) != TRUE );
			}
		}

		window::window( const de::app & p_app , bool p_always_on_top )
			: m_class          { class_deleter , 0 }
			, m_handle         { hwnd_deleter  , nullptr }
			, m_state          { window_state::open }
			, m_size           { }
		{
			HMODULE l_hinstance = GetModuleHandleA( NULL );

			WNDCLASSA l_window_class { };
			l_window_class.style         = ( CS_DBLCLKS | CS_OWNDC );
			l_window_class.lpfnWndProc   = wind_proc;
			l_window_class.hInstance     = l_hinstance;
			l_window_class.lpszClassName = CLASS_NAME;

			DE__OS__ERROR__CHECK( ( m_class = RegisterClassA( &l_window_class ) ) == 0 );

			HWND l_handle = CreateWindowExA(
				( p_always_on_top ? WS_EX_TOPMOST : 0 ) ,
				CLASS_NAME ,
				p_app.name.c_str( ) ,
				WS_OVERLAPPEDWINDOW ,
				CW_USEDEFAULT ,
				CW_USEDEFAULT ,
				CW_USEDEFAULT ,
				CW_USEDEFAULT ,
				NULL ,
				NULL ,
				l_hinstance ,
				NULL
				);

			DE__OS__ERROR__CHECK( l_handle == NULL );

			m_handle = l_handle;

			DE__OS__ERROR__CHECK( SetWindowLongPtrA( l_handle , GWLP_USERDATA , reinterpret_cast<LONG_PTR>( this ) ) != 0 ); // JWS: The previous value should always be zero after window creation so this function always succeeds.
		}

		bool window::has_event( ) noexcept
		{
			MSG l_msg { };

			if ( PeekMessageA( &l_msg , static_cast<HWND>( static_cast<void *>( m_handle ) ) , 0 , 0 , PM_REMOVE ) )
			{
				switch ( l_msg.message )
				{
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
					/* Keydown */
				case WM_CHAR:
					char l_mb[ 5 ];
					l_mb[ 0 ] = 0;
					l_mb[ 1 ] = 0;
					l_mb[ 2 ] = 0;
					l_mb[ 3 ] = 0;
					l_mb[ 4 ] = 0;
					WideCharToMultiByte( CP_UTF7 , 0 , reinterpret_cast<LPCWCH>( &l_msg.wParam ) , 1 , l_mb , 4 , NULL , NULL );
					DE__LOG__INFO( "char " << l_mb << std::endl );
					break;
				/* Default - dispath message. */
				default:
					DispatchMessageA( &l_msg );
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
			if ( ShowWindow( static_cast<HWND>( static_cast<void *>( m_handle ) ) , SW_SHOW ) == FALSE )
			{
				m_state = window_state::visible;
			}
		}
	}
}

/* END */
