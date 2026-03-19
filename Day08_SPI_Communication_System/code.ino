//Master Code
#include <SPI.h>

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT); // SS pin

  SPI.begin(); // Start SPI as Master
}

void loop() {

  digitalWrite(10, LOW);   // Select Slave

  SPI.transfer('A');       // Send data

  digitalWrite(10, HIGH);  // Deselect Slave

  Serial.println("Data Sent: A");

  delay(1000);
}



//Slave Code
#include <SPI.h>

volatile char receivedData;

void setup() {
  Serial.begin(9600);

  pinMode(MISO, OUTPUT);   // Slave sends data back

  SPCR |= _BV(SPE);        // Enable SPI in Slave mode

  SPI.attachInterrupt();   // Enable SPI interrupt
}

// Interrupt function when data is received
ISR (SPI_STC_vect) {
  receivedData = SPDR;     // Read received data
}

void loop() {

  Serial.print("Received: ");
  Serial.println(receivedData);

  delay(500);
}
