#define pirPin 2
#define ledPin 7
#define buzzerPin 6
#define resetButton 3
volatile bool alert = false;
void triggerAlarm(){
  alert = true;
}
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pirPin), triggerAlarm, RISING);

}

void loop() {
  if(alert){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("INTRUDER DETECTED");
  }

  if(digitalRead(resetButton) == LOW){
    alert = false;
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("System Reset");
    delay(300);
  }

}
