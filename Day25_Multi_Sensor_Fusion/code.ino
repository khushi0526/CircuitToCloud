#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define lightSensor A0
#define motionSensor 3
#define ledPin 7
DHT dht(DHTPIN, DHTTYPE);
float temp;
int lightValue;
int motion;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(motionSensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  temp = dht.readTemperature();
  lightValue = analogRead(lightSensor);
  motion = digitalRead(motionSensor);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" | Light: ");
  Serial.print(lightValue);
  Serial.print(" | Motion: ");
  Serial.println(motion);

  if (temp > 30 && lightValue < 400 && motion == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ALERT: Condition Matched");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Normal Condition");
  }

  delay(1000);
}
