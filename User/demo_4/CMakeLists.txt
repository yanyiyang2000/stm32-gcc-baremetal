add_library(
    demo_4
    OBJECT # force interrupt service routine to be included
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_4_gpio_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_4_usart_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_4_isr.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_4_enter.c
)

target_include_directories(
    demo_4
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${PROJECT_SOURCE_DIR}/User/demo_common/include
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(
    demo_4
    PUBLIC
    STM32L476xx
)

target_compile_options(
    demo_4
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

target_link_directories(
    demo_4
    PUBLIC
    ${PROJECT_SOURCE_DIR}/User/demo_common
)

target_link_libraries(
    demo_4
    demo_common
)
