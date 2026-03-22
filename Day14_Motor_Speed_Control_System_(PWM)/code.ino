int potPin = A0;
int motorPin = 9;
int value;
int speed;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  value = analogRead(potPin);   // 0–1023
  speed = map(value, 0, 1023, 0, 255);
  analogWrite(motorPin, speed);
  Serial.print("Speed: ");
  Serial.println(speed);
  delay(200);
}
