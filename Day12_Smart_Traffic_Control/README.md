# Smart Traffic Density Control System (RGB LED Based)

## Objective
To design an intelligent traffic light system that adjusts signal timing based on vehicle density using an ultrasonic sensor.

---

## Components Used
- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- RGB LED (Common Cathode)
- Resistors (220Ω recommended)
- Jumper wires

---

## Concept
This project demonstrates an **adaptive traffic control system** using embedded decision-making.

Basic Flow:
Sensor → Arduino → Decision Logic → Traffic Light Control

The ultrasonic sensor measures the distance of vehicles:
- Short distance → High traffic density
- Long distance → Low traffic density

Based on this, the system dynamically controls the traffic light duration.

---

## Working Principle

1. Ultrasonic sensor measures distance using sound waves.
2. Arduino calculates distance using echo time.
3. Based on distance:
   - High density → Longer green signal
   - Medium density → Medium signal
   - Low density → Red signal
4. RGB LED represents traffic light states.

---

## RGB LED Mapping (Modified)

| Color | Meaning |
|------|--------|
| 🔴 Red | Stop (Low traffic) |
| 🔵 Blue | Medium traffic |
| 🟢 Green | High traffic (Go) |

> Note: Blue is used instead of Yellow for better visibility and simplicity in simulation.

---

## Circuit Connections

### Ultrasonic Sensor

| Pin | Arduino |
|-----|--------|
| VCC | 5V |
| GND | GND |
| TRIG | Pin 2 |
| ECHO | Pin 3 |

---

### RGB LED (Common Cathode)

| Pin | Arduino |
|-----|--------|
| Red | Pin 7 |
| Green | Pin 6 |
| Blue | Pin 5 |
| Common | GND |

---

## Output

Simulation link (https://wokwi.com/projects/459113680652046337)
### Serial Monitor:
```
Distance: 15
Distance: 35
Distance: 60
```

### LED Behavior:

| Distance | LED Color |
|---------|----------|
| < 20 cm | Green |
| 20–50 cm | Blue |
| > 50 cm | Red |

---

## Simulation (Wokwi)

- Adjust object distance in the ultrasonic sensor settings.
- Observe LED color changes based on traffic density.

---

## Applications
- Smart city traffic systems
- Automated signal control
- Vehicle density monitoring
- IoT-based traffic management

---

## Skills Learned
- Embedded decision-making
- Sensor interfacing (HC-SR04)
- RGB LED control
- Real-time system design
- Condition-based automation

---

## Advantages
- Reduces traffic congestion
- Efficient signal timing
- Low-cost implementation
- Scalable for multi-lane systems

---

## Limitations
- Single-lane simulation
- Uses distance instead of actual vehicle counting
- Yellow signal replaced with Blue for simulation simplicity

---

## Future Improvements
- Multi-lane traffic control system
- IoT integration for remote monitoring
- Camera-based vehicle detection
- AI-based traffic prediction

---

## Conclusion
This project demonstrates how embedded systems can be used to design intelligent traffic control solutions. It showcases real-time decision-making using sensor data and highlights the foundation of smart city technologies.
