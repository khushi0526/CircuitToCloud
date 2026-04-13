#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define sensorPin A0
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();
  int analogValue = analogRead(sensorPin);
  String dataPacket = "T:" + String(temp) + ",A:" + String(analogValue);
  Serial.println(dataPacket);
  parseData(dataPacket);
  delay(1000);
}

void parseData(String data) {
  int tIndex = data.indexOf("T:");
  int aIndex = data.indexOf(",A:");
  float receivedTemp = data.substring(tIndex + 2, aIndex).toFloat();
  int receivedAnalog = data.substring(aIndex + 3).toInt();
  Serial.print("Parsed Temp: ");
  Serial.print(receivedTemp);
  Serial.print(" | Parsed Analog: ");
  Serial.println(receivedAnalog);

  if (receivedTemp > 30 || receivedAnalog > 700) {
    Serial.println("ALERT: Node Condition Critical");
  } else {
    Serial.println("Node Condition Normal");
  }
}
