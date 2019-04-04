#include <AFMotor.h>

AF_DCMotor motor(3);

int speed=0,num;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);

//  while(Serial.available()==0){
//  }
//  speed = Serial.parseInt();
//  Serial.println(speed);
  
}

void loop() {
  uint8_t i;

  if(Serial.available()>0){
  num = Serial.parseInt();
  }
 
  if(num<0) speed = 0;
  else if(num>0) speed = num;
  Serial.println(speed);

  motor.run(BACKWARD);
  for (i=0; i<speed; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
  motor.setSpeed(speed);
  delay(5000);
}
