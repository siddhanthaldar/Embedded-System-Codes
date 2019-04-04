#include <AFMotor.h>

AF_DCMotor motor(3);

int speed=0,num;
int analogPin = 0;
float raw = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);

  pinMode(analogPin,INPUT);
  
}

void loop() {
  uint8_t i;
  raw = analogRead(analogPin);
  Serial.print(raw);
  Serial.print("    ");
//  delay(1000);

  if(raw<150) speed = 255;
  else if(raw<200 & raw>150) speed = 200;
  else speed=0;
  Serial.println(speed);

  motor.run(BACKWARD);
  for (i=0; i<speed; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
  motor.setSpeed(speed);
  delay(5000);
}
