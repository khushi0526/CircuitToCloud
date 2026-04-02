int sensorPin = A0;
int pumpPin = 7;

int moistureValue = 0;
int threshold = 500;  // Adjust based on simulation

void setup() {
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  moistureValue = analogRead(sensorPin);

  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    digitalWrite(pumpPin, HIGH);
    Serial.println("Soil Dry → Pump ON");
  } else {
    digitalWrite(pumpPin, LOW);
    Serial.println("Soil Wet → Pump OFF");
  }

  delay(1000);
}
