# Embedded File System for Data Storage

## Objective
To design a system that logs sensor data with timestamps, simulating file storage in embedded systems.

## Components Used
- Arduino UNO
- Potentiometer (simulated sensor)
- Jumper wires

## Concept
This project demonstrates data logging in embedded systems. Sensor data is continuously recorded along with timestamps, simulating how data is stored in files on SD cards in real systems.

## Working Principle
1. The sensor generates analog data.
2. Arduino reads the sensor value.
3. Each reading is logged along with time (millis).
4. The log is printed in a structured format.
5. This simulates file storage in embedded systems.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460533494657295361

## Sample Output
```
LOG: Sensor Value = 200 | Time = 1000
LOG: Sensor Value = 500 | Time = 2000
LOG: Sensor Value = 800 | Time = 3000
```

## Applications
- Data logging systems
- Industrial monitoring
- IoT data collection
- Environmental monitoring systems

## Skills Learned
- Data logging techniques
- Timestamp-based recording
- Embedded system data handling
- File system concepts
- Serial data formatting

## Highlights
- Simulates file storage using serial output
- Logs real-time sensor data
- Uses timestamps for tracking
- Demonstrates embedded data management concepts
