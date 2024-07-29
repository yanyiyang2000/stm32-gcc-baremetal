add_library(
    demo_2
    OBJECT # force interrupt service routine to be included
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_dac_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_dma_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_gpio_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_timer_config.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_isr.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_util.c
    ${CMAKE_CURRENT_LIST_DIR}/source/demo_2_enter.c
)

target_include_directories(
    demo_2
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${PROJECT_SOURCE_DIR}/User/demo_common/include
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_directories(
    demo_2
    PUBLIC
    ${PROJECT_SOURCE_DIR}/User/demo_common
)

target_link_libraries(
    demo_2
    demo_common
)
