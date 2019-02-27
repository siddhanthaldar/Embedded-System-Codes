int ledPin = 2;
int analogPin = 0;
float raw = 0;
float val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);
  if(raw){
    val = raw/1024*5.0;
    Serial.println(val);
    if(val<1){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
    }
  }
}
