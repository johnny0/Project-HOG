//HOG

#include <Servo.h> //an arduino library for servo's

//declare 2 servo motors with a name
Servo servo1;
Servo servo2;

//declare 2 potentiometers to the arduino
int potPin1 = A0;
int potPin2 = A2;

int buttonPin = 8; //declare a button to the arduino
int motor = 9; //declare the DC motor to the arduino

int motorState = HIGH; //declare a variable for the motor
int buttonState; 
int lastButtonState; //a variable that remembers the previous state of the button, this helps in the debouncing

//declare variables to put the potentiometers value in
int val1;
int val2;

//declare variables for the debouncing process
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup(){
  //connecting the servo's to the arduino
  servo1.attach(10);
  servo2.attach(11);

  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(buttonPin, INPUT);
  
  pinMode(motor, OUTPUT);
  digitalWrite(motor, motorState); //the motor gets an initial value
}

void loop(){
  int reading = digitalRead(buttonPin); //the state of the button is put on an extra variable
  
  //debouncing process
  if(reading != lastButtonState){
    lastDebounceTime = millis();
  }
  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonState){
      buttonState = reading;
      if(buttonState == HIGH){
        motorState = !motorState;
      }
    }
  }
  //the motor gets turned on or off
  digitalWrite(motor, motorState);
  lastButtonState = reading;
  
  //reading the value of the potmeters and mapping it in a value that the servo's can read
  val1 = analogRead(potPin1);
  val2 = analogRead(potPin2);
  val1 = map(val1, 0, 1023, 0, 179);
  val2 = map(val2, 0, 1023, 0, 179);
  
  //positioning the servo's
  servo1.write(val1);
  servo2.write(val2);
  delay(15);
}
