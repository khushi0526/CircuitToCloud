#include <DHT.h>
#include <Servo.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define SERVO_PIN 9
DHT dht(DHTPIN, DHTTYPE);
Servo fan;

float setPoint = 30.0;  // Desired temp in °C
float Kp = 2.0, Ki = 0.5, Kd = 1.0;
float integral = 0, lastError = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  fan.attach(SERVO_PIN);
}

void loop() {
  float temp = dht.readTemperature();
  float error = setPoint - temp;

  integral += error;
  float derivative = error - lastError;

  float output = Kp*error + Ki*integral + Kd*derivative;

  // Constrain output for servo (0-180)
  float rotate = constrain(output, 0, 180);
  fan.write(rotate);

  lastError = error;

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C, Fan Output: ");
  Serial.println(output);

  delay(1000);
}
