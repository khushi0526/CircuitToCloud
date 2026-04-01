# Advanced Smart Home Automation System

## Objective
To design and simulate a smart home automation system that can control multiple devices such as lights, fan, door, and alarm using a command-based interface.

## Components Used
- Arduino UNO
- LED (Light)
- Servo Motor (Fan simulation)
- Servo Motor (Door control)
- Buzzer
- Resistors
- Jumper wires

## Concept
This project simulates a smart home system where multiple appliances are controlled through serial commands. It demonstrates embedded control logic and mimics real IoT systems where devices are controlled remotely.

## Working Principle
1. User sends commands through Serial Monitor.
2. Arduino reads the input data.
3. Based on the command:
   - LED (light) is turned ON/OFF
   - Servo motor controls fan speed (0°, 90°, 180°)
   - Servo motor controls door position (open/close)
   - Buzzer acts as an alarm system
4. All devices respond in real-time.

## Control Commands

| Command | Action |
|--------|--------|
| 1 | Light ON |
| 0 | Light OFF |
| 2 | Fan OFF (0°) |
| 3 | Fan MEDIUM (90°) |
| 4 | Fan FULL (180°) |
| 5 | Door CLOSED |
| 6 | Door OPEN |
| 7 | Buzzer ON |
| 8 | Buzzer OFF |

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460079942708418561

## Applications
- Smart home systems
- Home automation solutions
- Remote appliance control
- Security systems
- IoT-based automation projects

## Skills Learned
- Embedded system design
- Serial communication
- Multi-device control
- Servo motor interfacing
- Automation logic development

## Highlights
- Implemented multi-device control in a single system
- Used servo motors for advanced control instead of simple ON/OFF
- Simulated real-world smart home automation logic
