#include <Servo.h>
#define btn1 2
#define btn2 3
#define btn3 4
#define led1 8
#define led2 9
#define led3 10
#define buzzer 6
Servo door;

int currentFloor = 1;
void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  door.attach(5);
  updateLEDs();
}

void loop() {

  if (digitalRead(btn1) == LOW) moveToFloor(1);
  if (digitalRead(btn2) == LOW) moveToFloor(2);
  if (digitalRead(btn3) == LOW) moveToFloor(3);
}

void moveToFloor(int targetFloor) {
  Serial.print("Moving to Floor ");
  Serial.println(targetFloor);
  while (currentFloor != targetFloor) {
    if (currentFloor < targetFloor) currentFloor++;
    else currentFloor--;
    updateLEDs();
    Serial.print("Current Floor: ");
    Serial.println(currentFloor);

    delay(1000);
  }
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  Serial.println("Arrived!");
  door.write(90);
  delay(2000);
  door.write(0);
}
void updateLEDs() {
  digitalWrite(led1, currentFloor == 1);
  digitalWrite(led2, currentFloor == 2);
  digitalWrite(led3, currentFloor == 3);
}
