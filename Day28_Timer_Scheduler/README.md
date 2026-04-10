# Timer-Based Task Scheduler

## Objective
To design a hardware timer-based task scheduler using interrupts for executing tasks at fixed intervals.

## Platform Used
- Wokwi Simulation
- Arduino UNO

## Components Used
- 3 LEDs
- Resistors
- Jumper wires

## Concept
This project demonstrates advanced scheduling using hardware timers. Tasks are executed at precise intervals using timer interrupts, simulating real-time operating system behavior.

## Working Principle
1. Timer1 generates interrupt every 1 second.
2. ISR updates task flags based on timing conditions.
3. Main loop checks flags and executes tasks.
4. Multiple tasks run at different intervals.

## Tasks

| Task | Interval |
|------|----------|
| Task 1 | 1 second |
| Task 2 | 2 seconds |
| Task 3 | 3 seconds |

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460924478909127681

## Sample Output
```
Task 1 (1 sec)
Task 2 (2 sec)
Task 3 (3 sec)
```

## Applications
- Real-time systems
- Embedded schedulers
- Industrial automation
- Automotive control systems

## Skills Learned
- Timer interrupts
- Register-level programming
- RTOS concepts
- Task scheduling

## Highlights
- Uses hardware timer instead of delay
- Implements interrupt-driven scheduler
- Demonstrates RTOS-like behavior

## Folder Structure
```
Day28_Timer_Scheduler
│
├── code.ino
├── circuit.png
└── README.md
```
