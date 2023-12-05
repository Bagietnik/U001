cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "/home/bagieta/Desktop/picosdk/")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

set(FREERTOS_CFG_DIRECTORY "/home/bagieta/Desktop/U001/Config")
set(FREERTOS_SRC_DIRECTORY "/home/bagieta/Desktop/U001/FreeRTOS-Kernel")

add_library(FreeRTOS STATIC
    ${FREERTOS_SRC_DIRECTORY}/event_groups.c
    ${FREERTOS_SRC_DIRECTORY}/list.c
    ${FREERTOS_SRC_DIRECTORY}/queue.c
    ${FREERTOS_SRC_DIRECTORY}/stream_buffer.c
    ${FREERTOS_SRC_DIRECTORY}/tasks.c
    ${FREERTOS_SRC_DIRECTORY}/timers.c
    ${FREERTOS_SRC_DIRECTORY}/portable/MemMang/heap_3.c
    ${FREERTOS_SRC_DIRECTORY}/portable/GCC/ARM_CM0/port.c
)

target_include_directories(FreeRTOS PUBLIC
    ${FREERTOS_CFG_DIRECTORY}/
    ${FREERTOS_SRC_DIRECTORY}/include
    ${FREERTOS_SRC_DIRECTORY}/portable/GCC/ARM_CM0
)

project(my_project)

pico_sdk_init()

add_executable(main
    main.c
)

target_link_libraries(main pico_stdlib hardware_watchdog hardware_uart hardware_clocks hardware_gpio FreeRTOS)

pico_add_extra_outputs(main)