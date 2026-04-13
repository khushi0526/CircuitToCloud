#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define ledPin 7
#define buzzerPin 6
DHT dht(DHTPIN, DHTTYPE);
float temp, hum;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("System Started...");
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  if (temp > 35 || hum > 80) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("ALERT: Critical Condition!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Normal Condition");
  }

  delay(1000);
}
