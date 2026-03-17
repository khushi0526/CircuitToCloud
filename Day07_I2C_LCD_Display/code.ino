#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();                     
  lcd.backlight();                 
  lcd.setCursor(0,0);              
  lcd.print("ECE Embedded Pro");   
  lcd.setCursor(0,1);             
  lcd.print("I2C LCD Test");     
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
