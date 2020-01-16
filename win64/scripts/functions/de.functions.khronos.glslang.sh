#!/bin/bash
# Copyright (c) 2019 Jason William Staiert. All Rights Reserved.

set -eu

# Perform dependency initialization for this module.
# NOTE: PWD is the root directory of this module's GIT repository.
function kg_update_deps()
{
	cd ./External

	# Check if depdencies have been cloned, if so then clean them, otherwise clone them.

	de_clean_clone_dependency ../../google.googletest ./googletest

	de_clean_clone_dependency ../../khronos.spirv-tools ./spirv-tools

	cd ./spirv-tools/external

	de_clean_clone_dependency ../../../../khronos.spirv-headers ./spirv-headers

	cd ../../..

	# Run ./update_glslang_sources.py.

	winpty python ./update_glslang_sources.py
}

# Private helper function. Build and install this module.
#   arg1    - Install path prefix.
#   arg2    - CMake build type.
function _kg_build()
{
	local _de_install_prefix="${1}"
	local _de_cmake_build_type="${2}"

	winpty cmake .. \
		-G "${DE_TOOLCHAIN}" \
		-DCMAKE_BUILD_TYPE=${_de_cmake_build_type} \
		-DCMAKE_INSTALL_PREFIX="${_de_install_prefix}"

	winpty cmake --build . \
		--config ${_de_cmake_build_type} \
		--target install
}

# Build and install the DEBUG configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kg_build_debug()
{
	mkdir -p ./build.debug

	cd ./build.debug

	_kg_build "${1}" Debug
}

# Build and install the RELEASE configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kg_build_release()
{
	mkdir -p ./build.release

	cd ./build.release

	_kg_build "${1}" Release
}

# END
