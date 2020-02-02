#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <string>

#include <cstdint>

namespace de
{
	class version
	{
		std::uint32_t m_version;

	public:

		version( ) noexcept = default;

		version( const version & ) noexcept = default;

		version( std::uint32_t p_version ) noexcept;

		version( std::uint32_t p_major , std::uint32_t p_minor , std::uint32_t p_patch );

		~version( ) = default;

		version & operator=( const version & ) noexcept = default;

		operator std::uint32_t( ) const noexcept { return m_version; }

		operator std::string( ) const noexcept;

		friend inline bool operator==( const ::de::version & p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( p_lhs.m_version == p_rhs.m_version );
		}

		friend inline bool operator==( const ::de::version & p_lhs , const ::std::uint32_t p_rhs ) noexcept
		{
			return ( p_lhs.m_version == p_rhs );
		}

		friend inline bool operator==( const ::std::uint32_t p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( p_lhs == p_rhs.m_version );
		}

		friend inline bool operator==( const ::de::version & p_lhs , const char * p_rhs ) noexcept
		{
			return ( static_cast<std::string>( p_lhs ) == std::string ( p_rhs ) );
		}

		friend inline bool operator==( const char * p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( std::string( p_lhs ) == static_cast<std::string>( p_rhs ) );
		}

		friend inline bool operator!=( const ::de::version & p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( p_lhs.m_version != p_rhs.m_version );
		}

		friend inline bool operator!=( const ::de::version & p_lhs , const ::std::uint32_t p_rhs ) noexcept
		{
			return ( p_lhs.m_version != p_rhs );
		}

		friend inline bool operator!=( const ::std::uint32_t p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( p_lhs != p_rhs.m_version );
		}

		friend inline bool operator!=( const ::de::version & p_lhs , const char * p_rhs ) noexcept
		{
			return ( static_cast<std::string>( p_lhs ) != std::string( p_rhs ) );
		}

		friend inline bool operator!=( const char * p_lhs , const ::de::version & p_rhs ) noexcept
		{
			return ( std::string( p_lhs ) != static_cast<std::string>( p_rhs ) );
		}
	};
}

/* END */
