#include <Servo.h>
#define trigPin 9
#define echoPin 10
#define ldrPin A0
#define ledPin 7
#define buzzerPin 6
Servo brakeServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  brakeServo.attach(5);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  int lightValue = analogRead(ldrPin);
  if (lightValue < 400) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Headlight ON");
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
  if (distance < 20) {
    digitalWrite(buzzerPin, HIGH);
    brakeServo.write(90);  
    Serial.println("Obstacle! Braking...");
  }
  else {
    digitalWrite(buzzerPin, LOW);
    brakeServo.write(0);  
  }

  delay(500);
}
