#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
int sensorPin = A0;

File dataFile;

void setup() {
  Serial.begin(9600);

  // Initialize SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized.");

  // Create/Open file
  dataFile = SD.open("data.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println("Time(ms), SensorValue");
    dataFile.close();
  }
}

void loop() {

  int sensorValue = analogRead(sensorPin);
  unsigned long timeStamp = millis();

  // Open file
  dataFile = SD.open("data.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.print(timeStamp);
    dataFile.print(",");
    dataFile.println(sensorValue);
    dataFile.close();

    Serial.println("Data logged to SD card");
  } else {
    Serial.println("Error opening file");
  }

  delay(1000);
}
