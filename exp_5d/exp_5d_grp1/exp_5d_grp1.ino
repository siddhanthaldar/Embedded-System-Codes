int trigPin = 8; 
int echoPin = 7; 
int digiPin = 13;
int motion=0;
float v=331.5+0.6*20;

void setup() 
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(digiPin, INPUT); 
}
float distanceCm(){ //
  // send sound pulse //
  digitalWrite(trigPin, LOW); //
  delayMicroseconds(3); //
  digitalWrite(trigPin, HIGH); //
  delayMicroseconds(5); //
  digitalWrite(trigPin, LOW); //
  // listen for echo //
  float tUs = pulseIn(echoPin, HIGH); // microseconds //
  float t = tUs / 1000.0 / 1000.0 / 2.0; // s //
  float d = t*v; // m //
  return d*100; // cm //
}
void loop() //
{
  motion=digitalRead(digiPin);
  if (motion==1){
  int d=distanceCm(); //
  if (d<1000){
  Serial.println(d, DEC);} //
  delay(200); // ms //
  }
 }
