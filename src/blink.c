#include <avr/io.h>
#include <util/delay.h>
#include "hc_sr04.h"

#define ECHO_PIN    PB2
#define TRIG_PIN    PB1
#define OUT_PIN     PB0

/**
 * Calculate the distance using the time it took the wave to come back.
 */
float get_distance_cm(u16 ticks) {
    // Convert the CPU ticks to microseconds (us).
    float duration_us = ticks * 0.0625;

    if (duration_us == HC_SR04_TIMEOUT) return -1.0;

    // Convert the duration to centimetres,
    float distance = (duration_us * 0.0343) / 2;
    if (distance < 2.0 || distance > 400.0) return -1.0;

    return distance;
}

int main(void) {
    DDRB |= (1 << TRIG_PIN);
    DDRB |= (1 << OUT_PIN);
    DDRB &= ~(1 << ECHO_PIN);

    HCSR04_Sensor sensor;
    hcsr04_init(&sensor, TRIG_PIN, ECHO_PIN);

    while (1) {
        hcsr04_trigger(&sensor);
        u16 ticks = hcsr04_duration(&sensor);
        float distance = get_distance_cm(ticks);

        if (distance > 0 && distance < 30) {
            PORTB |= (1 << OUT_PIN);
        } else {
            PORTB &= ~(1 << OUT_PIN);
        }

        _delay_ms(100);
    }
}