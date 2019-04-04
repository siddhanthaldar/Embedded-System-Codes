const int mq_pin = A0;

int val;

void setup() {
  pinMode(mq_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(mq_pin);
  // Normal
//  if(val>700) Serial.println("Detected");
//  else Serial.println("NO SMOKE");
  
  // Processing
  if(val>700) Serial.write(1);
  else Serial.write(0);

  delay(200);
}
