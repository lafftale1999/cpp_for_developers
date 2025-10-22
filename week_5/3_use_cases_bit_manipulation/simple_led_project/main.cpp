
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// GLOBALS
#define LED_PIN PB5

int main(void) {

    // SETUP
    DDRB |= (1 << LED_PIN);
    PORTB &= ~(1 << LED_PIN);

    // SUPER LOOP
    while(1) {
        PORTB ^= (1 << LED_PIN);
        _delay_ms(500);
    }

    return 0;
}




// wokwi project link: https://wokwi.com/projects/445516715245466625