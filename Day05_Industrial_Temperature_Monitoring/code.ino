#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_PIN 8
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
}

void loop() {

  float temperature = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if(temperature > 40)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Warning: Machine Overheating!");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
  delay(2000);
}
