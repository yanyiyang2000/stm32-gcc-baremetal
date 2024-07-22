add_library(
    demo_1
    OBJECT # force interrupt service routine to be included
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_1_gpio_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_1_isr.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_1_enter.c
)

target_include_directories(
    demo_1
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${PROJECT_SOURCE_DIR}/User/demo_common/include
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(
    demo_1
    PUBLIC
    STM32L476xx
)

target_compile_options(
    demo_1
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

target_link_directories(
    demo_1
    PUBLIC
    ${PROJECT_SOURCE_DIR}/User/demo_common
)

target_link_libraries(
    demo_1
    demo_common
)
