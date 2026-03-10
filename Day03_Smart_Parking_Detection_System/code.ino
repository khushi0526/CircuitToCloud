#define trigPin 9
#define echoPin 10
#define greenLED 5
#define redLED 6
#define buzzer 7

long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);                 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

                          
duration = pulseIn(echoPin, HIGH);

                              
distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.println(distance);
                                    
  if (distance > 10) {
Serial.println("Parking Available");
digitalWrite(greenLED, HIGH);
digitalWrite(redLED, LOW);
digitalWrite(buzzer, LOW);
} else {
Serial.println("Parking Full");
digitalWrite(greenLED, LOW);
digitalWrite(redLED, HIGH);
digitalWrite(buzzer, HIGH);
}

delay(1000);
}
