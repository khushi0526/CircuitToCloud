# Secure Embedded Communication System

## Objective
To implement a secure communication system by encrypting and decrypting data using embedded programming techniques.

## Components Used
- Arduino UNO
- Serial Monitor (communication interface)

## Concept
This project demonstrates basic encryption in embedded systems. Data is encrypted before transmission and decrypted at the receiver end, ensuring secure communication.

## Working Principle
1. User inputs data through Serial Monitor.
2. Data is encrypted using XOR operation with a key.
3. Encrypted data is transmitted.
4. Receiver decrypts the data using the same key.
5. Original message is recovered.

## Encryption Method
XOR Encryption:

Encrypted = Data ^ Key  
Decrypted = Encrypted ^ Key  

## Simulation
This project is simulated using Wokwi.

https://wokwi.com/projects/460538426333711361

## Sample Output
```
Input: A
Encrypted Data: *
Decrypted Data: A
```

## Applications
- Secure IoT communication
- Embedded system security
- Wireless data protection
- Industrial automation systems

## Skills Learned
- Encryption techniques
- Embedded communication security
- Data protection methods
- XOR-based encryption logic

## Highlights
- Implements basic encryption and decryption
- Demonstrates secure data transmission
- Uses lightweight encryption suitable for embedded systems
