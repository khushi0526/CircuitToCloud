#include <SD.h>
#include <SPI.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define CSPIN 10

DHT dht(DHTPIN, DHTTYPE);

File dataFile;

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!SD.begin(CSPIN)) {
    Serial.println("SD card failed!");
    return;
  }
  Serial.println("SD card initialized.");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  dataFile = SD.open("datalog.csv", FILE_WRITE);

  if (dataFile) {
    dataFile.print("Temperature: ");
    dataFile.print(temp);
    dataFile.print(", Humidity: ");
    dataFile.println(hum);
    dataFile.close();
    Serial.println("Data logged.");
  } else {
    Serial.println("Error opening file!");
  }

  delay(2000); // Log every 2 seconds
}
