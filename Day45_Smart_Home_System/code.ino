#include <Servo.h>

#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0

Servo fan;

// thresholds
int lightThreshold = 400;

// states
bool lightState = false;
bool motionState = false;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  fan.attach(SERVO_PIN);
}

void loop() {

  int lightValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  handleLighting(lightValue);
  handleFan(lightValue);
  handleSecurity(motion);

  debugPrint(lightValue, motion);

  delay(200);
}

// 💡 LIGHT SYSTEM
void handleLighting(int lightValue) {

  if (lightValue < lightThreshold) {
    lightState = true;
    digitalWrite(LED_PIN, HIGH);
  } else {
    lightState = false;
    digitalWrite(LED_PIN, LOW);
  }
}

// 🌀 FAN SYSTEM (SMOOTH CONTROL)
void handleFan(int lightValue) {

  int angle = map(lightValue, 0, 1023, 180, 0);
  fan.write(angle);
}

// 🚨 SECURITY SYSTEM
void handleSecurity(int motion) {

  if (motion == HIGH) {
    motionState = true;
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    motionState = false;
    digitalWrite(BUZZER_PIN, LOW);
  }
}

// 📊 DEBUG (CLEAN OUTPUT)
void debugPrint(int lightValue, int motion) {

  Serial.print("Light: ");
  Serial.print(lightValue);

  Serial.print(" | LED: ");
  Serial.print(lightState ? "ON" : "OFF");

  Serial.print(" | Motion: ");
  Serial.print(motion);

  Serial.print(" | Alarm: ");
  Serial.println(motionState ? "ON" : "OFF");
}
