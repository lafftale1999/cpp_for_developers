# Embedded Exercises for AVR ATMega328p
You can use wokwi for all of these exercises. Each exercise will either contain a link to a project you can use or encourage you to create your own.

> **NOTE:** If you need a guide for running a program in wokwi or how to create a new sketch: [Use this link](wokwi_guide.md)

## 1. Getting started
First we need to get familiar with how we upload our programs to wokwi:
1. Use this guide to understand how you upload a project: [wokwi_guide.md](wokwi_guide.md)
2. Download this .hex-file: https://drive.google.com/file/d/1J55hJkRvq13mgTq0UG6hni31FN5hQ3LG/view?usp=drive_link  
3. Run it in this wokwi sketch: https://wokwi.com/projects/445516715245466625

## 2. Blink an LED
Create a program that turns an LED on and off using this sketch https://wokwi.com/projects/445516715245466625.

Remember to use the Port representation of the pin and not their offical D*Number*.

> Note: the button will not affect your program in any way.

## 3. Control the LED with the Button
Create a program that turns controls the LED by lighting it when you push the button. The sketch provided is using a `pull-down resistor`, so when you push the button - the logical signal will be 1. This makes it very important to disable the internal pull-up resistor.

Use this sketch: https://wokwi.com/projects/445516715245466625

## 4. Create drivers
Building on what we've learned so far, we are now gonna create drivers. Create two classes which holds the following functionality:

### led_driver
* `led_driver()` - contructor that initializes the led.
* `turn_on()`
* `turn_off()`
* `toggle()`

### button_driver
* `button_driver()` - constructor that initalizes the button.
* `is_pressed()` - returning the true or false

Now use these drivers in [Exercise 3](#3-control-the-led-with-the-button).

## 5. Toggling the LED
Use the drivers from earlier exercises to build a program where you toggle a LED on and off using the button.

Remember to implement a debounce logic where you let the signal stabilize for 100 - 200ms. This means that when the button is pressed, it will not register another high signal for the debounce time.

## 6. Traffic Lights
Use the drivers from the program before and this sketch: https://wokwi.com/projects/445631470875471873

Create a program that:
* Green LED is lighted as standard.
* When the button is pressed:
    1. Wait 5 seconds
    2. Turn off the green LED and turn on the yellow LED
    3. Wait 2 seconds
    5. Turn off the yellow LED and turn on the red LED
    6. Wait 10 seconds
    7. Turn off the red LED and turn on the yellow LED
    8. Wait 2 seconds
    9. Turn off the yellow LED and turn on the green LED.

Remember to debounce the button and that a button press should NOT interrupt the sequence started by the button press!

## 7. STRETCH GOALS
1. Implement an Interrupt Service Routine for the button instead of polling it.
2. Add an HC-SR04 Ultrasonic Sensor to the traffic lights which triggers the sequence instead of the button.