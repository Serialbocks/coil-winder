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
    int encoder_val_new, encoder_val_old = 0;
    char message[MAX_CHARS];
    uint switch_new, switch_old = 0;
    uint switch_count_new = 0, switch_count_old = 0;

    // Base pin to connect the A phase of the encoder.
    // The B phase must be connected to the next pin
    const uint AB_PIN = 10;
    const uint SWITCH_PIN = 15;

    stdio_init_all();

    lcd_init();
    PIO pio = pio0;
    const uint sm = 0;

    // we don't really need to keep the offset, as this program must be loaded
    // at offset 0
    pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, sm, AB_PIN, 0);

    gpio_init(SWITCH_PIN);
    gpio_set_dir(SWITCH_PIN, GPIO_IN);

    //static char *message[] =
    //{
    //        "Firmware For", "Coil Winder",
    //        "Coil Winder", "by Serialbocks",
    //        "Raspberry Pi", "Pico"
    //};

    snprintf(message, MAX_CHARS, "val: %d", encoder_val_old);
    lcd_clear();
    lcd_write_line(0, message);
    snprintf(message, MAX_CHARS, "switch: %u", switch_old);
    lcd_write_line(1, message);

    while (1) {
        // Encoder Value
        encoder_val_new = quadrature_encoder_get_count(pio, sm);
        
        // Switch Value
        switch_new = gpio_get(SWITCH_PIN);

        if(switch_new > switch_old) {
            switch_count_new++;
        }
        if(encoder_val_old != encoder_val_new || switch_count_new != switch_count_old) {
            lcd_clear();
            snprintf(message, MAX_CHARS, "val: %d", encoder_val_new);
            lcd_write_line(0, message);
            snprintf(message, MAX_CHARS, "switch: %u", switch_count_new);
            lcd_write_line(1, message);
        }

        encoder_val_old = encoder_val_new;
        switch_old = switch_new;
        switch_count_old = switch_count_new;

        sleep_ms(10);
        
    }

}
