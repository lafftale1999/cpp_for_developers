#ifndef BUTTON_DRIVER_HPP_
#define BUTTON_DRIVER_HPP_

#include <stdint.h>
#include <avr/io.h>

#include "../include/millis.h"

#define BUTTON_DEBOUNCE_MS      200
#define BUTTON_PIN              PB4
#define BUTTON_PORT             PORTB
#define BUTTON_DDR              DDRB
#define BUTTON_PIN_REG          PINB
#define BUTTON_PIN_MASK_REG     PCMSK0
#define BUTTON_INT_BIT          PCIE0

class Button {
private:
    uint8_t pin_mask;
    volatile uint8_t* port;
    volatile uint8_t* ddr;
    volatile uint8_t* pin_reg;
    volatile uint8_t pressed;

    void button_init(uint8_t pull_up);
public:
    Button(
        uint8_t pin,
        volatile uint8_t* port,
        volatile uint8_t* ddr,
        volatile uint8_t* pin_reg,
        uint8_t pull_up
    );

    void was_pressed();
    uint8_t key_pressed();
};

#endif