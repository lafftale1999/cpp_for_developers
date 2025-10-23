#ifndef LED_DRIVER_HPP_
#define LED_DRIVER_HPP_

#include <stdint.h>
#include <avr/io.h>

class LED {
private:
    uint8_t pin_mask;
    volatile uint8_t* port;
    volatile uint8_t* ddr;

public:
    LED(uint8_t pin, volatile uint8_t* port, volatile uint8_t* ddr);
    void turn_on();
    void turn_off();
    void toggle();
    uint8_t getCurrentState();
};

#endif