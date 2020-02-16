#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <ostream>

namespace de
{
	class version;
}

std::ostream& operator<<( std::ostream&, const de::version& );

/* END */
