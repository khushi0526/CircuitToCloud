# Bluetooth Data Transmission System (ESP32)

## Objective
To design a wireless communication system using ESP32 Bluetooth to send and receive data between a mobile device and a microcontroller.

## Components Used
- ESP32
- LED (optional)
- Jumper wires

## Concept
Bluetooth communication in ESP32 works similar to serial (UART) communication but without wires. It allows data exchange between devices using radio signals.

The ESP32 acts as a Bluetooth device that can:
- Receive data from a mobile phone
- Process commands
- Control hardware (like LED)

## Working Principle
1. ESP32 initializes Bluetooth with a device name.
2. A mobile device connects to ESP32 via Bluetooth.
3. User sends commands (e.g., '1' or '0') from mobile.
4. ESP32 receives data using BluetoothSerial.
5. Based on input:
   - '1' → LED turns ON
   - '0' → LED turns OFF
6. ESP32 can also send responses back to the mobile.

## Code Structure
- Uses `BluetoothSerial.h` library
- `SerialBT.begin("ESP32_BT")` initializes Bluetooth
- `SerialBT.read()` receives data
- `SerialBT.println()` sends response

## Output (Expected)
Mobile App:
```
Send: 1 → LED ON
Send: 0 → LED OFF
```

Serial Monitor:
```
Received: 1
LED ON

Received: 0
LED OFF
```

## ⚠️ Simulation Note (Important)

This project does **NOT work correctly in Wokwi simulation**.

### Reason:
- Wokwi currently does not fully support ESP32 Bluetooth functionality.
- The `BluetoothSerial` library depends on ESP32's internal Bluetooth hardware.
- In simulation, this hardware is not properly emulated.
- This causes:
  - Watchdog timer errors
  - Guru Meditation errors
  - ESP32 crashes

## ✅ Workaround in Wokwi

To demonstrate the concept in simulation:
- Bluetooth communication is replaced with Serial Monitor input.
- This simulates how commands are sent and received.

## ✅ Real Hardware Implementation

This project works perfectly on a **real ESP32 board**.

### Requirements:
- ESP32 board
- Mobile phone
- Bluetooth terminal app (e.g., Serial Bluetooth Terminal)

### Steps:
1. Upload the Bluetooth code to ESP32.
2. Turn ON Bluetooth on your phone.
3. Connect to device named: `ESP32_BT`
4. Send:
   - `1` → LED ON
   - `0` → LED OFF

## Applications
- Home automation systems
- Wireless control of devices
- Robotics control
- Smart appliances
- IoT-based wireless systems

## Skills Learned
- Bluetooth communication
- Wireless data transmission
- Serial communication (UART concept)
- Embedded system control
- Debugging hardware vs simulation issues

## Conclusion
This project demonstrates wireless communication using ESP32 Bluetooth. While simulation tools may have limitations, the concept and implementation are fully functional on real hardware, making it a valuable embedded systems project.
