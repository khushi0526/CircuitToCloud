int device1 = A0;
int device2 = A1;
int device3 = A3;
int led1 = 5;
int led2 = 6;
int led3 = 7;
int val1, val2, val3;
int threshold = 700;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  val1 = analogRead(device1);
  val2 = analogRead(device2);
  val3 = analogRead(device3);
  Serial.print("Device 1: ");
  Serial.println(val1);
  Serial.print("Device 2: ");
  Serial.println(val2);  
  Serial.print("Device 3: ");
  Serial.println(val3);
  digitalWrite(led1, val1 > 100 ? HIGH : LOW);
  digitalWrite(led2, val2 > 100 ? HIGH : LOW);
  digitalWrite(led3, val3 > 100 ? HIGH : LOW);
  if(val1 > threshold || val2 > threshold || val3 > threshold){
    Serial.println("High energy Consumption");
  }
  else{
    Serial.println("Energy usage Normal \n");
  }
  delay(1000);
}
