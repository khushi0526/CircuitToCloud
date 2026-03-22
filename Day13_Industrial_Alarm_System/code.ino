int sensorPin = A0;
int buzzer = 8;
int led = 7;
int value;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  value = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(value);
  if(value > 600) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }
  delay(500);
}
