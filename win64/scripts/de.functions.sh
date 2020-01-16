#!/bin/bash
# Copyright (c) 2020 Jason William Staiert. All Rights Reserved.

set -eu

# Define color variables if script is being run on a color tty.

if test -t 1;
then
	if [[ "$( tput colors )" -ge 8 ]];
	then
		_de_cyan='\033[0;36m'
		_de_green='\033[0;32m'
		_de_red='\033[0;31m'
		_de_white='\033[1;37m'
		_de_default='\033[0m'
	else
		_de_cyan=''
		_de_green=''
		_de_red=''
		_de_white=''
		_de_default=''
	fi
fi

# Print a formatted error message on stdout.
#   arg 1    - Message.
function de_error()
{
	printf "${_de_cyan}${_de_script:-}${_de_red}: ERROR : ${_de_white}%s${_de_default}\n" "${1}"
}

# Print the name and value of a variable to stdout.
#   arg 1    - Variable name.
function de_echo_var()
{
	local _de_var="${1}"

	printf "%-32s = %s\n" "${_de_var}" "${!_de_var}"
}

# Check if a GIT clone exists, if so then clean it, otherwise clone its parent.
#   arg 1    - GIT parent path
#   arg 2    - GIT clone path
function de_clean_clone_dependency()
{
	local _de_parent_path="${1}"
	local _de_clone_path="${2}"

	if [[ ! -d "${_de_clone_path}" ]];
	then

		git clone "${_de_parent_path}" "${_de_clone_path}"

	else

		local _de_previous_dir="${PWD}"

		cd "${_de_clone_path}"

		git clean -f -x -d

		cd "${_de_previous_dir}"

	fi
}

# END
