# Smart Parking Detection System

## About the Project

This project is a simple smart parking prototype built using ESP32 and an ultrasonic sensor.
The goal of the system is to detect whether a parking slot is free or occupied by measuring the distance between the sensor and an object.

When a vehicle enters the parking slot, the distance detected by the ultrasonic sensor becomes smaller. The ESP32 reads this distance and decides whether the parking slot is occupied or available.

A red LED indicates that the parking space is occupied, while a green LED shows that the slot is free.

---

## Objective

To design a simple embedded system that can detect parking availability using distance measurement.

---

## Components Used

* ESP32
* HC-SR04 Ultrasonic Sensor
* Red LED
* Green LED
* 220Ω Resistors
* Jumper wires

---

## How It Works

The ultrasonic sensor sends ultrasonic sound waves and waits for the echo signal to return after hitting an object.

Using the time taken for the echo to return, the Arduino calculates the distance between the sensor and the object.

If the distance is below a defined threshold, the system considers the parking slot occupied and turns on the red LED. Otherwise, the green LED turns on to indicate that the parking slot is available.

---

## Simulation

You can try the simulation here:

[Open Wokwi Simulation](https://wokwi.com/projects/458131328286747649)

---

## Applications

* Smart parking systems in malls or offices
* Parking assistance systems
* Smart city infrastructure
* Basic IoT parking monitoring

---

## Author

Khushi
