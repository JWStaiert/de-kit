/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.vk.op-ostream.hpp"

#include <de.op-ostream.hpp>
#include <de.version.hpp>

#include <de.math.op-ostream.hpp>

#include <de.vk.instance.hpp>
#include <de.vk.loader.hpp>

std::ostream& operator<<( std::ostream& p_stream, const de::vk::extension& )
{
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::extensions& )
{
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::layer& )
{
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::layers& )
{
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::instance_configuration& )
{
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::queue_family& p_queue_family )
{
	p_stream << u8"      count            = " << p_queue_family.count << std::endl;
	p_stream << u8"      graphics         = " << p_queue_family.graphics << std::endl;
	p_stream << u8"      compute          = " << p_queue_family.compute << std::endl;
	p_stream << u8"      transfer         = " << p_queue_family.transfer << std::endl;
	p_stream << u8"      sparse_binding   = " << p_queue_family.sparse_binding << std::endl;
	p_stream << u8"      protected_memory = " << p_queue_family.protected_memory << std::endl;
	p_stream << u8"      minimum_transfer_granularity = " << p_queue_family.min_image_transfer_granularity << std::endl;
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::queue_families& p_queue_families )
{
	p_stream << "  Queue Family Count: " << p_queue_families.size( ) << std::endl;

	for ( auto i = 0; i < p_queue_families.size( ); ++i )
	{
		p_stream << "    Queue Family [" << i << "]" << std::endl;
		p_stream << p_queue_families[ i ];
	}

	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::memory_type& p_memory_type )
{
	p_stream << u8"      device_coherent  = " << p_memory_type.device_coherent << std::endl;
	p_stream << u8"      device_local     = " << p_memory_type.device_local << std::endl;
	p_stream << u8"      device_uncached  = " << p_memory_type.device_uncached << std::endl;
	p_stream << u8"      host_cached      = " << p_memory_type.host_cached << std::endl;
	p_stream << u8"      host_coherent    = " << p_memory_type.host_coherent << std::endl;
	p_stream << u8"      host_visible     = " << p_memory_type.host_visible << std::endl;
	p_stream << u8"      lazily_allocated = " << p_memory_type.lazily_allocated << std::endl;
	p_stream << u8"      protected_memory = " << p_memory_type.protected_memory << std::endl;
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::memory_heap& p_memory_heap )
{
	p_stream << u8"    Memory Type" << std::endl;
	p_stream << p_memory_heap.type;
	p_stream << u8"      size           = " << p_memory_heap.size << std::endl;
	p_stream << u8"      device_local   = " << p_memory_heap.device_local << std::endl;
	p_stream << u8"      multi_instance = " << p_memory_heap.multi_instance << std::endl;
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::memory_heaps& p_memory_heaps )
{
	p_stream << "  Memory Heap Count: " << p_memory_heaps.size( ) << std::endl;

	for ( auto i = 0; i < p_memory_heaps.size( ); ++i )
	{
		p_stream << "    Memory Heap [" << i << "]" << std::endl;
		p_stream << p_memory_heaps[ i ];
	}

	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::physical_device& p_device )
{
	p_stream << "  name           = " << p_device.name << std::endl;
	p_stream << "  api_version    = " << p_device.api_version << std::endl;
	p_stream << "  driver_version = " << p_device.driver_version << std::endl;
	p_stream << p_device.memory_heaps;
	p_stream << p_device.queue_families;
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::vk::physical_devices& p_devices )
{
	p_stream << "Physical Device Count:" << p_devices.size( ) << std::endl;

	for ( auto i = 0; i < p_devices.size( ); ++i )
	{
		p_stream << "Physical Device [" << i << "]" << std::endl;
		p_stream << p_devices[ i ];
	}

	return p_stream;
}

/* END */
