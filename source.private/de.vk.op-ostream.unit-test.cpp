/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.vk.op-ostream.hpp"

#include <de.vk.instance.hpp>
#include <de.vk.loader.hpp>

#include <sstream>

TEST( de__vk__op_ostream, extension_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::extension uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ),
		u8"extension.name         = VK_KHR_surface\n"
		u8"extension.spec_version = 1.2.3\n" );
}

TEST( de__vk__op_ostream, extensions_size_zero_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::extensions uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), u8"extensions.size = 0\n" );
}

TEST( de__vk__op_ostream, extensions_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::extensions uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ),
		u8"extensions.size = 2\n"
		u8"extensions[0]\n"
		u8"extension.name         = GLOBAL_EXTENSION_1\n"
		u8"extension.spec_version = 1.2.3\n"
		u8"extensions[1]\n"
		u8"extension.name         = GLOBAL_EXTENSION_2\n"
		u8"extension.spec_version = 2.4.6\n" );
}

TEST( de__vk__op_ostream, layer_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::layer uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ),
		u8"layer.name                   = LAYER_1\n"
		u8"layer.spec_version           = 1.2.3\n"
		u8"layer.implementation_version = 2.4.6\n"
		u8"layer.description            = This is LAYER_1.\n"
		u8"layer.extensions:\n"
		u8"extensions.size = 2\n"
		u8"extensions[0]\n"
		u8"extension.name         = LAYER_1_EXTENSION_1\n"
		u8"extension.spec_version = 1.2.3\n"
		u8"extensions[1]\n"
		u8"extension.name         = LAYER_1_EXTENSION_2\n"
		u8"extension.spec_version = 2.4.6\n" );
}

TEST( de__vk__op_ostream, layers_size_zero_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::layers uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), u8"layers.size = 0\n" );
}

TEST( de__vk__op_ostream, layers_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::layers uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ),
		u8"layers.size = 2\n"
		u8"layers[0]\n"
		u8"layer.name                   = LAYER_1\n"
		u8"layer.spec_version           = 1.2.3\n"
		u8"layer.implementation_version = 2.4.6\n"
		u8"layer.description            = This is LAYER_1.\n"
		u8"layer.extensions:\n"
		u8"extensions.size = 2\n"
		u8"extensions[0]\n"
		u8"extension.name         = LAYER_1_EXTENSION_1\n"
		u8"extension.spec_version = 1.2.3\n"
		u8"extensions[1]\n"
		u8"extension.name         = LAYER_1_EXTENSION_2\n"
		u8"extension.spec_version = 2.4.6\n"
		u8"layers[1]\n"
		u8"layer.name                   = LAYER_2\n"
		u8"layer.spec_version           = 3.6.9\n"
		u8"layer.implementation_version = 4.8.12\n"
		u8"layer.description            = This is LAYER_2.\n"
		u8"layer.extensions:\n"
		u8"extensions.size = 0\n" );
}

TEST( de__vk__op_ostream, instance_configuration_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::instance_configuration uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, extent_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::extent uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, queue_family_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::queue_family uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, queue_families_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::queue_families uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, memory_type_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::memory_type uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, memory_heap_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::memory_heap uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, memory_heaps_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::memory_heaps uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, physical_device_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::physical_device uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

TEST( de__vk__op_ostream, physical_devices_operator_ostream )
{
	std::stringstream l_ostream{};

	de::vk::physical_devices uut{};

	l_ostream << uut;

	EXPECT_EQ( l_ostream.str( ), "" );
	FAIL( ) << "Test expectations not defined.";
}

/* END */
