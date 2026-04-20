#define led1 7
#define led2 8
#define buzzer 6
#define button 2
unsigned long prev1 = 0;
unsigned long prev2 = 0;
unsigned long prev3 = 0;
bool systemOn = true;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == LOW) {
    systemOn = !systemOn;
    delay(300);
  }
  if (!systemOn) 
  return;
  unsigned long current = millis();
  if (current - prev1 >= 1000) {
    prev1 = current;
    digitalWrite(led1, !digitalRead(led1));
    Serial.println("Task1: LED1 Toggle");
  }
  if (current - prev2 >= 2000) {
    prev2 = current;
    digitalWrite(led2, !digitalRead(led2));
    Serial.println("Task2: LED2 Toggle");
  }
  if (current - prev3 >= 3000) {
    prev3 = current;
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    Serial.println("Task3: Buzzer Beep");
  }
}
