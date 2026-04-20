# Day40 - Mini RTOS Scheduler

## Objective
To simulate a real-time multi-tasking system using non-blocking code.

## Platform
- Wokwi Simulation
- Arduino UNO

## Components Used
- LED (2)
- Buzzer
- Push Button

## Concept
Instead of using delay(), this system uses millis() to schedule multiple tasks independently.

## Tasks
- LED1 toggles every 1 second
- LED2 toggles every 2 seconds
- Buzzer beeps every 3 seconds

## Working Principle
1. System tracks time using millis()
2. Each task runs when its time interval is reached
3. All tasks run independently without blocking

## Simulation Link
https://wokwi.com/projects/461843387089576961

## Applications
- Real-time systems
- Embedded multitasking
- Industrial automation

## Skills Learned
- Non-blocking programming
- Task scheduling
- Embedded RTOS concepts
