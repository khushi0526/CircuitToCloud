#define LED_PIN 7
#define BUTTON_PIN 2
volatile bool ledState = false;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(
    digitalPinToInterrupt(BUTTON_PIN),
    toggleLED,
    FALLING
  );
}
void loop() {
  digitalWrite(LED_PIN, ledState);
}
void toggleLED() {
  ledState = !ledState;
}
