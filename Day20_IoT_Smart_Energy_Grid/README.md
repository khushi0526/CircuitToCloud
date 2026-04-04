# IoT Smart Energy Grid Monitor

## Objective
To design and simulate a system that monitors energy consumption across multiple devices and identifies high energy usage conditions.

## Components Used
- Arduino UNO
- 3 Potentiometers (simulating energy usage of devices)
- 3 LEDs (device indicators)
- Resistors
- Jumper wires

## Concept
This project demonstrates how energy consumption can be monitored across multiple devices in a smart grid system. It simulates real-time energy tracking and analysis using embedded systems, which is a fundamental concept in IoT-based energy management.

## Working Principle
1. Each potentiometer simulates energy consumption of a device.
2. Arduino reads analog values from all devices.
3. The values are displayed on the Serial Monitor.
4. LEDs indicate whether devices are active.
5. If any device exceeds the threshold, a warning is generated.
6. The system continuously monitors all devices in real-time.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460378339491966977

## Sample Output
```
---- Energy Monitoring ----
Device 1: 350
Device 2: 820
Device 3: 200
⚠️ High Energy Consumption Detected!
----------------------------
```

## Applications
- Smart energy grid systems
- Home energy monitoring
- Industrial power management
- Energy efficiency analysis
- IoT-based energy tracking

## Skills Learned
- Analog data acquisition
- Multi-device monitoring
- Embedded data processing
- IoT system design concepts
- Threshold-based analytics

## Highlights
- Monitors multiple devices simultaneously
- Detects high energy consumption
- Simulates real-world smart grid system
- Implements basic IoT analytics using embedded systems
