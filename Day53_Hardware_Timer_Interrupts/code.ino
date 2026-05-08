#define LED_PIN 7
volatile bool ledState = false;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  cli(); 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei(); 
}

void loop() {
  digitalWrite(LED_PIN, ledState);
}

ISR(TIMER1_COMPA_vect) {
  ledState = !ledState;

}
