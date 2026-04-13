# Day33 - Multi-Node Sensor Communication System

## Objective
To simulate communication between multiple sensor nodes by packaging, transmitting, and parsing data.

## Platform
- Wokwi Simulation
- Arduino UNO

## Components Used
- DHT22 Sensor
- Potentiometer
- Jumper wires

## Concept
This project demonstrates how multiple sensors send structured data as a packet, which is then parsed and processed by a receiver system.

## Working Principle
1. Sensor data is collected from multiple sources
2. Data is formatted into a structured packet
3. Packet is transmitted via serial communication
4. Receiver parses the data
5. System makes decisions based on parsed values

## Data Format
```
T:Temperature,A:AnalogValue
```

## Sample Output
```
T:32.5,A:720
Parsed Temp: 32.5 | Parsed Analog: 720
⚠️ ALERT: Node Condition Critical
```

## Simulation Link
https://wokwi.com/projects/461205864696152065

  
## Applications
- Industrial IoT systems
- Distributed sensor networks
- Smart monitoring systems
- Embedded communication systems

## Skills Learned
- Data communication
- Data structuring
- Parsing techniques
- Embedded system architecture
