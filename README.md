# libhcsr04 (AVR)
libhcsr04 is a lightweight library providing functionality for HC-SR04 ultrasonic sensors using the AVR architecture. It was designed for the ATMega328p with the Arduino UNO, but works for most AVR-architecture MCUs.

## Installation
To install libhcsr04, clone this repository:
```sh
git clone https://github.com/brayner05/avr-libhcsr04.git
```

Next, build the library from source using GNU Make:
```sh
make clean compile
```

If nothing went wrong, `libhscr04.a` will be located in the `lib` directory.

## Basic Usage
```c
// The pins for TRIG and ECHO.
const uint16_t trig_pin = PB1;
const uint16_t echo_pin = PB2;

// Initialize the sensor.
HCSR04_Sensor sensor;
hcsr04_init(&sensor, trig_pin, echo_pin);

// Trigger a sensor pulse.
hcsr04_trigger(&sensor);

// Compute the number of CPU ticks between the pulse and the return of the wave.
uint16_t ticks = hcsr04_duration(&sensor);
```