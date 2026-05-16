#include <Servo.h>

#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0

Servo fan;

// 📦 LOG STRUCTURE
struct LogEntry {

  unsigned long timeStamp;

  String event;

};

// Memory for logs
LogEntry logs[10];

int logIndex = 0;

// Last states
bool lastLightState = false;
bool lastMotionState = false;

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  fan.attach(SERVO_PIN);

  Serial.println("=== DATA LOGGER SYSTEM ===");
}

void loop() {

  monitorLighting();

  monitorMotion();

  delay(300);
}

// 💡 LIGHT MONITOR
void monitorLighting() {

  int light = analogRead(LDR_PIN);

  bool currentLightState = (light < 400);

  digitalWrite(LED_PIN, currentLightState);

  fan.write(currentLightState ? 120 : 0);

  // EVENT CHANGE
  if (currentLightState != lastLightState) {

    if (currentLightState) {

      addLog("LIGHT ON");

    } else {

      addLog("LIGHT OFF");
    }

    lastLightState = currentLightState;
  }
}

// 🚨 MOTION MONITOR
void monitorMotion() {

  bool motion = digitalRead(PIR_PIN);

  digitalWrite(BUZZER_PIN, motion);

  // EVENT CHANGE
  if (motion != lastMotionState) {

    if (motion) {

      addLog("MOTION DETECTED");

    } else {

      addLog("MOTION STOPPED");
    }

    lastMotionState = motion;
  }
}

// 💾 ADD LOG
void addLog(String message) {

  if (logIndex < 10) {

    logs[logIndex].timeStamp = millis();

    logs[logIndex].event = message;

    logIndex++;
  }

  printLogs();
}

// 📊 PRINT LOGS
void printLogs() {

  Serial.println("\n=== EVENT LOGS ===");

  for (int i = 0; i < logIndex; i++) {

    Serial.print("[");

    Serial.print(logs[i].timeStamp);

    Serial.print(" ms] ");

    Serial.println(logs[i].event);
  }

  Serial.println("==================");
}
