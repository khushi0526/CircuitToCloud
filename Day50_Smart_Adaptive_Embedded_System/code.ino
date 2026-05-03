#include <Servo.h>
#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0
Servo fan;
int dark = 300;
int medium = 700;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  fan.attach(SERVO_PIN);
}

void loop() {
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  handleLighting(light);
  handleFan(light);
  handleSecurity(light, motion);
  debug(light, motion);
  delay(200);
}

void handleLighting(int light) {
  if (light < medium) {
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
void handleFan(int light) {
  if (light < dark) {
    fan.write(160);   
  }
  else if (light < medium) {
    fan.write(80);    
  }
  else {
    fan.write(0);     
  }
}

void handleSecurity(int light, int motion) {
  if (motion == HIGH && light < medium) {
    digitalWrite(BUZZER_PIN, HIGH);
  } 
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void debug(int light, int motion) {
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print(" | Motion: ");
  Serial.print(motion);
  Serial.print(" | Mode: ");
  if (light < dark) 
  Serial.println("NIGHT (HIGH ACTIVITY)");
  else if (light < medium) 
  Serial.println("EVENING");
  else 
  Serial.println("DAY");
}
