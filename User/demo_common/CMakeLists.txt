add_library(
    demo_common
    OBJECT # force interrupt service routine to be included
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_common_clock_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_common_gpio_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_common_uart_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_common_isr.c
    ${CMAKE_CURRENT_LIST_DIR}/source/syscalls.c
)

target_include_directories(
    demo_common
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(
    demo_common
    PUBLIC
    STM32L476xx
)

target_compile_options(
    demo_common
    PUBLIC
    -mthumb
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -O0                         # no optimization
    -g3                         # maximum debugging information
    -Wall                       # enable all warnings
    -Wno-missing-attributes     # disable warning about missing attributes
    -ffunction-sections         # place each function in its own named section in the output object file
    -fdata-sections             # place each data in its own named section in the output object file
)
