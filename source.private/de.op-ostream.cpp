#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.op-ostream.hpp"

#include <de.version.hpp>

std::ostream& operator<<( std::ostream& p_stream, const de::version& p_value )
{
	p_stream << std::string{ p_value };
	return p_stream;
}

/* END */
