#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

int ledPin = 2; // built-in LED (ESP32)

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_BT"); // Bluetooth name

  pinMode(ledPin, OUTPUT);

  Serial.println("Bluetooth Started! Connect to ESP32_BT");
}

void loop() {

  if (SerialBT.available()) {

    char data = SerialBT.read();

    Serial.print("Received: ");
    Serial.println(data);

    if (data == '1') {
      digitalWrite(ledPin, HIGH);
      SerialBT.println("LED ON");
    }

    else if (data == '0') {
      digitalWrite(ledPin, LOW);
      SerialBT.println("LED OFF");
    }
  }
}
