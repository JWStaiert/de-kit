#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.version.hpp>

#include <de.os.module.hpp>

#include <filesystem>
#include <set>
#include <string>
#include <vector>

class de__vk__loader_get_instance_function_address_throws_Test;

namespace de
{
	namespace vk
	{
		struct extension
		{
			std::string name;
			de::version spec_version;
		};

		using extensions = std::vector<extension>;

		struct layer
		{
			std::string name;
			de::version spec_version;
			de::version implementation_version;
			std::string description;
			extensions  extensions;
		};

		using layers = std::vector<layer>;

		class instance;

		class loader
		{
			friend class ::de__vk__loader_get_instance_function_address_throws_Test;

			de::os::module m_module;

			de::version m_api_version;

			layers m_layers;

			extensions m_extensions;

			void enumerate_api_version( );

			void enumerate_layer_properties( );

			void enumerate_extension_properties( );

		public:
			loader( ) = delete;

			loader( const std::filesystem::path& p_loader_dll_path );

			loader( const loader& ) = delete;

			~loader( ) = default;

			loader& operator=( const loader& ) = delete;

			const de::version api_version( ) const noexcept
			{
				return m_api_version;
			}

			const layers& layers( ) const noexcept
			{
				return m_layers;
			}

			const extensions& extensions( ) const noexcept
			{
				return m_extensions;
			}

			void* get_function_address( const char* p_function_name ) const;
		};
	}
}

/* END */
