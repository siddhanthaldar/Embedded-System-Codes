// set pin numbers:
const int lightsensorPin = A0; // the number of the light sensor pin
const int redledPin = 12; // the number of the red LED pin

// variables will change:
int sensorState = 0; // variable for reading light sensor status
void setup() {
  // initialize the LED pins as outputs:
  pinMode(redledPin, OUTPUT);
  // initialize the light sensor pin as an input:
  pinMode(lightsensorPin, INPUT);
  Serial.begin(9600);
}
void loop(){
  // read the state of the pushbutton value:
  sensorState = analogRead(lightsensorPin);
  Serial.println(sensorState);
  // check if the light sensor is activated
  // if it is, the sensorState is HIGH:
  //if (sensorState== HIGH) {
  if (sensorState > 500){
    // turn red LED on:
    digitalWrite(redledPin, HIGH);
  }
  else {
    // turn red LED off:
    digitalWrite(redledPin, LOW);
  }
}
