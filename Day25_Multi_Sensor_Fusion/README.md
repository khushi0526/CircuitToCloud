# Multi-Sensor Fusion System

## Objective
To design a system that combines data from multiple sensors to make intelligent decisions.

## Components Used
- Arduino UNO
- DHT22 Temperature Sensor
- Potentiometer (simulated light sensor)
- PIR Sensor (motion detection)
- LED
- Resistor
- Jumper wires

## Concept
This project demonstrates sensor fusion by combining inputs from multiple sensors to improve decision-making accuracy. Instead of relying on a single sensor, multiple parameters are analyzed together.

## Working Principle
1. Temperature, light, and motion data are collected.
2. Arduino processes all sensor inputs.
3. A decision is made based on combined conditions:
   - High temperature
   - Low light
   - Motion detected
4. If all conditions are satisfied, an alert is triggered.
5. Otherwise, the system remains in normal state.

## Fusion Logic
IF (Temperature > Threshold AND Light < Threshold AND Motion Detected) → ALERT

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460637279723411457

## Sample Output
```
Temp: 32 | Light: 300 | Motion: 1
⚠️ ALERT: Condition Matched
```

## Applications
- Smart surveillance systems
- Industrial safety monitoring
- Smart home automation
- Robotics and AI systems

## Skills Learned
- Multi-sensor integration
- Sensor fusion techniques
- Embedded data processing
- Intelligent decision-making systems

## Highlights
- Combines multiple sensor inputs
- Improves system accuracy and reliability
- Demonstrates real-world embedded intelligence
- Implements condition-based decision logic
