#include "../include/led_driver.hpp"

LED::LED(uint8_t pin, volatile uint8_t* port, volatile uint8_t* ddr) 
: pin_mask(1 << pin), port(port), ddr(ddr) {
    if (!port || !ddr) return;
    *ddr |= pin_mask;
    turn_off();
}

void LED::turn_on() {
    *port |= pin_mask;
}

void LED::turn_off() {
    *port &= ~pin_mask;
}

void LED::toggle() {
    *port ^= pin_mask;
}

uint8_t LED::getCurrentState() {
    return *port & pin_mask;
}