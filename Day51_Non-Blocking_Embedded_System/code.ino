#include <Servo.h>
#define LED_PIN 7
#define SERVO_PIN 5
Servo fan;
unsigned long prevTime = 0;
int interval = 1000;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  fan.attach(SERVO_PIN);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - prevTime >= interval) {
    prevTime = currentTime;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    fan.write(ledState ? 120 : 0);
  }
}
