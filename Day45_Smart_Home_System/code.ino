#include <Servo.h>
#define ledPin 7
#define buzzer 6
#define pirPin 2
#define ldrPin A0
Servo fan;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pirPin, INPUT);
  fan.attach(5);   
}

void loop() {
  int light = analogRead(ldrPin);
  if (light < 400) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Light ON (Dark)");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Light OFF");
  }
  if (light < 400) {
    fan.write(180);  
    Serial.println("Fan ON");
  } else {
    fan.write(0);   
    Serial.println("Fan OFF");
  }
  int motion = digitalRead(pirPin);
  if (motion == HIGH) {
    digitalWrite(buzzer, HIGH);
    Serial.println("Motion Detected!");
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
