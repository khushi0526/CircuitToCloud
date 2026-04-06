char key = 'K';
void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {

    char data = Serial.read();
    if (data == '\n' || data == '\r') {
      return;
    }
    // Encryption
    char encrypted = data ^ key;
    // Decryption
    char decrypted = encrypted ^ key;

    Serial.print("Encrypted Data (number): ");
    Serial.println((int)encrypted);

    Serial.print("Decrypted Data: ");
    Serial.println(decrypted);
  }
}
