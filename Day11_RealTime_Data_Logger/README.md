# Real-Time Data Logger – Arduino SD Card Project

## Objective
To continuously read sensor data (temperature & humidity) and log it to an SD card for later analysis. This is a fundamental project for monitoring systems and industrial IoT applications.

---

## Components Used
- Arduino UNO / Arduino Mega
- DHT22 sensor (or any analog/digital sensor)
- SD Card Module
- SD card (real hardware) / virtual SD (Wokwi)
- Jumper wires

---

## Concept
This project demonstrates **real-time data logging**:

```text
Sensor → Microcontroller → Storage (SD card) → Analysis
```

Core points:
- Read sensor at intervals
- Save data in structured format (CSV)
- Retrieve or display logged data

---

## Circuit Connections

### DHT22 Sensor

| DHT22 | Arduino |
|-------|--------|
| VCC   | 5V     |
| GND   | GND    |
| DATA  | Pin 2  |

### SD Card Module

| SD Module | Arduino |
|-----------|--------|
| VCC       | 5V     |
| GND       | GND    |
| MISO/DO   | 12     |
| MOSI/DI   | 11     |
| SCK       | 13     |
| CS/DS     | 10     |
| CD        | Leave unconnected in Wokwi |

---

## ⚠️ Simulation Limitation in Wokwi

https://wokwi.com/projects/459100747845526529

If you see:

```
SD card failed!
Error opening file!
```

### Reasons:
1. **No virtual SD card added** in Wokwi simulation.
2. **Incorrect CS pin** connection (must match code).
3. SD card detection (CD) is optional; Wokwi ignores it.

### Workaround in Wokwi:
- Add SD Card module from Wokwi components.
- Attach a virtual file named `datalog.csv`.
- Make sure **CS pin = 10** (or match your code).
- Then simulation will log data successfully.

---

## ✅ Real Hardware Implementation

In real life with **Arduino + SD Card Module + Sensor**:

1. Connect DHT22 sensor and SD module to Arduino as above.
2. Insert SD card into the module.
3. Upload the data logger code to Arduino.
4. Open Serial Monitor → check data logging status.
5. SD card stores the sensor readings in `datalog.csv`.
6. Remove SD card and open in Excel / Notepad / Python for analysis.

---

## Output

**Serial Monitor Example:**
```
SD card initialized.
Data logged.
Data logged.
...
```

**SD Card File (`datalog.csv`):**
```
Temperature: 28.5, Humidity: 60
Temperature: 28.7, Humidity: 61
```

---

## Skills Learned
- Sensor interfacing (DHT22)
- SD Card module & file handling
- Real-time data logging
- Serial debugging
- Data analysis preparation

---

## Applications
- Industrial monitoring systems
- Weather stations
- Smart agriculture monitoring
- IoT data acquisition
- Environmental monitoring

---
