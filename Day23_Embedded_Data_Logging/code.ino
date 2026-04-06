int sensorPin = A0;
int value;
void setup() {
  Serial.begin(9600);
  Serial.println("Data Logging Started");

}

void loop() {
  value = analogRead(sensorPin);
  Serial.print("LOG: ");
  Serial.print("Sensor Value = ");
  Serial.print(value);
  Serial.print(" Time= ");
  Serial.println(millis());
  delay(1000);

}
