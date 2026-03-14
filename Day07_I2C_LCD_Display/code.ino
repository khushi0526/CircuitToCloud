#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0,0);              // Set cursor to column 0, row 0
  lcd.print("ECE Embedded Pro");   // Display title
  lcd.setCursor(0,1);              // Set cursor to second row
  lcd.print("I2C LCD Test");       // Display subtitle
}

void loop() {
  // Example: scroll message
  lcd.scrollDisplayLeft();
  delay(300);
}
