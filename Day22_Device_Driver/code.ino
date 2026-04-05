//Driver Layer
int sensorPin = A0;

//Initialize sensor
void sensor_init(){
  pinMode(sensorPin, INPUT);
}

//Read sensor value
int sensor_read(){
  return analogRead(sensorPin);
}

int ledPin = 7;
int threshold = 500;
void setup() {
  Serial.begin(9600);
  sensor_init();
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int value = sensor_read();
  Serial.print("Sensor Value: ");
  Serial.println(value);
  if(value > threshold){
    digitalWrite(ledPin, HIGH);
    Serial.println("High value");
  }
  else{
    digitalWrite(ledPin, LOW);
    Serial.println("Normal Value");
  }
  delay(500);

}
