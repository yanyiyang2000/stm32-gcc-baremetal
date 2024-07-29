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

target_link_directories(
    demo_1
    PUBLIC
    ${PROJECT_SOURCE_DIR}/User/demo_common
)

target_link_libraries(
    demo_1
    demo_common
)
