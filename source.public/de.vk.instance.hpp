#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.version.hpp"

#include "de.vk.util.hpp"

#include <string>
#include <vector>

namespace de
{
	namespace vk
	{
		using layer_names = std::vector< std::string >;

		using extension_names = std::vector< std::string >;

		struct instance_configuration
		{
			std::string application_name    { "default application name" };
			version application_version     { 0 , 0 , 1 };
			layer_names layer_names         { };
			extension_names extension_names { };
			version api_version             { 1 , 0 , 0 };
		};

		struct extent
		{
			std::uint32_t width  = 0u;
			std::uint32_t height = 0u;
			std::uint32_t depth  = 0u;
		};

		struct queue_family
		{
			struct
			{
				bool graphics         = false;
				bool compute          = false;
				bool transfer         = false;
				bool sparse_binding   = false;
				bool protected_memory = false;
			} flags;

			std::uint32_t count = 0;

			extent min_image_transfer_granularity;
		};

		using queue_families = std::vector<queue_family>;

		struct memory_type
		{
			bool device_coherent  = false;
			bool device_local     = false;
			bool device_uncached  = false;
			bool host_cached      = false;
			bool host_coherent    = false;
			bool host_visible     = false;
			bool lazily_allocated = false;
			bool protected_memory = false;
		};

		struct memory_heap
		{
			memory_type   type;
			std::uint64_t size           = 0ul;
			bool          device_local   = false;
			bool          multi_instance = false;
		};

		using memory_heaps = std::vector<memory_heap>;

		struct physical_device
		{
			std::string name;
			de::version api_version;
			de::version driver_version;
			memory_heaps memory_heaps;
			queue_families queue_families;
			void * handle;
		};
		
		using physical_devices = std::vector< physical_device >;

		class loader;

		class instance
		{
			const loader & m_loader;

			instance_configuration m_configuration;

			physical_devices m_physical_devices;

			handle m_instance;

			void assert_layers_available( );

			void assert_extensions_available( );

			void create_instance( );

			void create_debug_report( );

			void create_debug_messenger( );

			void enumerate_physical_devices( );

		public:

			instance( ) = delete;

			instance( const loader & , const instance_configuration & );

			instance( const instance & ) = delete;

			~instance( ) = default;

			instance & operator=( const instance & ) = delete;

			const instance_configuration & configuration( ) const noexcept { return m_configuration; }

			const physical_devices & physical_devices( ) const noexcept { return m_physical_devices; }

			void * get_function_address( const char * p_function_name ) const;
		};
	}
}

/* END */
