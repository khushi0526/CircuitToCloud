#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define MQ135 A0

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();

}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int airQuality = analogRead(MQ135);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C ");

  lcd.print("H:");
  lcd.print(humidity);

  lcd.setCursor(0,1);
  lcd.print("Air:");
  lcd.print(airQuality);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  Serial.print("Air Quality: ");
  Serial.println(airQuality);

  delay(2000);
}
