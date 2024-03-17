add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/common
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_1
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/demo_2
)

# add more demo directory here

add_executable(
    ${CMAKE_PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Source/system_stm32l4xx.c
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Source/gcc/startup_stm32l4xx.c
    ${CMAKE_CURRENT_LIST_DIR}/common/source/cortex_m4_crt0.S
    main.c
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include
    ${PROJECT_SOURCE_DIR}/CMSIS/Core/Include/m-profile
    ${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Include
    ${CMAKE_CURRENT_LIST_DIR}/common/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_1/include
    ${CMAKE_CURRENT_LIST_DIR}/demo_2/include
    # add more demo includes here
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

target_link_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/common
    ${CMAKE_CURRENT_LIST_DIR}/demo_1
    ${CMAKE_CURRENT_LIST_DIR}/demo_2
    # add more demo libraries here
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    common
    demo_2  # change this entry to the directory of the demo being used
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
    -T "${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32L4xx/Config/stm32l4xx_gcc.ld"
)
