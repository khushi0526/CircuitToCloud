# Smart Street Lighting System

## Objective
To design and simulate an intelligent street lighting system that automatically adjusts brightness based on ambient light and motion detection, improving energy efficiency.

## Components Used
- Arduino UNO
- Potentiometer (simulating LDR - Light Sensor)
- PIR Sensor (Motion Detection)
- LED (Street Light)
- Resistor
- Jumper wires

## Concept
This project demonstrates an automated lighting system using sensor inputs. It uses ambient light sensing to detect day/night conditions and motion detection to adjust brightness accordingly. This is a key concept used in smart city infrastructure for energy conservation.

## Working Principle
1. The potentiometer simulates ambient light intensity.
2. Arduino reads the light value using analog input.
3. A PIR sensor detects motion (vehicle/person).
4. The system operates as follows:
   - Daytime → Street light remains OFF
   - Night + No Motion → Light glows dimly
   - Night + Motion → Light glows at full brightness
5. LED brightness is controlled using PWM (analog output).

## Control Logic

| Condition | Action |
|----------|--------|
| Daytime (High Light) | Light OFF |
| Night + No Motion | Dim Light |
| Night + Motion | Full Brightness |

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460366794602921985

## Sample Output
```
Light: 800 → Day → Light OFF
Light: 300 | Motion: 0 → Night → Dim Light
Light: 300 | Motion: 1 → Night → Full Brightness
```

## Applications
- Smart street lighting systems
- Energy-efficient lighting solutions
- Smart city infrastructure
- Parking lot lighting systems
- Security and surveillance lighting

## Skills Learned
- Sensor automation (light + motion)
- PWM-based brightness control
- Embedded decision-making logic
- Multi-sensor integration
- Energy-efficient system design

## Highlights
- Automatic brightness adjustment based on environment
- Combines LDR and PIR sensor for intelligent control
- Demonstrates real-world smart city application
- Reduces energy consumption using automation
