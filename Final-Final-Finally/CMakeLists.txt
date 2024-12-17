cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(main)

pico_sdk_init()

add_executable(main
    Buttons.c
    Motors.c
    sw_in.c
    main.c
)


target_link_libraries(main  
    pico_stdlib 
    pico_bootsel_via_double_reset
    hardware_gpio hardware_pio 

)

pico_add_extra_outputs(main)
