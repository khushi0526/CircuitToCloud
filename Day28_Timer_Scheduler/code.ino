#include <avr/interrupt.h>
volatile bool task1Flag = false;
volatile bool task2Flag = false;
volatile bool task3Flag = false;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // Disable interrupts
  cli();

  // Timer1 setup (1 second interrupt)
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 15624; // 1 second for 16MHz clock

  TCCR1B |= (1 << WGM12);  // CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024

  TIMSK1 |= (1 << OCIE1A); // Enable timer interrupt

  sei(); // Enable interrupts
}

// Timer Interrupt Service Routine
ISR(TIMER1_COMPA_vect) {
  count++;

  if (count % 1 == 0) task1Flag = true;
  if (count % 2 == 0) task2Flag = true;
  if (count % 3 == 0) task3Flag = true;
}

void loop() {

  if (task1Flag) {
    digitalWrite(5, !digitalRead(5));
    Serial.println("Task 1 (1 sec)");
    task1Flag = false;
  }

  if (task2Flag) {
    digitalWrite(6, !digitalRead(6));
    Serial.println("Task 2 (2 sec)");
    task2Flag = false;
  }

  if (task3Flag) {
    digitalWrite(7, !digitalRead(7));
    Serial.println("Task 3 (3 sec)");
    task3Flag = false;
  }
}
