int lightSensor = A0;
int pirSensor = 2;
int ledPin = 9;
int lightValue;
int motion;
int threshold = 500; 
void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(lightSensor);
  motion = digitalRead(pirSensor);
  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" Motion: ");
  Serial.println(motion);
  if (lightValue > threshold) {
    analogWrite(ledPin, 0);
    Serial.println("Day → Light OFF");
  } 
  else {
    if (motion == HIGH) {
      analogWrite(ledPin, 255); 
      Serial.println("Full Light");
    } 
    else {
      analogWrite(ledPin, 40);
      Serial.println("Dim Light");
    }
  }
  delay(1000);
}
