#include <Servo.h>

#define LED_PIN 7
#define BUZZER_PIN 6
#define SERVO_PIN 5

Servo fan;

String command = "";

bool ledState = false;
bool fanState = false;
bool buzzerState = false;

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  fan.attach(SERVO_PIN);

  Serial.println("=== SMART HOME CLI ===");

  Serial.println("Commands:");

  Serial.println("LIGHT ON");

  Serial.println("LIGHT OFF");

  Serial.println("FAN ON");

  Serial.println("FAN OFF");

  Serial.println("BUZZER ON");

  Serial.println("BUZZER OFF");

  Serial.println("STATUS");
}

void loop() {

  while (Serial.available()) {

    char c = Serial.read();

    // ENTER key
    if (c == '\n') {

      processCommand(command);

      command = "";

    } else {

      command += c;
    }
  }
}

// 🧠 COMMAND PROCESSOR
void processCommand(String cmd) {

  cmd.trim();

  cmd.toUpperCase();

  // 💡 LIGHT
  if (cmd == "LIGHT ON") {

    ledState = true;

    digitalWrite(LED_PIN, HIGH);

    Serial.println("LIGHT TURNED ON");
  }

  else if (cmd == "LIGHT OFF") {

    ledState = false;

    digitalWrite(LED_PIN, LOW);

    Serial.println("LIGHT TURNED OFF");
  }

  // 🌀 FAN
  else if (cmd == "FAN ON") {

    fanState = true;

    fan.write(120);

    Serial.println("FAN TURNED ON");
  }

  else if (cmd == "FAN OFF") {

    fanState = false;

    fan.write(0);

    Serial.println("FAN TURNED OFF");
  }

  // 🚨 BUZZER
  else if (cmd == "BUZZER ON") {

    buzzerState = true;

    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("BUZZER TURNED ON");
  }

  else if (cmd == "BUZZER OFF") {

    buzzerState = false;

    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("BUZZER TURNED OFF");
  }

  // 📊 STATUS
  else if (cmd == "STATUS") {

    Serial.println("----- STATUS -----");

    Serial.print("LIGHT: ");

    Serial.println(ledState ? "ON" : "OFF");

    Serial.print("FAN: ");

    Serial.println(fanState ? "ON" : "OFF");

    Serial.print("BUZZER: ");

    Serial.println(buzzerState ? "ON" : "OFF");
  }

  // ❌ INVALID
  else {

    Serial.println("INVALID COMMAND");
  }
}
