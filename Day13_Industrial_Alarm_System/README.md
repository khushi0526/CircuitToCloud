# Automatic Industrial Alarm System

## Objective
To design a real-time monitoring system that detects abnormal sensor values and triggers an alarm using a buzzer and LED.

---

## Components Used
- Arduino UNO
- Potentiometer (Sensor Simulation)
- Buzzer
- LED
- Resistor (220Ω)
- Jumper wires

---

## Concept
This project demonstrates a **threshold-based embedded monitoring system**.

Basic Flow:
Sensor → Arduino → Threshold Detection → Alarm System

The system continuously reads sensor values and compares them with a predefined threshold. If the value exceeds the limit, an alert is triggered.

---

## Working Principle

1. The potentiometer simulates a sensor by generating variable voltage.
2. Arduino reads this analog value using ADC (0–1023).
3. The value is compared with a threshold (e.g., 600).
4. If the value exceeds the threshold:
   - Buzzer turns ON
   - LED turns ON
5. If the value is below threshold:
   - System remains in safe state (no alert)

---

## Circuit Connections

### Potentiometer

| Pin | Arduino |
|-----|--------|
| Left | 5V |
| Right | GND |
| Middle | A0 |

---

### Buzzer

| Pin | Arduino |
|-----|--------|
| Positive | Pin 8 |
| Negative | GND |

---

### LED

| Pin | Arduino |
|-----|--------|
| Positive | Pin 7 |
| Negative | GND (via resistor) |

---

## Output

### Serial Monitor:
```
Sensor Value: 350
Sensor Value: 720
```

### System Behavior:

| Sensor Value | Status |
|-------------|--------|
| < 600       | Safe (No alarm) |
| > 600       | Alarm ON (LED + Buzzer) |

---

## Simulation (Wokwi)

- Rotate the potentiometer to change sensor value.
- When value crosses threshold, alarm is triggered.
- Add your simulation link below:

👉 Simulation Link: https://wokwi.com/projects/459210544705712129

---

## Applications
- Industrial machine safety monitoring
- Fire and heat detection systems
- Gas leakage detection
- Smart home alert systems
- Environmental monitoring

---

## Skills Learned
- Analog sensor interfacing
- ADC (Analog to Digital Conversion)
- Threshold-based decision making
- Embedded alert systems
- Real-time monitoring

---

## Advantages
- Simple and cost-effective
- Real-time alert mechanism
- Easy to expand with multiple sensors
- Reliable for safety applications

---

## Limitations
- Uses simulated sensor (potentiometer)
- Fixed threshold value
- No remote alert system

---

## Future Improvements
- Integrate IoT for remote alerts (SMS/App)
- Add multiple sensors (temperature, gas, smoke)
- Adjustable threshold using buttons or interface
- Data logging for analysis

---

## Conclusion
This project demonstrates a fundamental industrial safety system using embedded logic. It highlights how real-time monitoring and threshold detection can be used to prevent hazardous situations in practical environments.
