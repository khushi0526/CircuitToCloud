#include <Servo.h>

#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0

Servo fan;

// 📡 NODE DATA
struct SensorData {

  int lightLevel;

  bool motionDetected;

};

SensorData networkData;

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  fan.attach(SERVO_PIN);
}

void loop() {

  // 📡 SENSOR NODES
  lightSensorNode();

  motionSensorNode();

  // 🧠 MASTER CONTROLLER
  masterController();

  delay(200);
}

// 🌙 NODE 1
void lightSensorNode() {

  networkData.lightLevel = analogRead(LDR_PIN);
}

// 🚶 NODE 2
void motionSensorNode() {

  networkData.motionDetected =
    digitalRead(PIR_PIN);
}

// 🧠 MASTER NODE
void masterController() {

  Serial.print("Light: ");

  Serial.print(networkData.lightLevel);

  Serial.print(" | Motion: ");

  Serial.println(networkData.motionDetected);

  // 💡 LIGHTING
  if (networkData.lightLevel < 400) {

    digitalWrite(LED_PIN, HIGH);

    fan.write(120);

  } else {

    digitalWrite(LED_PIN, LOW);

    fan.write(0);
  }

  // 🚨 SECURITY
  if (
    networkData.motionDetected &&
    networkData.lightLevel < 400
  ) {

    digitalWrite(BUZZER_PIN, HIGH);

  } else {

    digitalWrite(BUZZER_PIN, LOW);
  }
}
