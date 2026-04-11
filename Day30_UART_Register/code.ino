void UART_init() {
  // Set baud rate to 9600
  UBRR0H = 0;
  UBRR0L = 103;

  // Enable transmitter
  UCSR0B = (1 << TXEN0);

  // Set frame format: 8 data bits, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_sendChar(char data) {
  // Wait until buffer is empty
  while (!(UCSR0A & (1 << UDRE0)));

  // Put data into buffer
  UDR0 = data;
}

void UART_sendString(const char *str) {
  while (*str) {
    UART_sendChar(*str);
    str++;
  }
}

void setup() {
  UART_init();
}

void loop() {

  UART_sendString("Hello Khushi!\n");

  delay(1000);
}
