# ⚡ Smart Energy Monitoring System

## 📌 Project Overview
The **Smart Energy Monitoring System** is an embedded system designed to monitor electrical signal levels and detect high energy consumption conditions.

The system uses an Arduino Uno to read analog voltage signals from a potentiometer and convert them into digital values using the built-in Analog-to-Digital Converter (ADC).

When the signal level exceeds a predefined threshold, an LED turns ON to indicate high energy usage. This project demonstrates fundamental embedded systems concepts such as analog sensing, signal processing, and threshold-based control.

---

## 🎯 Objective
To monitor electrical signal levels and detect conditions where energy usage exceeds a predefined limit.

---

## 🧠 Concept
The Arduino Uno contains a **10-bit ADC (Analog-to-Digital Converter)** that converts analog voltage signals into digital values ranging from **0 to 1023**.

The potentiometer simulates varying electrical signals representing different energy consumption levels.

The Arduino continuously reads these signals and compares them with a predefined threshold value. If the signal exceeds the threshold, the LED turns ON to indicate high energy usage.

---

## 🧰 Components Used
- Arduino Uno  
- Potentiometer  
- LED  
- 220Ω Resistor  
- Breadboard  
- Jumper Wires  

---

## ⚙️ Working Principle
1. The potentiometer generates a variable analog voltage signal.  
2. The Arduino reads the analog voltage through an analog input pin.  
3. The internal ADC converts the analog signal into a digital value (0–1023).  
4. The program compares the value with a predefined threshold level.  
5. If the signal value exceeds the threshold:
   - The LED turns ON indicating **high energy usage**.
6. If the signal value is below the threshold:
   - The LED remains OFF.

---

## 🔌 System Flow
```
Analog Signal → Arduino ADC → Threshold Comparison → LED Indicator
```

---

## 🌍 Applications
- Smart Home Energy Monitoring  
- Industrial Energy Monitoring  
- Energy Management Systems  
- Embedded Systems Learning Projects  

---

## 🖥️ Simulation
You can run the project simulation online using Wokwi.

Simulation Link:  
(https://wokwi.com/projects/457995032782307329)

---

## 📚 Skills Demonstrated
- Embedded Systems Programming  
- Analog Signal Processing  
- ADC (Analog-to-Digital Conversion)  
- Hardware Interfacing  
- Threshold-Based System Design  

