#include <Servo.h>

#define LED_PIN 7
#define SERVO_PIN 5
#define PIR_PIN 2
#define BUZZER_PIN 6
#define LDR_PIN A0

Servo fan;

// ================= FSM =================

enum State {
  IDLE,
  NIGHT,
  ALERT
};

State currentState = IDLE;

// ================= LOGGER =================

struct LogEntry {

  unsigned long timeStamp;

  String event;
};

LogEntry logs[20];

int logIndex = 0;

// ================= SCHEDULER =================

unsigned long prevTask = 0;

int interval = 300;

// ================= EVENTS =================

bool darkEvent = false;

bool motionEvent = false;

// ================= SETUP =================

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  fan.attach(SERVO_PIN);

  Serial.println("=== SMART EMBEDDED SYSTEM ===");
}

// ================= LOOP =================

void loop() {

  scheduler();

  commandProcessor();
}

// ================= SCHEDULER =================

void scheduler() {

  unsigned long now = millis();

  if (now - prevTask >= interval) {

    prevTask = now;

    detectEvents();

    updateFSM();

    runStateActions();
  }
}

// ================= EVENTS =================

void detectEvents() {

  int light = analogRead(LDR_PIN);

  int motion = digitalRead(PIR_PIN);

  darkEvent = (light < 400);

  motionEvent = (motion == HIGH);
}

// ================= FSM =================

void updateFSM() {

  switch (currentState) {

    case IDLE:

      if (darkEvent) {

        currentState = NIGHT;

        addLog("ENTER NIGHT");
      }

      break;

    case NIGHT:

      if (motionEvent) {

        currentState = ALERT;

        addLog("ALERT TRIGGERED");
      }

      if (!darkEvent) {

        currentState = IDLE;

        addLog("RETURN IDLE");
      }

      break;

    case ALERT:

      if (!motionEvent) {

        currentState = NIGHT;

        addLog("ALERT CLEARED");
      }

      break;
  }
}

// ================= ACTIONS =================

void runStateActions() {

  switch (currentState) {

    case IDLE:

      digitalWrite(LED_PIN, LOW);

      digitalWrite(BUZZER_PIN, LOW);

      fan.write(0);

      break;

    case NIGHT:

      digitalWrite(LED_PIN, HIGH);

      digitalWrite(BUZZER_PIN, LOW);

      fan.write(80);

      break;

    case ALERT:

      digitalWrite(LED_PIN, HIGH);

      digitalWrite(BUZZER_PIN, HIGH);

      fan.write(150);

      break;
  }
}

// ================= LOGGER =================

void addLog(String message) {

  if (logIndex < 20) {

    logs[logIndex].timeStamp = millis();

    logs[logIndex].event = message;

    logIndex++;
  }
}

// ================= COMMAND SYSTEM =================

void commandProcessor() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');

    cmd.trim();

    cmd.toUpperCase();

    if (cmd == "STATUS") {

      printStatus();
    }

    else if (cmd == "LOGS") {

      printLogs();
    }

    else if (cmd == "RESET") {

      resetLogs();
    }

    else {

      Serial.println("INVALID COMMAND");
    }
  }
}

// ================= STATUS =================

void printStatus() {

  Serial.println("\n=== STATUS ===");

  Serial.print("STATE: ");

  switch (currentState) {

    case IDLE:
      Serial.println("IDLE");
      break;

    case NIGHT:
      Serial.println("NIGHT");
      break;

    case ALERT:
      Serial.println("ALERT");
      break;
  }
}

// ================= PRINT LOGS =================

void printLogs() {

  Serial.println("\n=== LOG HISTORY ===");

  for (int i = 0; i < logIndex; i++) {

    Serial.print("[");

    Serial.print(logs[i].timeStamp);

    Serial.print(" ms] ");

    Serial.println(logs[i].event);
  }
}

// ================= RESET =================

void resetLogs() {

  logIndex = 0;

  Serial.println("LOGS RESET");
}
