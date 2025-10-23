#include "../include/button_driver.hpp"
#include <avr/io.h>
#include <avr/interrupt.h>

static Button* current_button = nullptr;
millis_t last_press = 0;

Button::Button(uint8_t pin, volatile uint8_t* port, volatile uint8_t* ddr, volatile uint8_t* pin_reg, uint8_t pull_up = false) 
: pin_mask(1 << pin), port(port), ddr(ddr), pin_reg(pin_reg), pressed(0) {
    if (!(port && ddr && pin_reg)) return;
    current_button = this;
    button_init(pull_up);
}

void Button::button_init(uint8_t pull_up) {
    *ddr &= ~pin_mask;
    if (pull_up) *port |= pin_mask;
    else *port &= ~pin_mask;

    PCICR |= (1 << BUTTON_INT_BIT);
    BUTTON_PIN_MASK_REG |= (1 << BUTTON_PIN);
}

uint8_t Button::key_pressed() {
    uint8_t temp = this->pressed;
    this->pressed = 0;
    return temp;
}

void Button::was_pressed() {
    this->pressed = 1;
}

ISR(PCINT0_vect) {
    millis_t now = millis_get();

    if (current_button && ((now - last_press) > BUTTON_DEBOUNCE_MS)) {
        current_button->was_pressed();
        last_press = now;
    }
}