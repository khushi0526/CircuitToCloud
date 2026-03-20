#include <WiFi.h>
#include <DHT.h>
#define DHTPIN 16
#define DHTTYPE DHT22
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* server = "api.thingspeak.com";
String apiKey = "YOUR_API_KEY";  // Replace this
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
void setup() {
  Serial.begin(9600);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" | Hum: ");
  Serial.println(hum);
  if (client.connect(server, 80)) {
    String url = "/update?api_key=" + apiKey;
    url += "&field1=" + String(temp);
    url += "&field2=" + String(hum);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
  }
  delay(15000); // ThingSpeak limit
}
