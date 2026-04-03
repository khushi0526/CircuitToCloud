#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define vibrationPin 3
#define ledPin 7
#define buzzerPin 6

DHT dht(DHTPIN, DHTTYPE);

float tempThreshold = 35.0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(vibrationPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  float temperature = dht.readTemperature();
  int vibration = digitalRead(vibrationPin);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Vibration: ");
  Serial.println(vibration);

  if (temperature > tempThreshold || vibration == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("⚠️ ALERT: Machine Condition Abnormal");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("✅ Machine Running Normally");
  }

  delay(1000);
}
