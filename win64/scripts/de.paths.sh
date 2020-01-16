#!/bin/bash
# Copyright (c) 2020 Jason William Staiert. All Rights Reserved.

set -eu

# Build environment variables.

export DE_THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" ; pwd -P )"
export DE_ROOT_DIR="$( cd "${DE_THIS_DIR}/../.." ; pwd -P )"
export DE_PLATFORM_DIR="${DE_ROOT_DIR}/win64"
export DE_PLATFORM_TARGETS_DIR="${DE_PLATFORM_DIR}/targets"
export DE_PLATFORM_SCRIPTS_DIR="${DE_PLATFORM_DIR}/scripts"
export DE_PLATFORM_SCRIPTS_FUNCTIONS_DIR="${DE_PLATFORM_SCRIPTS_DIR}/functions"
export DE_PLATFORM_SCRIPTS_TARGETS_DIR="${DE_PLATFORM_SCRIPTS_DIR}/targets"

# END
