#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define LED 11
#define BUZZER 12
Servo lockServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
const String password = "1234";
String input = "";
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  lockServo.attach(10);
  lcd.init();
  lcd.backlight();
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    input += key;
    lcd.setCursor(0,1);
    lcd.print(input);

    if (input.length() == 4) {

      if (input == password) {

        lcd.clear();
        lcd.print("Access Granted");

        digitalWrite(LED, HIGH);
        lockServo.write(90); 
        delay(2000);
        lockServo.write(0); 
        digitalWrite(LED, LOW);

      } 
      else {
        lcd.clear();
        lcd.print("Access Denied");
        digitalWrite(BUZZER, HIGH);
        delay(1000);
        digitalWrite(BUZZER, LOW);
      }

      input = "";
      lcd.clear();
      lcd.print("Enter Password");
    }
  }
}
