#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <string>

/* A mock for vulkan-1.dll. */

static const std::wstring DE_TEST_MODULE_PATH{ L"../../tests/" };

static const std::wstring DE_TEST_MODULE_NAME{ L"de.vk.mock.dll" };

static const std::wstring DE_TEST_MODULE_PATHNAME{ DE_TEST_MODULE_PATH + DE_TEST_MODULE_NAME };

/* The real vulkan-1.dll. */

static const std::wstring DE_VULKAN_LOADER_MODULE_PATH{ L"../../targets/active/debug/bin/" };

static const std::wstring DE_VULKAN_LOADER_MODULE_NAME{ L"vulkan-1.dll" };

static const std::wstring DE_VULKAN_LOADER_MODULE_PATHNAME{ DE_VULKAN_LOADER_MODULE_PATH + DE_VULKAN_LOADER_MODULE_NAME };

/* END */
