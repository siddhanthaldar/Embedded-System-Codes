int analogPin = 0;
int buzzer = 13;
float raw = 0;
float temp = 0;

//int thresh = 800;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(analogPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);
  temp = raw*500.0/1024.0;

  if(temp>40) tone(buzzer,2000);
  else noTone(buzzer);
  Serial.println(temp);
  delay(100);
  
}
