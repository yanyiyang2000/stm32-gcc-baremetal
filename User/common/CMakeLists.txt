add_library(
    common
    OBJECT # force interrupt service routine to be included
    ${CMAKE_CURRENT_LIST_DIR}/source/common_clock_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/common_gpio_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/common_uart_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/common_isr.c
    ${CMAKE_CURRENT_LIST_DIR}/source/syscalls.c
)

target_include_directories(
    common
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(
    common
    PUBLIC
    STM32L476xx
)

target_compile_options(
    common
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
