cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(main)

pico_sdk_init()

add_executable(main
        pong.c 
        debounce_sw1.c 
        debounce_sw2.c 
        timer.c 
        sw_in.c 
        led_out.c
        )

# pull in common dependencies
target_link_libraries(main pico_stdlib pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(main)