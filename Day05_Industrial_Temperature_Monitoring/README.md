# Industrial Temperature Monitoring System

## Objective
To monitor the temperature of machines and detect overheating conditions in industrial environments. The system reads temperature data and triggers an alert if the temperature exceeds a safe limit.

## Components Used
- Arduino UNO  
- DHT22 Temperature and Humidity Sensor  
- LED  
- 220Ω Resistor  
- Jumper Wires  
- Breadboard  

## Concept
Industrial machines generate heat while operating. If the temperature becomes too high, it can damage equipment or reduce performance.

This system continuously monitors temperature using a sensor. The microcontroller reads the sensor data and checks whether the temperature crosses a predefined threshold value. If the temperature becomes too high, a warning indicator is activated.

## Working Principle
The DHT22 sensor measures the temperature of the surrounding environment and sends the data to the Arduino. The Arduino processes this information and displays the temperature on the Serial Monitor.

If the measured temperature exceeds the set threshold value, the LED turns ON to indicate a potential overheating condition.

## Simulation
You can run the simulation using Wokwi:
https://wokwi.com/projects/458301727030510593

## Applications
- Industrial machine temperature monitoring  
- Motor and transformer protection systems  
- Factory automation systems  
- Preventive maintenance systems  
- Smart industrial monitoring solutions  

## Skills Learned
- Sensor integration with microcontrollers  
- Temperature monitoring systems  
- Embedded system programming  
- Hardware interfacing  
- Industrial monitoring concepts
