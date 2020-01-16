#!/bin/bash
# Copyright (c) 2019 Jason William Staiert. All Rights Reserved.

set -eu

# Perform dependency initialization for this module.
# NOTE: PWD is the root directory of this module's GIT repository.
function kvh_update_deps()
{
	# This function is a no-op.
	true
}

# Private helper function. Build and install this module.
#   arg1    - Install path prefix.
#   arg2    - CMake build type.
function _kvh_build()
{
	local _de_install_prefix="${1}"
	local _de_cmake_build_type="${2}"

	winpty cmake .. \
		-G "${DE_TOOLCHAIN}" \
		-DCMAKE_INSTALL_PREFIX="${_de_install_prefix}"

	winpty cmake --build . \
		--config ${_de_cmake_build_type} \
		--target install
}

# Build and install the DEBUG configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kvh_build_debug()
{
	mkdir -p ./build.debug

	cd ./build.debug

	_kvh_build "${1}" Debug
}

# Build and install the RELEASE configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kvh_build_release()
{
	mkdir -p ./build.release

	cd ./build.release

	_kvh_build "${1}" Release
}

# END
