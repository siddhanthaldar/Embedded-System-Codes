int analogPin = 0;
int ledPin = 13;
float raw = 0;

//int thresh = 800;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);

//  if(raw>thresh) digitalWrite(ledPin,HIGH);
//  else digitalWrite(ledPin,LOW);

  Serial.println(raw*500.0/1024.0);
  delay(100);
  
}
