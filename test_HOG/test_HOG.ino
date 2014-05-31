//test programma HOG 

#include <Servo.h> 
 
Servo servo1;
Servo servo2;
 
int potpin1 = A0;
int potpin2 = A2;
int val1;
int val2;

int motorPin = 9;
int switchPin = 8;
int switchState = 0;
 
void setup() 
{ 
  servo1.attach(10);
  servo2.attach(11);
  
  pinMode(potpin1, INPUT);
  pinMode(potpin2, INPUT);
  
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
} 
 
void loop() 
{ 
  val1 = analogRead(potpin1);
  val2 = analogRead(potpin2);
  val1 = map(val1, 0, 1023, 0, 179);
  val2 = map(val2, 0, 1023, 0, 179);
  servo1.write(val1);
  servo2.write(val2); 
  delay(15);
  
  switchState = digitalRead(switchPin);
  if(switchState == LOW){
    digitalWrite(motorPin, HIGH);
  }else{
    digitalWrite(motorPin, LOW);
  }
} 
