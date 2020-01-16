#!/bin/bash
# Copyright (c) 2019 Jason William Staiert. All Rights Reserved.

set -eu

# Get name of this script.

_de_script="$( basename "${BASH_SOURCE[0]}" )"

# Load DE environment paths.

. "$( dirname "${BASH_SOURCE[0]}" )/de.paths.sh"

# Load DE bash functions.

. "$( dirname "${BASH_SOURCE[0]}" )/de.functions.sh"

# Setup default values for command-line arguments.

_de_update_deps=true
_de_debug=true
_de_release=true
_de_target='win64.1.dev.0'
_de_modules_master_list="khronos_spirv_headers:khronos_spirv_tools:khronos_glslang:khronos_vulkan_headers:khronos_vulkan_loader:khronos_vulkan_tools:khronos_vulkan_validation_layers"
_de_modules="${_de_modules_master_list}"

# Print script usage, description, and command-line arguments to stdout.

function _de_help_cmdline()
{
	printf "${_de_script}: ${_de_cyan}${_de_script}${_de_white} [-u|--update-deps] [-d|--debug] [-r|--release] [-t|--target <name>] [-m|--module <colon delimited list>]${_de_default}\n"
	echo ""
	echo "	Description:"
	echo ""
	echo "	  Invokes git and cmake commands to build DE-KIT."
	echo ""
	echo "	Command-Line Arguments:"
	echo "	  -u|--update-deps			 Update dependencies of each specified module to a known good state. This action occurs before builds and must be done at least once after a clean checkout."
	echo "	  -d|--debug				 Build and install the Debug configuration for each specified module."
	echo "	  -r|--release				 Build and install the Release configuration for each specified module."
	echo "	  -t|--target <name>			 Act on the specified version of each module. Default is '${_de_target}'."
	echo "	  -m|--modules <colon delimited list>	 Act on the specified modules. Default modules are listed below:"

	IFS=':' read -r -a __de_modules <<< "${_de_modules_master_list}"

	for i in "${!__de_modules[@]}";
	do

		echo "							 ${__de_modules[$i]}"

	done
}

# Process command-line input.

while [[ $# -gt 0 ]]
do
	arg="$1"
	case $arg in
		-u|--update-deps)
		_de_update_deps=true
		shift
		;;
		-d|--debug)
		_de_debug=true
		shift
		;;
		-r|--release)
		_de_release=true
		shift
		;;
		-t|--target)
		_de_target="${2:-}"
		shift
		shift
		;;
		-m|--modules)
		_de_modules="${2:-}"
		shift
		shift
		;;
		-h|--help)
		_de_help_cmdline
		exit 0
		;;
		*)
		de_error "Unrecognized command-line argument '$1'."
		exit 1
		;;
	esac
done

# Declare module data arrays, these will be populated by the versions file which is loaded next.

declare -A DE_FUNCTION_PREFIX
declare -A DE_SOURCE_PATH
declare -A DE_COMMIT_ID

# Verify version argument is valid.

_de_target_path="${DE_PLATFORM_SCRIPTS_TARGETS_DIR}/de-kit.${_de_target}.sh"

if [[ ! -f "${_de_target_path}" ]];
then

	de_error "No configuration file for target '${_de_target}' found in '${DE_PLATFORM_SCRIPTS_TARGETS_DIR}'"

	exit 1

else

	. "${_de_target_path}"

fi

# Verify modules list is valid.

# Create array from modules master list.

IFS=':' read -r -a _de_modules_master_array <<< "${_de_modules_master_list}"

# Crete array from modules list.

IFS=':' read -r -a _de_modules_array <<< "${_de_modules}"

# Iterate over each entry in the modules array and match it to an entry in the master list array.

_de_module_error=false

for i in "${!_de_modules_array[@]}";
do

	_de_found=false

	for j in "${!_de_modules_master_array[@]}";
	do

		if [[ "${_de_modules_array[$i]}" == "${_de_modules_master_array[$j]}" ]];
		then

			_de_found=true

			break;

		fi

	done

	if ! ${_de_found};
	then

		_de_module_error=true

		de_error "Invalid module argument '${_de_modules_array[$i]}'."

	fi

