# Day30 - UART Communication Using Registers

## Objective
Implement UART communication using AVR registers without using Arduino Serial library.

## Platform
- Arduino UNO
- Wokwi Simulation

## Concept
UART (Universal Asynchronous Receiver Transmitter) is used for serial communication. This project directly configures UART registers to send data.

## Registers Used

- UBRR0 → Baud rate control
- UCSR0A → Status register
- UCSR0B → Enable TX
- UCSR0C → Frame format
- UDR0 → Data register

## Working

1. UART initialized at 9600 baud
2. Transmitter enabled
3. Data sent using UDR0 register
4. Characters transmitted one by one

## Output

```
Hello Khushi!
Hello Khushi!
```

## Skills Learned

- UART protocol
- Register-level programming
- Hardware communication
- Embedded firmware development

## Simulation Link

https://wokwi.com/projects/461014918077451265
