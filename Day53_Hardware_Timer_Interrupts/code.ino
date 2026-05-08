#define LED_PIN 7

volatile bool ledState = false;

void setup() {

  pinMode(LED_PIN, OUTPUT);

  cli(); // Disable interrupts

  // TIMER1 setup
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 0;

  // Compare match value
  OCR1A = 15624;

  // CTC mode
  TCCR1B |= (1 << WGM12);

  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Enable interrupts
}

void loop() {

  digitalWrite(LED_PIN, ledState);

}

// TIMER INTERRUPT
ISR(TIMER1_COMPA_vect) {

  ledState = !ledState;

}
