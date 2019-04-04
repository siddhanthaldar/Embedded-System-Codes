int analogPin = 0;
int ledPin = 13;
float raw = 0;
float temp = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);
  temp = raw*500.0/1024.0;
//  raw = 120;
//  temp = 30;
  Serial.println(temp);
//  Serial.write((int)temp);
  
}
