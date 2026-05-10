#include <Servo.h>
#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
Servo fan;
unsigned long prevLED = 0;
unsigned long prevFan = 0;
unsigned long prevSecurity = 0;
unsigned long prevDebug = 0;
int ledInterval = 500;
int fanInterval = 300;
int securityInterval = 200;
int debugInterval = 1000;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  fan.attach(SERVO_PIN);
}

void loop() {

  unsigned long currentTime = millis();
  taskLighting(currentTime);
  taskFan(currentTime);
  taskSecurity(currentTime);
  taskDebug(currentTime);
}

void taskLighting(unsigned long now) {
  if (now - prevLED >= ledInterval) {
    prevLED = now;
    int light = analogRead(LDR_PIN);
    ledState = (light < 500);
    digitalWrite(LED_PIN, ledState);
  }
}
void taskFan(unsigned long now) {
  if (now - prevFan >= fanInterval) {
    prevFan = now;
    int light = analogRead(LDR_PIN);
    int angle = map(light, 0, 1023, 180, 0);
    fan.write(angle);
  }
}
void taskSecurity(unsigned long now) {
  if (now - prevSecurity >= securityInterval) {
    prevSecurity = now;
    int motion = digitalRead(PIR_PIN);
    digitalWrite(BUZZER_PIN, motion);
  }
}

void taskDebug(unsigned long now) {
  if (now - prevDebug >= debugInterval) {
    prevDebug = now;
    Serial.println("Scheduler Running");
  }
}
