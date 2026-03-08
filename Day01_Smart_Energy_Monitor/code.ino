int sensorPin = A0;
int ledPin = 9;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(sensorPin);

  Serial.print("Energy Signal Value: ");
  Serial.println(sensorValue);

  if(sensorValue > 600)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}
