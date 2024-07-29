add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_common
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_1
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_2
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_3
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_4
)

# add more demo directory here

add_executable(
    firmware
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Source/system_stm32l4xx.c
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Source/gcc/startup_stm32l4xx.c
    ${CMAKE_CURRENT_LIST_DIR}/demo_common/source/crt0.S
    main.c
)

target_include_directories(
    firmware
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/demo_common/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_1/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_2/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_3/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_4/include
    # add more demo includes here
)

target_link_directories(
    firmware
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/demo_common
    ${CMAKE_CURRENT_LIST_DIR}/demo_1
    ${CMAKE_CURRENT_LIST_DIR}/demo_2
    ${CMAKE_CURRENT_LIST_DIR}/demo_3
    ${CMAKE_CURRENT_LIST_DIR}/demo_4
    # add more demo libraries here
)

target_link_libraries(
    firmware
    PUBLIC
    demo_common
    demo_2  # change this entry to the directory of the demo being used
)
