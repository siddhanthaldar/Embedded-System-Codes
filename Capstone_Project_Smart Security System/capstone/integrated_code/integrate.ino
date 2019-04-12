// Servo
#include <Servo.h>
Servo myServo; // Creates a servo object for controlling the servo motor
int angle;
int flag = 0;  // for flag 0, increase angle else decrease angle

// For Bluetooth
char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

// For sonar
const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;

//Buzzer 
int buzzerPin = 3;
int buzzerFreq = 2000;

int ledPin = 7;

void setup() {
    Serial.begin(38400);
    Serial.write("Power On");
    pinMode(13,OUTPUT);
    myServo.attach(9);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(ledPin,OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else {
        index=0;
        return(1);
    }
}

void loop()
{
    if (Comp("y")==0) {
        digitalWrite(13,HIGH);
        delay(5000);
        digitalWrite(13,LOW);
    }
    else{
      if(flag==0){
        distance = calculateDistance();
        if(distance<10){
          digitalWrite(ledPin,HIGH);
          tone(buzzerPin, buzzerFreq);
          delay(2000);
          noTone(buzzerPin);
          digitalWrite(ledPin,LOW);
        }
        angle += 1;
        if(angle>180){
          angle = 180;
          flag = 1;  
        }
        Serial.print(angle);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
        myServo.write(angle);
        }
        else if(flag==1){
          distance = calculateDistance();
          if(distance<10){
            digitalWrite(ledPin,HIGH);
            tone(buzzerPin, buzzerFreq);
            delay(2000);
            noTone(buzzerPin);
            digitalWrite(ledPin,LOW);
          }
          angle -= 1;
          if(angle<0){
            angle=0;
            flag=0;      
          }
          Serial.print(angle);
          Serial.print(",");
          Serial.print(distance);
          Serial.print(".");
          myServo.write(angle);
        }
        delay(30);
    }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration / 29 / 2;
  return distance;
}
