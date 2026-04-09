# Smart Fan Controller (Advanced Embedded System)

## Objective
To design an intelligent fan control system that automatically adjusts speed based on temperature and allows manual override using interrupts.

## Platform Used
- Wokwi Simulation
- Arduino UNO

## Components Used
- DHT22 Temperature Sensor
- LED (simulating fan)
- Push Button (manual control)
- Resistor
- Jumper wires

## Concept
This project demonstrates advanced embedded system concepts such as PWM control and interrupt handling. The system automatically controls fan speed based on temperature and allows real-time switching to manual mode using an interrupt.

## Working Principle
1. Temperature is measured using DHT22 sensor.
2. In automatic mode:
   - High temperature → High fan speed
   - Medium temperature → Medium speed
   - Low temperature → Fan OFF
3. A push button is used to trigger an interrupt.
4. When pressed, the system switches to manual mode.
5. In manual mode, fan runs at fixed speed.
6. Press again to return to automatic mode.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460819651048258561

## Sample Output
```
Temperature: 32 → Auto Mode: High Speed
Temperature: 26 → Auto Mode: Medium Speed
Button Pressed → Manual Mode: Fan ON
```

## Applications
- Smart cooling systems
- Temperature-based automation
- Industrial fan control
- HVAC systems

## Skills Learned
- Interrupt handling
- PWM-based speed control
- Real-time embedded systems
- Sensor-based automation

## Highlights
- Uses interrupt for instant response
- Implements automatic + manual control
- Demonstrates real-time embedded behavior
README.md
