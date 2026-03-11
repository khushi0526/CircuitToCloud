# Smart Water Tank Monitoring System

## About the Project

This project is a simple water level monitoring system built using Arduino and an ultrasonic sensor. The system measures the distance between the sensor and the water surface inside a tank to estimate the current water level.

Based on the measured distance, the Arduino determines whether the tank is **Full, Medium, or Low** and displays the tank status on the Serial Monitor. When the water level becomes too low, an LED alert is activated.

This project demonstrates how sensors and microcontrollers can be used to monitor real-world systems such as household water tanks.

---

## Objective

The objective of this project is to monitor the water level in a tank and notify the user when the water level becomes low.

---

## Components Used

* Arduino UNO
* HC-SR04 Ultrasonic Sensor
* LED (Low water alert)
* 220Ω Resistor
* Jumper wires

---

## How It Works

The ultrasonic sensor is placed at the top of the tank. It sends ultrasonic sound waves toward the water surface and waits for the echo signal to return.

The Arduino calculates the distance between the sensor and the water surface using the time taken for the echo signal.

Based on the calculated distance:

* **Small distance → Tank Full**
* **Medium distance → Tank Medium**
* **Large distance → Tank Low**

The tank status is displayed in the Serial Monitor, and an LED turns ON when the water level becomes too low.

---

## Simulation

You can try the simulation here:

https://wokwi.com/projects/458206760644017153

---



## Applications

* Household water tank monitoring
* Smart home automation systems
* Industrial water level monitoring
* IoT-based water management systems

---
