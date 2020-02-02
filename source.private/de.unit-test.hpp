#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <string>

/* A mock for vulkan-1.dll. */

static const std::string DE_TEST_MODULE_PATH { "../../tests/" };

static const std::string DE_TEST_MODULE_NAME { "de.vk.mock.dll" };

static const std::string DE_TEST_MODULE_PATHNAME { DE_TEST_MODULE_PATH + DE_TEST_MODULE_NAME };

/* The real vulkan-1.dll. */

static const std::string DE_VULKAN_LOADER_MODULE_PATH { "../../targets/active/debug/bin/" };

static const std::string DE_VULKAN_LOADER_MODULE_NAME { "vulkan-1.dll" };

static const std::string DE_VULKAN_LOADER_MODULE_PATHNAME { DE_VULKAN_LOADER_MODULE_PATH + DE_VULKAN_LOADER_MODULE_NAME };

/* END */
