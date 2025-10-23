#include "include/led_driver.hpp"
#include "include/button_driver.hpp"
#include <util/delay.h>
#include <avr/interrupt.h>

// GLOBALS
// -------

int main(void) {

    // SET UP
    millis_init();
    LED green(5, &PORTB, &DDRB);
    Button button(BUTTON_PIN, &BUTTON_PORT, &BUTTON_DDR, &BUTTON_PIN_REG, 0);
    sei();

    // SUPER LOOP
    while(1) {
        if (button.key_pressed()) {
            green.toggle();
        }

        _delay_ms(50);
    }

    return 0;
}