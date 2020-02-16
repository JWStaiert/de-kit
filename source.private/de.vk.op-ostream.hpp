#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.op-ostream.hpp>

#include <de.math.op-ostream.hpp>

#include <ostream>
#include <vector>

namespace de
{
	namespace vk
	{
		struct extension;

		using extensions = std::vector<extension>;

		struct layer;

		using layers = std::vector<layer>;

		struct instance_configuration;

		struct queue_family;

		using queue_families = std::vector<queue_family>;

		struct memory_type;

		struct memory_heap;

		using memory_heaps = std::vector<memory_heap>;

		struct physical_device;

		using physical_devices = std::vector<physical_device>;
	}
}

std::ostream& operator<<( std::ostream&, const de::vk::extension& );

std::ostream& operator<<( std::ostream&, const de::vk::extensions& );

std::ostream& operator<<( std::ostream&, const de::vk::layer& );

std::ostream& operator<<( std::ostream&, const de::vk::layers& );

std::ostream& operator<<( std::ostream&, const de::vk::instance_configuration& );

std::ostream& operator<<( std::ostream&, const de::vk::queue_family& );

std::ostream& operator<<( std::ostream&, const de::vk::queue_families& );

std::ostream& operator<<( std::ostream&, const de::vk::memory_type& );

std::ostream& operator<<( std::ostream&, const de::vk::memory_heap& );

std::ostream& operator<<( std::ostream&, const de::vk::memory_heaps& );

std::ostream& operator<<( std::ostream&, const de::vk::physical_device& );

std::ostream& operator<<( std::ostream&, const de::vk::physical_devices& );

/* END */
