#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define pulsePin A0
#define ledPin 7
#define buzzerPin 6
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {

  float temp = dht.readTemperature();
  int pulse = analogRead(pulsePin);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Pulse:");
  lcd.print(pulse);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" | Pulse: ");
  Serial.println(pulse);

  if (temp > 38 || pulse > 700) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Emergency!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}
