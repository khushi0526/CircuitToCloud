# Day31 - Password-Based Access Control System

## Objective
To design a secure access control system using keypad input and password verification.

## Platform
- Wokwi Simulation
- Arduino UNO

## Components Used
- 4x4 Keypad
- LED
- Buzzer
- Jumper wires

## Concept
This project demonstrates embedded security using a password-based authentication system. It uses a finite state machine approach for processing input and making decisions.

## Working Principle
1. User enters password via keypad
2. Input is stored and processed
3. Press '#' to verify
4. If correct → access granted (LED ON)
5. If incorrect → access denied (buzzer ON)
6. '*' resets input

## Sample Output
```
Access Granted
```
## Simulation Link
https://wokwi.com/projects/461120394410852353

## Applications
- Door lock systems
- ATM machines
- Security systems
- Access control systems

## Skills Learned
- Embedded security systems
- Keypad interfacing
- State machine logic
- Input processing

## Folder Structure
```
Day31_Access_Control
│
├── code.ino
├── circuit.png
└── README.md
```
