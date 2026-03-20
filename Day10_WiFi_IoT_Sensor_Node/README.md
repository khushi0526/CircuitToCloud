# WiFi IoT Sensor Node (Temperature & Humidity Monitoring)

## Objective
To design an IoT-based system that reads temperature and humidity data from a sensor and sends it to a cloud platform for remote monitoring.

---

## Components Used
- Arduino UNO (Simulation)
- DHT22 Sensor
- ESP32 (for real hardware implementation)
- Jumper wires

---

## Concept
This project demonstrates the foundation of an IoT system where sensor data is collected, processed, and transmitted for monitoring.

Basic Flow:
Sensor → Microcontroller → Data Output / Cloud

In real IoT systems:
Sensor → ESP32 → WiFi → Cloud Platform → User Dashboard

---

## Working Principle (Simulation - Wokwi)

1. DHT22 sensor reads temperature and humidity.
2. Arduino UNO processes the sensor data.
3. Data is displayed on the Serial Monitor.
4. This simulates how data would be sent to a cloud in a real IoT system.

---

## Output (Simulation)

Serial Monitor:
```
Temperature: 28.5 °C | Humidity: 60 %
Temperature: 29.1 °C | Humidity: 58 %
```

---

## ⚠️ Simulation Limitation (Important)

This project cannot be fully implemented using ESP32 WiFi in Wokwi in some cases.

### Reason:
- WiFi/cloud communication may not work properly depending on configuration.
- Real-time cloud integration requires actual network hardware.
- Some features like API communication may fail or behave inconsistently.

---

## ✅ Workaround in Wokwi

- Sensor data is displayed using Serial Monitor.
- This simulates the IoT data flow without using actual internet communication.

---

## ✅ Real-Time Implementation (ESP32 + WiFi)

This project works fully using a real ESP32 board.

### Requirements:
- ESP32 board
- Internet (WiFi)
- ThingSpeak account (or any IoT cloud platform)

---

## Steps to Implement in Real Hardware

1. Connect DHT22 to ESP32:
   - VCC → 3.3V
   - GND → GND
   - DATA → GPIO 15

2. Create a ThingSpeak account:
   - Create a new channel
   - Add fields:
     - Field 1 → Temperature
     - Field 2 → Humidity

3. Copy your Write API Key.

4. Update the ESP32 code:
   - Add WiFi credentials
   - Add ThingSpeak API key

5. Upload code to ESP32.

6. Open Serial Monitor:
   - Check WiFi connection status
   - Observe sensor readings

7. Open ThingSpeak dashboard:
   - View real-time graphs of temperature and humidity

---

## Applications
- Smart home monitoring systems
- Weather monitoring stations
- Smart agriculture systems
- Industrial environment monitoring
- IoT-based automation systems

---

## Skills Learned
- Sensor interfacing (DHT22)
- Data acquisition and monitoring
- IoT system architecture
- Understanding simulation vs real hardware limitations
- Embedded system design

---

## Conclusion
This project builds a strong foundation for IoT systems by demonstrating how sensor data is collected and processed. While simulation tools have limitations, the same system can be fully implemented in real hardware using ESP32 and cloud platforms.
