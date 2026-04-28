#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
#define MODE_BTN 4
#define LIGHT_BTN 8
#define FAN_BTN 9
Servo fan;
LiquidCrystal_I2C lcd(0x27, 16, 2);
bool autoMode = true;
bool ledState = false;
bool fanState = false;
int lightThreshold = 400;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MODE_BTN, INPUT_PULLUP);
  pinMode(LIGHT_BTN, INPUT_PULLUP);
  pinMode(FAN_BTN, INPUT_PULLUP);
  fan.attach(SERVO_PIN);
  lcd.init();
  lcd.backlight();
}

void loop() {
  handleModeSwitch();
  if (autoMode) {
    runAutoMode();
  } 
  else {
    runManualMode();
  }
  updateDisplay();
  delay(200);
}

void handleModeSwitch() {
  if (digitalRead(MODE_BTN) == LOW) {
    autoMode = !autoMode;
    delay(300);
  }
}
void runAutoMode() {
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  ledState = (light < lightThreshold);
  digitalWrite(LED_PIN, ledState);
  fanState = (light < lightThreshold);
  fan.write(fanState ? 120 : 0);
  digitalWrite(BUZZER_PIN, motion);
}

void runManualMode() {
  if (digitalRead(LIGHT_BTN) == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(300);
  }
  if (digitalRead(FAN_BTN) == LOW) {
    fanState = !fanState;
    fan.write(fanState ? 120 : 0);
    delay(300);
  }
  digitalWrite(BUZZER_PIN, LOW);
}
void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(autoMode ? "Mode: AUTO" : "Mode: MANUAL");
  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(ledState ? "ON " : "OFF");
  lcd.print(" F:");
  lcd.print(fanState ? "ON" : "OFF");
}
