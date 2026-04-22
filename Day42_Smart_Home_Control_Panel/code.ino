#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define btnUp 2
#define btnDown 3
#define btnSelect 4
#define ledPin 7
#define buzzer 6
Servo fan;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int menu = 0;
bool lightState = false;
bool fanState = false;
bool buzzerState = false;

void setup() {
  Serial.begin(9600);
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnSelect, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  fan.attach(5);
  fan.write(0); 
  lcd.init();
  lcd.backlight();
  showMenu();
}

void loop() {
  if (digitalRead(btnUp) == LOW) {
    menu--;
    if (menu < 0) menu = 2;
    showMenu();
    delay(200);
  }
  if (digitalRead(btnDown) == LOW) {
    menu++;
    if (menu > 2) menu = 0;
    showMenu();
    delay(200);
  }
  if (digitalRead(btnSelect) == LOW) {
    executeMenu();
    delay(300);
    showMenu();
  }
}

void showMenu() {
  lcd.clear();
  switch (menu) {
    case 0:
      lcd.print("Light: ");
      lcd.print(lightState ? "ON" : "OFF");
      break;
    case 1:
      lcd.print("Fan: ");
      lcd.print(fanState ? "ON" : "OFF");
      break;
    case 2:
      lcd.print("Buzzer: ");
      lcd.print(buzzerState ? "ON" : "OFF");
      break;
  }
}

void executeMenu() {
  lcd.clear();
  switch (menu) {
    case 0: 
      lightState = !lightState;
      digitalWrite(ledPin, lightState);
      lcd.print(lightState ? "Light ON" : "Light OFF");
      break;
    case 1: 
      fanState = !fanState;
      if (fanState) {
        fan.write(90); 
        lcd.print("Fan ON");
      } 
      else {
        fan.write(0); 
        lcd.print("Fan OFF");
      }
      break;
    case 2: 
      buzzerState = !buzzerState;
      digitalWrite(buzzer, buzzerState);
      lcd.print(buzzerState ? "Buzzer ON" : "Buzzer OFF");
      break;
  }
}
