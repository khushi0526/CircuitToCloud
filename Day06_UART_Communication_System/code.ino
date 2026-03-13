void setup() {
  Serial.begin(9600);
  Serial.println("UART Communication System Started");
}

void loop() {

  if (Serial.available() > 0) {

    char data = Serial.read();

    Serial.print("Received Data: ");
    Serial.println(data);

  }

}
