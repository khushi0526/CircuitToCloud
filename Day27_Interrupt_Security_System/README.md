# Interrupt-Based Security System

## Objective
To design a real-time security system that detects intrusion using interrupts and triggers an alert mechanism.

## Platform Used
- Wokwi Simulation
- Arduino UNO

## Components Used
- PIR Sensor (motion detection)
- LED (alert indicator)
- Buzzer (alarm)
- Push Button (reset system)
- Jumper wires

## Concept
This project demonstrates interrupt-driven embedded systems. Instead of continuously checking sensor values, the system responds instantly when motion is detected using hardware interrupts.

## Working Principle
1. PIR sensor detects motion.
2. An interrupt is triggered immediately.
3. The system activates LED and buzzer.
4. Alert continues until reset button is pressed.
5. Reset button turns off the alert system.

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460821343181843457

## Sample Output
```
🚨 INTRUDER DETECTED!
System Reset
```

## Applications
- Home security systems
- Intrusion detection systems
- Industrial safety systems
- Smart surveillance systems

## Skills Learned
- Interrupt handling
- ISR (Interrupt Service Routine)
- Real-time system design
- Embedded security systems

## Highlights
- Instant response using interrupts
- No continuous polling required
- Efficient real-time alert system
- Practical security application
