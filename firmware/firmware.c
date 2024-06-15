/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "pico/binary_info.h"

#include "lcd.h"
#include "quadrature_encoder.pio.h"

int main() {
    int new_value, old_value, display_value = 0, old_display_value = 0;
    char message[MAX_CHARS];

    // Base pin to connect the A phase of the encoder.
    // The B phase must be connected to the next pin
    const uint PIN_AB = 10;

    stdio_init_all();

    lcd_init();
    PIO pio = pio0;
    const uint sm = 0;

    // we don't really need to keep the offset, as this program must be loaded
    // at offset 0
    pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, sm, PIN_AB, 2);

    snprintf(message, MAX_CHARS, "val: %d", display_value);
    lcd_clear();
    lcd_write_line(0, message);

    while (1) {
        new_value = quadrature_encoder_get_count(pio, sm);
        old_value = new_value;
        display_value = -(old_value / 2);
        if(display_value != old_display_value) {
            snprintf(message, MAX_CHARS, "val: %d", display_value);
            lcd_clear();
            lcd_write_line(0, message);
        }
        old_display_value = display_value;
        sleep_ms(10);
        
    }

}
