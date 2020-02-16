#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

namespace de
{
	template<typename T>
	using deleter = void ( * )( T ) noexcept;

	template<typename T>
	class handle
	{
		deleter<T> m_deleter;

		T m_handle;

	public:
		inline handle( ) = delete;

		inline handle( deleter<T> p_deleter, const T p_initial ) noexcept
			: m_deleter{ p_deleter }
			, m_handle{ p_initial }
		{
		}

		handle( handle&& ) = delete;

		handle( const handle& ) = delete;

		inline ~handle( )
		{
			m_deleter( m_handle );
		}

		handle& operator=( handle&& ) = delete;

		handle& operator=( const handle& ) = delete;

		inline handle& operator=( T p_handle ) noexcept
		{
			m_handle = p_handle;
			return *this;
		}

		inline T value( ) noexcept
		{
			return m_handle;
		}

		inline const T value( ) const noexcept
		{
			return m_handle;
		}

		inline operator T( ) noexcept
		{
			return m_handle;
		}

		inline operator const T( ) const noexcept
		{
			return m_handle;
		}
	};
}

/* END */
