//test servo's

#include <Servo.h> 
 
Servo servo1;
Servo servo2;
 
int potpin1 = A1;
int potpin2 = A2;
int val1;
int val2;

void setup() 
{ 
  servo1.attach(9);
  servo2.attach(10);
  
  pinMode(potpin1, INPUT);
  pinMode(potpin2, INPUT);
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
}
