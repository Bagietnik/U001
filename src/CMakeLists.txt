cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "/home/bagieta/Desktop/picosdk/")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(my_project)

pico_sdk_init()

add_executable(main
    main.c
)

target_link_libraries(main pico_stdlib hardware_watchdog hardware_uart hardware_clocks hardware_gpio)

pico_add_extra_outputs(main)