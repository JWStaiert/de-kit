#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.version.hpp"

#include <string>

namespace de
{
	enum class window_mode
	{
		bordered ,
		borderless ,
		fullscreen ,
	};

	struct app
	{
		std::string name { "default app name" };

		de::version version;

		window_mode window_mode;

		// default dimensions
	};
}

/* END */
