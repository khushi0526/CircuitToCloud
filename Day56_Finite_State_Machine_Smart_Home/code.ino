#include <Servo.h>

#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
#define BUTTON_PIN 4

Servo fan;

// 🧠 STATES
enum State {
  IDLE,
  NIGHT,
  ALERT,
  MANUAL
};

State currentState = IDLE;

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  fan.attach(SERVO_PIN);
}

void loop() {

  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  bool button = (digitalRead(BUTTON_PIN) == LOW);

  // 🔄 STATE TRANSITIONS

  switch (currentState) {

    case IDLE:

      if (light < 400) {
        currentState = NIGHT;
      }

      if (button) {
        currentState = MANUAL;
        delay(300);
      }

      break;

    case NIGHT:

      if (motion == HIGH) {
        currentState = ALERT;
      }

      if (light > 700) {
        currentState = IDLE;
      }

      break;

    case ALERT:

      if (motion == LOW) {
        currentState = NIGHT;
      }

      break;

    case MANUAL:

      if (button) {
        currentState = IDLE;
        delay(300);
      }

      break;
  }

  // ⚙️ STATE ACTIONS
  runStateActions();
}

// ⚙️ ACTIONS
void runStateActions() {

  switch (currentState) {

    case IDLE:

      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      fan.write(0);

      Serial.println("STATE: IDLE");

      break;

    case NIGHT:

      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      fan.write(80);

      Serial.println("STATE: NIGHT");

      break;

    case ALERT:

      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      fan.write(150);

      Serial.println("STATE: ALERT");

      break;

    case MANUAL:

      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      fan.write(120);

      Serial.println("STATE: MANUAL");

      break;
  }

  delay(300);
}
