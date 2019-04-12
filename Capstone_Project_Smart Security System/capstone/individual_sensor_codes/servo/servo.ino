#include <Servo.h>

Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
   myServo.attach(9); //pwm pin // Defines on which pin is the servo motor attached
}

void loop() {
  for(int i=0;i<=180;i++){  
    myServo.write(i);
    delay(30);
  }

  for(int i=180;i>0;i--){  
    myServo.write(i);
    delay(30);
  }
}
