#!/bin/bash
# Copyright (c) 2019 Jason William Staiert. All Rights Reserved.

set -eu

# Perform dependency initialization for this module.
# NOTE: PWD is the root directory of this module's GIT repository.
function kst_update_deps()
{
	cd ./external

	# Check if depdencies have been cloned, if so then clean them, otherwise clone them.
	de_clean_clone_dependency ../../google.googletest	 ./googletest
	de_clean_clone_dependency ../../google.re2		 ./re2
	de_clean_clone_dependency ../../google.effcee		 ./effcee
	de_clean_clone_dependency ../../khronos.spirv-headers	 ./SPIRV-Headers

	# Run ../utils/git-sync-deps from ./external to get correct versions of dependency repos.
	winpty python ../utils/git-sync-deps
}

# Private helper function. Build and install this module.
#   arg1    - Install path prefix.
#   arg2    - CMake build type.
function _kst_build()
{
	local _de_install_prefix="${1}"
	local _de_cmake_build_type="${2}"

	winpty cmake .. \
		-G "${DE_TOOLCHAIN}" \
		-DCMAKE_BUILD_TYPE=${_de_cmake_build_type} \
		-DCMAKE_INSTALL_PREFIX="${_de_install_prefix}" \
		-DSPIRV_BUILD_FUZZER=OFF \
		-DSPIRV_COLOR_TERMINAL=ON

	winpty cmake --build . \
		--config ${_de_cmake_build_type} \
		--target install

	rm -rf "${_de_install_prefix}/include/effcee"
	rm -f "${_de_install_prefix}/lib/effcee.lib"
}

# Build and install the DEBUG configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kst_build_debug()
{
	mkdir -p ./build.debug

	cd ./build.debug

	_kst_build "${1}" Debug
}

# Build and install the RELEASE configuration of this module.
#   arg1    - Install path prefix.
# NOTE: PWD is the root directory of this module's GIT repository.
function kst_build_release()
{
	mkdir -p ./build.release

	cd ./build.release

	_kst_build "${1}" Release
}

# END
