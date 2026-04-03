# IoT Industrial Machine Monitoring System

## Objective
To design and simulate a system that monitors industrial machine conditions such as temperature and vibration, and provides alerts when abnormal conditions are detected.

## Components Used
- Arduino UNO
- DHT22 Temperature Sensor
- Push Button (simulating vibration sensor)
- LED (Alert indicator)
- Buzzer (Alarm system)
- Jumper wires

## Concept
This project demonstrates Industrial IoT (IIoT) by continuously monitoring machine parameters. It uses sensor data to detect abnormal conditions and trigger alerts, similar to real-world predictive maintenance systems used in industries.

## Working Principle
1. The DHT22 sensor measures machine temperature.
2. A push button simulates vibration detection.
3. Arduino continuously reads sensor values.
4. If:
   - Temperature exceeds threshold OR
   - Vibration is detected  
   → The system triggers an alert.
5. LED and buzzer indicate abnormal machine condition.
6. Serial Monitor displays real-time machine status.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460305348992778241

## Sample Output
```
Temp: 30°C | Vibration: 0 → Machine Normal
Temp: 40°C | Vibration: 0 → ALERT: High Temperature
Temp: 30°C | Vibration: 1 → ALERT: Vibration Detected
```

## Applications
- Industrial machine monitoring
- Predictive maintenance systems
- Factory automation
- Equipment safety monitoring
- Smart manufacturing systems

## Skills Learned
- Sensor integration (temperature & digital input)
- Industrial IoT concepts
- Real-time monitoring systems
- Fault detection and alert mechanisms
- Embedded system programming

## Highlights
- Detects abnormal machine conditions in real-time
- Simulates predictive maintenance system
- Combines multiple sensor inputs for decision making
- Implements alert system using LED and buzzer
