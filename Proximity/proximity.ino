int input_pin = 2;
int ledPin = 13;

int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(input_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(input_pin);
//  Serial.print("Motion:");
//  Serial.println(val);
  Serial.write(val);

  delay(100);

}
