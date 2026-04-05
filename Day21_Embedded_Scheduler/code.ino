unsigned long currentTime;
unsigned long task1Time = 0;
unsigned long task2Time = 0;
unsigned long task3Time = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  currentTime = millis();
  if(currentTime - task1Time >= 1000){
    task1Time = currentTime;
    digitalWrite(5, !digitalRead(5));
    Serial.println("Task 1 Executed");
  }

  if(currentTime - task2Time >= 2000){
    task2Time = currentTime;
    digitalWrite(6, !digitalRead(6));
    Serial.println("Task 2 Exceuted");
  }

  if(currentTime - task3Time >= 3000){
    task3Time = currentTime;
    digitalWrite(7, !digitalRead(7));
    Serial.println("Task 3 Executed");
  }
  delay(2000);
}
