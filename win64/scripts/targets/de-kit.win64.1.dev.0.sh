#!/bin/bash
# Copyright (c) 2020 Jason William Staiert. All Rights Reserved.

set -eu

DE_TARGET="win64.1.dev.0"

DE_TOOLCHAIN="Visual Studio 15 2017 Win64"

declare -A DE_FUNCTION_PREFIX
declare -A DE_SOURCE_PATH
declare -A DE_COMMIT_ID

DE_FUNCTION_PREFIX['khronos_spirv_headers']=ksh
    DE_SOURCE_PATH['khronos_spirv_headers']=khronos.spirv-headers
      DE_COMMIT_ID['khronos_spirv_headers']=af64a9e826bf5bb5fcd2434dd71be1e41e922563

DE_FUNCTION_PREFIX['khronos_spirv_tools']=kst
    DE_SOURCE_PATH['khronos_spirv_tools']=khronos.spirv-tools
      DE_COMMIT_ID['khronos_spirv_tools']=02910ffdffaa2966f613ede0c516645f5555c13c

DE_FUNCTION_PREFIX['khronos_glslang']=kg
    DE_SOURCE_PATH['khronos_glslang']=khronos.glslang
      DE_COMMIT_ID['khronos_glslang']=b131630e7c749a5dc19faa458024260c71fb170f

DE_FUNCTION_PREFIX['khronos_vulkan_headers']=kvh
    DE_SOURCE_PATH['khronos_vulkan_headers']=khronos.vulkan-headers
      DE_COMMIT_ID['khronos_vulkan_headers']="v1.1.130"

DE_FUNCTION_PREFIX['khronos_vulkan_loader']=kvl
    DE_SOURCE_PATH['khronos_vulkan_loader']=khronos.vulkan-loader
      DE_COMMIT_ID['khronos_vulkan_loader']="v1.1.130"

DE_FUNCTION_PREFIX['khronos_vulkan_tools']=kvt
    DE_SOURCE_PATH['khronos_vulkan_tools']=khronos.vulkan-tools
      DE_COMMIT_ID['khronos_vulkan_tools']="v1.1.130"

DE_FUNCTION_PREFIX['khronos_vulkan_validation_layers']=kvvl
    DE_SOURCE_PATH['khronos_vulkan_validation_layers']=khronos.vulkan-validation-layers
      DE_COMMIT_ID['khronos_vulkan_validation_layers']="v1.1.130"

DE_FUNCTION_PREFIX['lunarg_vulkan_tools']=lvt
    DE_SOURCE_PATH['lunarg_vulkan_tools']=lunarg.vulkan-tools
      DE_COMMIT_ID['lunarg_vulkan_tools']="sdk-1.1.130.0"

# END
