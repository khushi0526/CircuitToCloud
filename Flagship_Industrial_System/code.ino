#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define pirPin 3
#define Pot A0
#define ledPin 7
#define buzzerPin 6
#define fanPin 9
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  dht.begin();

}

void loop() {
  float temp = dht.readTemperature();
  int energy = analogRead(Pot);
  int motion = digitalRead(pirPin);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" Energy: ");
  Serial.print(energy);
  Serial.print(" Motion: ");
  Serial.println(motion);

  if(temp > 35 || energy > 700 || motion == HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Critical Condition");
  }
  else{
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  if(temp > 30){
    analogWrite(fanPin, 200);
    Serial.println("Fan On");
  }
  else{
    analogWrite(fanPin, 0);
  }

delay(1000);
}
