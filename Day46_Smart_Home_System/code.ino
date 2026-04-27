#include <Servo.h>
#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
#define MODE_BTN 4
Servo fan;
bool autoMode = true;
bool lastBtnState = HIGH;
bool ledState = false;
bool fanState = false;
int lightThreshold = 400;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MODE_BTN, INPUT_PULLUP);
  fan.attach(SERVO_PIN);
}

void loop() {
  handleModeSwitch();
  if (autoMode) {
    runAutoMode();
  } 
  else {
    runManualMode();
  }
  delay(200);
}
void handleModeSwitch() {
  bool current = digitalRead(MODE_BTN);
  if (current == LOW && lastBtnState == HIGH) {
    autoMode = !autoMode;
    Serial.println(autoMode ? "AUTO MODE" : "MANUAL MODE");
    delay(300);
  }
  lastBtnState = current;
}
void runAutoMode() {
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  digitalWrite(LED_PIN, light < lightThreshold);
  int angle = map(light, 0, 1023, 180, 0);
  fan.write(angle);
  digitalWrite(BUZZER_PIN, motion);

  Serial.println("AUTO RUNNING");
}
void runManualMode() {
  if (digitalRead(MODE_BTN) == LOW) {
    ledState = !ledState;
    fanState = !fanState;
    digitalWrite(LED_PIN, ledState);
    fan.write(fanState ? 120 : 0);
    Serial.println("MANUAL TOGGLE");
    delay(300);
  }
  digitalWrite(BUZZER_PIN, LOW);
}
