# Day34 - Event-Driven Smart Lighting System

## Objective
To design a smart lighting system that turns ON only when it is dark and motion is detected.

## Platform
- Wokwi Simulation
- Arduino UNO

## Components Used
- PIR Sensor
- Potentiometer (simulated LDR)
- LED
- Jumper wires

## Concept
This project demonstrates event-driven embedded systems using interrupts. The system reacts only when motion is detected and checks environmental light conditions before turning ON the light.

## Working Principle
1. PIR sensor detects motion (interrupt triggered)
2. Light sensor checks environment brightness
3. If dark and motion detected → LED ON
4. Otherwise → LED OFF

## Sample Output
```
Light: 300
Light ON (Dark + Motion)
```
## Simulatio Link
https://wokwi.com/projects/461285855741913089

## Applications
- Smart street lighting
- Home automation
- Energy-saving systems
- Security lighting

## Skills Learned
- Interrupt handling
- Event-driven programming
- Sensor fusion
- Embedded system optimization
