#define trigPin 9
#define echoPin 10
#define alertLED 2
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 10)
  {
    Serial.println("Tank Status: FULL");
    digitalWrite(alertLED, LOW);
  }
  else if(distance >= 10 && distance <= 300)
  {
    Serial.println("Tank Status: MEDIUM");
    digitalWrite(alertLED, LOW);
  }
  else
  {
    Serial.println("Tank Status: LOW WATER LEVEL");
    digitalWrite(alertLED, HIGH);
  }
  delay(1000);
}
