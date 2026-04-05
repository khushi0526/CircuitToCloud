# Custom Device Driver Development

## Objective
To design a custom device driver for a sensor module and demonstrate hardware abstraction in embedded systems.

## Components Used
- Arduino UNO
- Potentiometer (simulated sensor)
- LED
- Resistor
- Jumper wires

## Concept
This project demonstrates how device drivers are used to interact with hardware. A separate driver layer is created to handle sensor operations, while the application layer uses this driver to perform logic.

## Working Principle
1. A custom driver is created with functions:
   - sensor_init()
   - sensor_read()
2. The application code uses these functions instead of directly accessing hardware.
3. The sensor value is read and compared with a threshold.
4. If the value is high, LED turns ON.
5. If the value is normal, LED remains OFF.

## Architecture
Application Layer → Device Driver → Hardware

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460447823764702209

## Sample Output
```
Sensor Value: 300 → Normal
Sensor Value: 800 → High Value Detected
```

## Applications
- Embedded device drivers
- Sensor abstraction systems
- Industrial embedded systems
- Hardware interface development

## Skills Learned
- Low-level programming
- Hardware abstraction
- Modular code design
- Device driver development
- Embedded system architecture

## Highlights
- Implements custom driver functions
- Separates hardware and application logic
- Demonstrates real embedded system design pattern
