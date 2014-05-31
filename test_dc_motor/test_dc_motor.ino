//test dc motor

int motorPin = 9;
int switchPin = 8;
int switchState = 0;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop(){
  switchState = digitalRead(switchPin);
  
  if(switchState == LOW){
    digitalWrite(motorPin, HIGH);
  }else{
    digitalWrite(motorPin, LOW);
  }
}
