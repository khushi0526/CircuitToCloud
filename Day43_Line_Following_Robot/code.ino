#include <Servo.h>
#define pirLeft 2
#define pirRight 3
#define ledPin 7
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  pinMode(pirLeft, INPUT);
  pinMode(pirRight, INPUT);
  pinMode(ledPin, OUTPUT);
  servo1.attach(5);
  servo2.attach(6);
}

void loop() {
  int left = digitalRead(pirLeft);
  int right = digitalRead(pirRight);
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" Right: ");
  Serial.println(right);

  if (left == HIGH && right == LOW) {
    servo1.write(45);
    servo2.write(45);
    digitalWrite(ledPin, HIGH);
    Serial.println("Turning Left");
  }

  else if (left == LOW && right == HIGH) {
    servo1.write(135);
    servo2.write(135);
    digitalWrite(ledPin, HIGH);
    Serial.println("Turning Right");
  }

  else if (left == HIGH && right == HIGH) {
    servo1.write(90);
    servo2.write(90);
    digitalWrite(ledPin, HIGH);
    Serial.println("STOP - Motion Both Sides");
  }

  else {
    servo1.write(90);
    servo2.write(90);
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion");
  }

  delay(1000);
}
