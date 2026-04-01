#include <Servo.h>
Servo fanServo;
Servo doorServo;
char data;
void setup() {
  pinMode(5, OUTPUT);   // Light
  pinMode(6, OUTPUT);   // Buzzer
  fanServo.attach(9);   // Fan
  doorServo.attach(10); // Door
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    data = Serial.read();
    if (data == '1') {
      digitalWrite(5, HIGH);
      Serial.println("Light ON");
    }
    else if (data == '0') {
      digitalWrite(5, LOW);
      Serial.println("Light OFF");
    }
    else if (data == '2') {
      fanServo.write(0);
      Serial.println("Fan OFF");
    }
    else if (data == '3') {
      fanServo.write(90);
      Serial.println("Fan MEDIUM");
    }
    else if (data == '4') {
      fanServo.write(180);
      Serial.println("Fan FULL");
    }
    else if (data == '5') {
      doorServo.write(0);
      Serial.println("Door CLOSED");
    }
    else if (data == '6') {
      doorServo.write(90);
      Serial.println("Door OPEN");
    }
    else if (data == '7') {
      digitalWrite(6, HIGH);
      Serial.println("Buzzer ON");
    }
    else if (data == '8') {
      digitalWrite(6, LOW);
      Serial.println("Buzzer OFF");
    }
  }
}
