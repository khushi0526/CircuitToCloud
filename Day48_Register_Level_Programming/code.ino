void setup() {
  DDRD |= (1 << 7);
}

void loop() {
  PORTD |= (1 << 7);
  delay(1000);
  PORTD &= ~(1 << 7);
  delay(1000);
}
