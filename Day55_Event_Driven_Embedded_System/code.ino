#include <Servo.h>
#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
#define BUTTON_PIN 4
Servo fan;
bool darkEvent = false;
bool motionEvent = false;
bool buttonEvent = false;
bool systemMode = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  fan.attach(SERVO_PIN);
}

void loop() {
  detectEvents();
  handleDarkEvent();
  handleMotionEvent();
  handleButtonEvent();
}

void detectEvents() {
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  darkEvent = (light < 400);
  motionEvent = (motion == HIGH);
  buttonEvent = (digitalRead(BUTTON_PIN) == LOW);
}

void handleDarkEvent() {
  if (darkEvent) {
    digitalWrite(LED_PIN, HIGH);
    fan.write(120);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
    fan.write(0);
  }
}

void handleMotionEvent() {
  if (motionEvent && darkEvent) {
    digitalWrite(BUZZER_PIN, HIGH);
  } 
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void handleButtonEvent() {
  if (buttonEvent) {
    systemMode = !systemMode;
    Serial.println(systemMode ? "SMART MODE" : "NORMAL MODE");
    delay(300);
  }
}