done

# Exit if a module error was found.

if ${_de_module_error};
then

	exit 1

fi

# Iterate over each module and verify prerequisites are satisfied.

_de_prereq_missing=false

for i in "${!_de_modules_array[@]}";
do

	# Start.

	# Load the modules function file.

	_de_fn_file="${DE_PLATFORM_SCRIPTS_FUNCTIONS_DIR}/de.functions.${DE_SOURCE_PATH[${_de_modules_array[$i]}]}.sh"

	if [[ -f "${_de_fn_file}" ]];
	then

		. "${_de_fn_file}"

	else

		de_error "Module '${_de_modules_array[$i]}' has no function file in '${DE_PLATFORM_SCRIPTS_FUNCTIONS_DIR}'."
		de_error "Expecting file '${_de_fn_file}'."

		_de_prereq_missing=true

	fi

	# Verify INIT module function is defined.

	_de_fn_update_deps="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_update_deps"

	if [[ "$(type -t ${_de_fn_update_deps} )" != "function" ]];
	then

		de_error "Missing INITIALIZE module function '${_de_fn_update_deps}'."

		_de_prereq_missing=true

	fi

	# Verify Build DEBUG module function is defined.

	_de_fn_build_debug="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_build_debug"

	if [[ "$(type -t ${_de_fn_build_debug} )" != "function" ]];
	then

		de_error "Missing DEBUG Build module function '${_de_fn_build_debug}'."

		_de_prereq_missing=true

	fi


	# Verify Build RELEASE module function is defined.

	_de_fn_build_release="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_build_release"

	if [[ "$(type -t ${_de_fn_build_release} )" != "function" ]];
	then

		de_error "Missing RELEASE Build module function '${_de_fn_build_release}'."

		_de_prereq_missing=true

	fi

	# Done

done

# Terminate build if prerequisites are missing.

if ${_de_prereq_missing};
then

	de_error "One or more module prerequisites are missing. Terminating build."

	exit 1

fi

# Iterate over each module and execute actions.

for i in "${!_de_modules_array[@]}";
do

	# Start

	_de_source_dir="${DE_ROOT_DIR}/${DE_SOURCE_PATH[${_de_modules_array[$i]}]}"
	_de_install_dir="${DE_PLATFORM_TARGETS_DIR}/de-kit.${DE_TARGET}"
	_de_install_debug_dir="${_de_install_dir}/debug"
	_de_install_release_dir="${_de_install_dir}/release"
	_de_fn_update_deps="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_update_deps"
	_de_fn_build_debug="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_build_debug"
	_de_fn_build_release="${DE_FUNCTION_PREFIX[${_de_modules_array[$i]}]}_build_release"

	de_echo_var _de_source_dir
	de_echo_var _de_install_dir
	de_echo_var _de_fn_update_deps
	de_echo_var _de_fn_build_debug
	de_echo_var _de_fn_build_release

	# Perform INIT action.

	if $_de_update_deps;
	then

		echo "Initializing source for '${_de_modules_array[$i]}'."

		cd "${_de_source_dir}"

		git checkout --force "${DE_COMMIT_ID[${_de_modules_array[$i]}]}"

		git clean -f -x -d

		"${_de_fn_update_deps}"

	fi

	# Perform DEBUG Build action.

	if $_de_debug;
	then

		echo "Building DEBUG configuration for '${_de_modules_array[$i]}'."

		cd "${_de_source_dir}"

		mkdir -p "${_de_install_debug_dir}"

		"${_de_fn_build_debug}" "${_de_install_debug_dir}"

	fi

	# Perform RELEASE Build action.

	if $_de_release;
	then

		echo "Building RELEASE configuration for '${_de_modules_array[$i]}'."

		cd "${_de_source_dir}"

		mkdir -p "${_de_install_release_dir}"

		"${_de_fn_build_release}" "${_de_install_release_dir}"

	fi

	# Done.

	echo "Finished with module '${_de_modules_array[$i]}'"

done

# END
