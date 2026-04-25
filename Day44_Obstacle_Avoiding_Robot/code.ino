#include <Servo.h>
#define trigPin 9
#define echoPin 10
#define ledPin 7
#define buzzer 8
Servo leftMotor;
Servo rightMotor;

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  leftMotor.attach(5);
  rightMotor.attach(6);
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 20) {
    leftMotor.write(90);
    rightMotor.write(90);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Moving Forward");
  }

  else {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Obstacle Detected!");
    leftMotor.write(0);
    rightMotor.write(0);
    delay(500);
    leftMotor.write(90);
    rightMotor.write(0);
    delay(1000);
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
