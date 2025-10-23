
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// wokwi project link: https://wokwi.com/projects/445516715245466625

// GLOBALS
#define LED_PIN     PB5
#define BUTTON_PIN    PB4

int main(void) {

    // SETUP
    DDRB |= (1 << LED_PIN);
    PORTB &= ~(1 << LED_PIN);

    DDRB &= ~(1 << BUTTON_PIN);
    PORTB &= ~(1 << BUTTON_PIN);

    // SUPER LOOP
    while(1) {
        
        if (PINB & (1 << BUTTON_PIN)) {
            PORTB |= (1 << LED_PIN);
        } else {
            PORTB &= ~(1 << LED_PIN);
        }

        _delay_ms(5);
    }

    return 0;
}