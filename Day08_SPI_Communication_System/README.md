# SPI Communication System (Master-Slave)

## Objective
To demonstrate high-speed communication between two Arduino boards using the SPI (Serial Peripheral Interface) protocol in a master-slave configuration.

## Components Used
- 2 × Arduino Uno
- Jumper Wires

## Concept
SPI (Serial Peripheral Interface) is a synchronous communication protocol used in embedded systems for fast data transfer between devices.

It uses four main lines:
- MOSI (Master Out Slave In)
- MISO (Master In Slave Out)
- SCK (Serial Clock)
- SS (Slave Select)

The master device controls communication by generating the clock and selecting the slave device.

## Working Principle
1. The master Arduino initiates communication by pulling the SS pin LOW.
2. Data is sent from the master to the slave using the MOSI line.
3. The clock signal (SCK) synchronizes the data transfer.
4. The slave receives the data and stores it in the SPI data register.
5. An interrupt is triggered on the slave side when data is received.
6. The slave reads the data and displays it on the Serial Monitor.
7. Communication ends when the master sets SS HIGH.

## Code Structure
- `master.ino` → Sends data using SPI
- `slave.ino` → Receives data using SPI interrupt

## Output
Master Serial Monitor:
```
Data Sent: A
```

Slave Serial Monitor:
```
Received: A
```

## Applications
- Communication with sensors (IMU, ADC, temperature sensors)
- SD card interfacing
- OLED and TFT display communication
- Industrial embedded systems
- High-speed data transfer between microcontrollers

## Skills Learned
- SPI protocol fundamentals
- Master-slave communication
- Interrupt handling in embedded systems
- Low-level register control (SPDR, SPCR)
- Hardware interfacing

## Note
SPI communication between two Arduino boards may not work correctly in some simulators like Tinkercad due to hardware limitations.

This project demonstrates the SPI concept and can be fully tested using real hardware or advanced simulators.

## Conclusion
This project provides a strong foundation in SPI communication, which is widely used in embedded systems for fast and efficient data transfer between devices.
