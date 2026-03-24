# Embedded PID Temperature Controller

## Objective
Maintain a constant temperature automatically using PID control.

## Components
- Arduino Uno
- DHT22 temperature sensor
- Servo motor (simulate fan/heater)
- Jumper wires
- Optional LCD display

## Concept
PID control uses Proportional, Integral, and Derivative terms to minimize error and maintain temperature at the desired setpoint.

## Working
1. Read temperature from sensor
2. Calculate error = setpoint - measured temp
3. Compute PID output
4. Adjust fan or heater accordingly
5. Repeat continuously

## Simulation
Simulate this project on Wokwi using Arduino, DHT22, and servo. Observe temperature readings and PWM control.
https://wokwi.com/projects/459387916541748225

## Applications
- Industrial furnace controllers
- HVAC systems
- Food processing systems
- Robotics temperature regulation
- Smart home heating/cooling systems

## Skills Learned
- PID control implementation
- Sensor integration
- PWM actuator control
- Embedded programming
