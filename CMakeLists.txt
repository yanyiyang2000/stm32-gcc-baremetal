cmake_minimum_required(VERSION 3.22)

# Uncomment to make cmake output verbose
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Skip compiler test for cross compilation
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Set compiler path
set(CMAKE_ASM_COMPILER "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_C_COMPILER   "/usr/bin/arm-none-eabi-gcc")

# Set executable extension
set(CMAKE_EXECUTABLE_SUFFIX_ASM .elf)
set(CMAKE_EXECUTABLE_SUFFIX_C   .elf)

# Set C standard
# set(CMAKE_CXX_STANDARD 20)

project(
    test
    LANGUAGES C ASM
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/User
)
