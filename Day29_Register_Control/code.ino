void setup() {
  DDRD |= (1 << PD2);
  DDRD |= (1 << PD3);
  DDRD |= (1 << PD4);
}

void loop() {
  PORTD |= (1 << PD2);
  delay(500);
  PORTD &= ~(1 << PD2);
  PORTD |= (1 << PD3);
  delay(500);
  PORTD &= ~(1 << PD3);
  PORTD |= (1 << PD4);
  delay(500);
  PORTD &= ~(1 << PD4);

}
