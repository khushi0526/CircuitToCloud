#include <Servo.h>
#define irSensor 2
#define buttonPin 3
#define ledPin 7
#define buzzerPin 6
Servo motor;
bool systemOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(irSensor, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  motor.attach(5);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    systemOn = !systemOn;
    delay(300); 
  }

  if (systemOn) {
    int objectDetected = digitalRead(irSensor);
    if (objectDetected == LOW) { 
      motor.write(0); 
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      Serial.println("Object Detected - Conveyor Stopped");
    } 
    else {
      motor.write(90); 
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Serial.println("Conveyor Running");
    }

  } else {
    motor.write(0);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    Serial.println("System OFF");
  }

  delay(500);
}
