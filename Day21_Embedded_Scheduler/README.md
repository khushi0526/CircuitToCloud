# Embedded Operating System Scheduler

## Objective
To design a simple task scheduler that executes multiple tasks at fixed time intervals, simulating basic RTOS behavior.

## Components Used
- Arduino UNO
- 3 LEDs
- Resistors
- Jumper wires

## Concept
This project demonstrates a basic embedded scheduler using non-blocking programming. It uses time-based execution to simulate how real-time operating systems manage multiple tasks efficiently.

## Working Principle
1. The system tracks time using millis().
2. Each task is assigned a time interval.
3. The scheduler continuously checks if a task is ready.
4. If the time condition is met, the task executes.
5. Multiple tasks run without blocking each other.

## Tasks

| Task | Interval |
|------|----------|
| Task 1 | 1 second |
| Task 2 | 2 seconds |
| Task 3 | 3 seconds |

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460443685943905281

## Output
Task execution messages are displayed on Serial Monitor and LEDs toggle based on task execution.

## Applications
- Embedded operating systems
- Real-time control systems
- Automotive ECUs
- Industrial automation

## Skills Learned
- Real-time system design
- Task scheduling
- Non-blocking programming
- Time-based execution using millis()

## Highlights
- Simulates RTOS-like behavior
- Executes multiple tasks concurrently
- Efficient CPU usage without delay()
