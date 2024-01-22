cmake_minimum_required(VERSION 3.22)

# uncomment to make cmake output verbose
#set(CMAKE_VERBOSE_MAKEFILE ON)

# skip compiler test for cross compilation
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# set compiler path and executable extension
set(CMAKE_ASM_COMPILER "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_C_COMPILER   "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_EXECUTABLE_SUFFIX_ASM .elf)
set(CMAKE_EXECUTABLE_SUFFIX_C   .elf)

project(
    test
    LANGUAGES C ASM
)

file(
    GLOB SRC
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Source/system_stm32l4xx.c
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Source/gcc/startup_stm32l4xx.c
    ${CMAKE_CURRENT_LIST_DIR}/User/common/source/cortex_m4_crt0.S
    ${CMAKE_CURRENT_LIST_DIR}/User/common/source/*.c
    ${CMAKE_CURRENT_LIST_DIR}/User/demo_2/source/*.c
    ${CMAKE_CURRENT_LIST_DIR}/User/main.c
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include/m-profile
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/User/common/include
    ${CMAKE_CURRENT_LIST_DIR}/User/demo_2/include
)

target_compile_definitions(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    STM32L476xx
)

target_compile_options(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mthumb
    -O0                         # no optimization
    -g3                         # maximum debugging information
    -Wall                       # enable all warnings
    -Wno-missing-attributes     # disable warning about missing attributes
    -ffunction-sections         # place each function in its own named section in the output object file
    -fdata-sections             # place each data in its own named section in the output object file
)

target_link_options(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mthumb
    -nostartfiles               # use custom crt0 (otherwise newlib's crt0.S will be used)
    --specs=nano.specs          # use libc_nano.a (otherwise libc.a will be used)
    --specs=nosys.specs         # use libnosys.a
    -Wl,--gc-sections           # enable garbage collection of unused sections
    -Wl,--trace                 # prints name of input files (use --verbose for more detailed information)
    -Wl,--print-memory-usage
    -T "${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Config/stm32l4xx_gcc.ld"
)
