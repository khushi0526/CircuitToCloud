# Day32 - Smart Data Logger with Alert System

## Objective
To design an embedded system that logs environmental data and triggers alerts when abnormal conditions are detected.

## Platform
- Wokwi Simulation
- Arduino UNO

## Components Used
- DHT22 Sensor
- LED
- Buzzer
- Jumper wires

## Concept
This project simulates an industrial monitoring system that continuously logs sensor data and triggers alerts based on predefined thresholds.

## Working Principle
1. Sensor reads temperature and humidity
2. Data is continuously logged to Serial Monitor
3. System checks for abnormal conditions
4. If threshold exceeded → alert triggered
5. Otherwise → system remains normal

## Sample Output
```
Temp: 36 °C | Humidity: 60 %
⚠️ ALERT: Critical Condition!
```

## Simulation Link
https://wokwi.com/projects/461204529622670337

## Applications
- Industrial monitoring systems
- Environmental safety systems
- Server room monitoring
- Cold storage monitoring

## Skills Learned
- Data logging
- Embedded monitoring systems
- Threshold-based alerts
- Sensor integration
