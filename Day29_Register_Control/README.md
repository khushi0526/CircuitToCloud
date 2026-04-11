# Day29 - Low Level Register Control

## Objective
Control LEDs using AVR registers directly instead of Arduino functions.

## Components
- Arduino UNO
- 3 LEDs
- 3 Resistors

## Connections
- LED1 → Pin 2
- LED2 → Pin 3
- LED3 → Pin 4

## Registers Used

### DDRD
Used to configure pin direction.

```cpp
DDRD |= (1 << PD2);
```

### PORTD
Used to set pin HIGH or LOW.

```cpp
PORTD |= (1 << PD2);    // ON
PORTD &= ~(1 << PD2);   // OFF
```

## Output
LED1, LED2, LED3 blink one after another.

## Skills Learned
- Register programming
- Bitwise operators
- Microcontroller internals
- Faster embedded control

  ## Simulation Link
https://wokwi.com/projects/461011347838195713
