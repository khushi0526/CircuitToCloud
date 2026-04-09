#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define fanPin 9
#define buttonPin 3
DHT dht(DHTPIN, DHTTYPE);
volatile bool manualMode = false;
void toggleMode(){
  manualMode = !manualMode;
}
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(fanPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleMode, FALLING);

}

void loop() {
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temp);
  if(!manualMode){
    if(temp > 30){
      analogWrite(fanPin, 255);
      Serial.println("Auto Mode: High Speed");
    }
    else if(temp > 25){
      analogWrite(fanPin, 150);
      Serial.println("Auto Mode: Medium Speed");
    }
    else{
      analogWrite(fanPin, 0);
      Serial.println("Auto Mode: Fan OFF");
    }
  }
  else{
    analogWrite(fanPin, 200);
    Serial.println("ManualMode: Fan ON");
  }
  delay(1000);

}
