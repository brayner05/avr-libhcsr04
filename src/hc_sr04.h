#ifndef HC_SR04_H
#define HC_SR04_H

#ifndef HC_SR04_TIMEOUT
#define HC_SR04_TIMEOUT 0
#endif

#include <stdint.h>

typedef uint16_t u16;

/**
 * A compound data type representing an HC-SR04 sensor.
 * Keeps track of the TRIG and ECHO pins.
 */
typedef struct HCSR04_Sensor {
    u16 pin_trig;
    u16 pin_echo;
} HCSR04_Sensor;


/**
 * Initialize an HC-SR04 sensor with the Echo and Trig pins, and
 * by default, set TRIG to off/LOW.
 */
extern void hcsr04_init(HCSR04_Sensor *sensor, u16 pin_trig, u16 pin_echo);

/**
 * Sets `trigger_pin` to HIGH for 10us and then sets it back to LOW,
 * triggering a pulse from the sensor.
 */
extern void hcsr04_trigger(HCSR04_Sensor *sensor);

/**
 * Time how long it takes for the ultrasonic wave to return to the sensor,
 */
extern u16 hcsr04_duration(HCSR04_Sensor *sensor);

#endif