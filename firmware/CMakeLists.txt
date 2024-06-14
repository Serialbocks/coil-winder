FILE(GLOB MyCSources *.c)
ADD_EXECUTABLE(firmware ${MyCSources})

pico_generate_pio_header(firmware ${CMAKE_CURRENT_LIST_DIR}/quadrature_encoder.pio)

# pull in common dependencies and additional i2c hardware support
target_link_libraries(firmware pico_stdlib pico_multicore hardware_i2c hardware_pio)

# create map/bin/hex file etc.
pico_add_extra_outputs(firmware)

# add url via pico_set_program_url
example_auto_set_url(firmware)
