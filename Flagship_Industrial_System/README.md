# Smart Industrial Monitoring & Control System

## Objective
To design a complete embedded system for monitoring industrial parameters and controlling devices based on real-time conditions.

## Platform
- Wokwi Simulation (Arduino UNO)
- Future Upgrade: ESP32 + IoT Dashboard

## Components Used
- DHT22 Temperature Sensor
- PIR Motion Sensor
- Potentiometer (Energy Simulation)
- LED (Alert)
- Buzzer
- Fan (simulated using PWM)
- Jumper wires

## Features
- Real-time monitoring of temperature, energy, and motion
- Alert system for abnormal conditions
- Automatic fan control based on temperature
- Continuous data logging via Serial Monitor

## Working Principle
1. Sensors collect environmental and system data
2. Arduino processes data in real-time
3. If thresholds are exceeded:
   - Alert is triggered (LED + Buzzer)
4. Fan is automatically controlled based on temperature
5. Data is continuously logged for monitoring

## Sample Output
```
Temp: 36 | Energy: 750 | Motion: 1
🚨 ALERT: Industrial Condition Critical
Fan ON (Cooling)
```

## Simulation Link
https://wokwi.com/projects/461287823683658753

## Applications
- Industrial machine monitoring
- Smart factory systems
- Predictive maintenance
- Safety monitoring systems

## Skills Learned
- Multi-sensor integration
- Embedded system design
- Data processing and logging
- Automation and control systems
- Industrial IoT concepts

## Folder Structure
```
Flagship_Industrial_System
│
├── code.ino
├── circuit.png
└── README.md
```
