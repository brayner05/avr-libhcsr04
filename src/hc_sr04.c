#include <avr/io.h>
#include <util/delay.h>
#include "hc_sr04.h"

extern void hcsr04_init(HCSR04_Sensor *sensor, u16 pin_trig, u16 pin_echo) {
    // The MCU pins used for the sensor's Trig, and Echo pins.
    sensor->pin_trig = pin_trig;
    sensor->pin_echo = pin_echo;

    // Set the TRIG pin to off as an initial value.
    PORTB |= (1 << pin_trig);
}

extern void hcsr04_trigger(HCSR04_Sensor *sensor) {
    PORTB |= (1 << sensor->pin_trig);
    _delay_us(10);
    PORTB &= ~(1 << sensor->pin_trig);
}

extern u16 hcsr04_duration(HCSR04_Sensor *sensor) {
    // Wait for the ECHO pin to be HIGH.
    while ((PINB & (1 << sensor->pin_echo)) == 0x00);

    TCNT1 = 0;
    TCCR1B |= (1 << CS10);

    // Wait for the ECHO pin to be LOW.
    while ((PINB & (1 << sensor->pin_echo)) != 0x00);

    TCCR1B = 0;

    return TCNT1;
}