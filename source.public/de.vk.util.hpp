#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.exception.hpp"

#include "de.os.module.hpp"

#define DE__VK__FUNCTION_EXTERN( p_name ) extern PFN_##p_name _##p_name

#define DE__VK__FUNCTION( p_name ) PFN_##p_name _##p_name = nullptr

#define DE__VK__FUNCTION_LOAD( p_name , p_get_addr_fn ) _##p_name = static_cast<PFN_##p_name>( p_get_addr_fn( #p_name ) )

#define DE__VK__FUNCTION_CALL( p_name ) _##p_name

namespace de
{
	namespace vk
	{
		using deleter = void( *)( void * );

		class handle
		{
			void * m_handle;

			deleter m_deleter;

		public:

			inline handle( ) = delete;

			inline handle( deleter p_deleter ) noexcept
				: m_handle { nullptr }
				, m_deleter { p_deleter }
			{
			}

			handle( const handle & ) = delete;

			inline ~handle( )
			{
				if ( ( m_handle != nullptr ) && ( m_deleter != nullptr ) )
				{
					m_deleter( m_handle );
				}
			}

			handle & operator=( const handle & ) = delete;

			inline handle & operator=( void * p_handle ) noexcept
			{
				m_handle = p_handle;
				return *this;
			}

			inline operator void *( ) noexcept { return m_handle; }

			inline operator const void *( ) const noexcept { return m_handle; }
		};
	}
}

/* END */
