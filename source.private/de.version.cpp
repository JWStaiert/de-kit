/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.version.hpp"
#include "de.exception.hpp"

#include <sstream>
#include <string>

#include <vulkan/vulkan.h>

namespace de
{
	version::version( std::uint32_t p_version ) noexcept
		: m_version { p_version }
	{
	}

	version::version( std::uint32_t p_major , std::uint32_t p_minor , std::uint32_t p_patch )
		: m_version { VK_MAKE_VERSION( p_major , p_minor , p_patch ) }
	{
		DE__EXCEPTION__ASSERT( p_major < 1024 );
		DE__EXCEPTION__ASSERT( p_minor < 1024 );
		DE__EXCEPTION__ASSERT( p_patch < 4096 );
	}

	version::operator std::string( ) const noexcept
	{
		std::stringstream m_tmp;
		m_tmp << VK_VERSION_MAJOR( m_version );
		m_tmp << ".";
		m_tmp << VK_VERSION_MINOR( m_version );
		m_tmp << ".";
		m_tmp << VK_VERSION_PATCH( m_version );
		return m_tmp.str( );
	}
}

/* END */