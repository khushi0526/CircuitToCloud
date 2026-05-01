#include <Servo.h>
#define LED_PIN 7
Servo fan;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  fan.attach(5);
  Serial.println("Enter Command:");
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    handleCommand(data);
  }
}
void handleCommand(char cmd) {
  switch (cmd) {
    case '1':
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
      break;
    case '0':
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
      break;
    case '2':
      fan.write(120);
      Serial.println("FAN ON");
      break;
    case '3':
      fan.write(0);
      Serial.println("FAN OFF");
      break;
    default:
      Serial.println("Invalid Command");
  }
}
