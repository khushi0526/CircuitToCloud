#define trigA 9
#define echoA 10
#define trigB 11
#define echoB 12
#define A_R 2
#define A_Y 3
#define A_G 4
#define B_R 5
#define B_Y 6
#define B_G 7
#define buzzer 8
#define emergency A0

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void setSignal(int r, int y, int g, int R, int Y, int G) {
  digitalWrite(r, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);

  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(trigA, OUTPUT); 
  pinMode(echoA, INPUT);
  pinMode(trigB, OUTPUT); 
  pinMode(echoB, INPUT);

  for (int i = 2; i <= 7; i++) 
  pinMode(i, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(emergency, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(emergency) == LOW) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(A_G, HIGH);
    digitalWrite(B_R, HIGH);
    Serial.println("Emergency Mode Activated");
    delay(3000);
    digitalWrite(buzzer, LOW);
    return;
  }

  long distA = getDistance(trigA, echoA);
  long distB = getDistance(trigB, echoB);
  Serial.print("A: "); Serial.print(distA);
  Serial.print(" | B: "); Serial.println(distB);
  int timeA = (distA < 20) ? 5000 : 2000;
  int timeB = (distB < 20) ? 5000 : 2000;
  digitalWrite(A_G, HIGH);
  digitalWrite(A_R, LOW);
  digitalWrite(B_R, HIGH);
  digitalWrite(B_G, LOW);
  delay(timeA);
  digitalWrite(A_G, LOW);
  digitalWrite(A_Y, HIGH);
  delay(1000);
  digitalWrite(A_Y, LOW);
  digitalWrite(B_G, HIGH);
  digitalWrite(B_R, LOW);
  digitalWrite(A_R, HIGH);
  delay(timeB);
  digitalWrite(B_G, LOW);
  digitalWrite(B_Y, HIGH);
  delay(1000);
  digitalWrite(B_Y, LOW);
}
