#define ldr A0
#define pirPin 2
#define ledPin 7
volatile bool motionDetected = false;

void motionISR() {
  motionDetected = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), motionISR, RISING);
}

void loop() {
  int lightValue = analogRead(ldr);

  Serial.print("Light: ");
  Serial.println(lightValue);

  if (lightValue < 400 && motionDetected) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Light ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Light OFF");
  }

  motionDetected = false;
  delay(500);
}
