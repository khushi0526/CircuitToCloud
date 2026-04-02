# Smart Agriculture Monitoring System

## Objective
To design and simulate an automated irrigation system that monitors soil moisture and controls water supply accordingly.

## Components Used
- Arduino UNO
- Potentiometer (simulating soil moisture sensor)
- LED (simulating water pump)
- Resistor
- Jumper wires

## Concept
This project is based on sensor-driven automation. The soil moisture level is continuously monitored, and based on the moisture value, the system decides whether irrigation is required. It demonstrates how embedded systems can be used in smart agriculture for efficient water management.

## Working Principle
1. The potentiometer simulates soil moisture levels.
2. Arduino reads analog values from the sensor.
3. The value is compared with a predefined threshold.
4. If moisture is low (dry soil), the system turns ON the pump.
5. If moisture is high (wet soil), the system turns OFF the pump.
6. The system continuously monitors and updates in real-time.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460213653788258305

## Sample Output
```
Moisture Value: 320 → Soil Dry → Pump ON
Moisture Value: 750 → Soil Wet → Pump OFF
```

## Applications
- Smart irrigation systems
- Water conservation in agriculture
- Greenhouse automation
- Precision farming
- IoT-based farming solutions

## Skills Learned
- Analog sensor interfacing
- Embedded automation logic
- Threshold-based decision making
- Real-time monitoring systems

## Highlights
- Automatic irrigation control based on soil condition
- Efficient water usage system
- Real-world agriculture problem solution using embedded systems

## Folder Structure
```
Day17_Smart_Agriculture_Monitoring
│
├── code.ino
├── circuit.png
└── README.md
```
