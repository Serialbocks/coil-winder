FILE(GLOB MyCSources *.c)
ADD_EXECUTABLE(firmware ${MyCSources})


# pull in common dependencies and additional i2c hardware support
target_link_libraries(firmware pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(firmware)

# add url via pico_set_program_url
example_auto_set_url(firmware)
