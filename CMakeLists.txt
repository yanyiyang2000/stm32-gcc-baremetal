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

add_compile_definitions(
    STM32L476xx
)

add_compile_options(
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mthumb
    -mfloat-abi=hard
    -O0
    -g3
    -Wall
    # -Wno-implicit-function-declaration
    -ffunction-sections
    -fdata-sections
)

add_link_options(
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mthumb
    -mfloat-abi=hard
    -Wl,--gc-sections
    --specs=nosys.specs
    -T "${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Config/stm32l4xx_gcc.ld"
)

file(
    GLOB SRC
    ${CMAKE_CURRENT_LIST_DIR}/User/source/*.c
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Source/system_stm32l4xx.c
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Source/gcc/startup_stm32l4xx.c
)

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/User/include
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include/m-profile
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include
)

add_executable(${PROJECT_NAME} ${SRC})
