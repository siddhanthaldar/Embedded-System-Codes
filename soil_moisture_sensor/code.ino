const int VAL_PROBE = 0; // Analog pin 0
const int MOISTURE_LEVEL = 250; // the value after the LED goes ON
 
void setup() {
    Serial.begin(9600);
}
 
void LedState(int state) {
    digitalWrite(13, state);
}
 
void loop() {
    int moisture = analogRead(VAL_PROBE);
    moisture = map(moisture,1024,0,0,100);
//    Serial.println(moisture);
//    // normal
//    Serial.print(moisture);
//    Serial.println("%");

   //processing
   if(moisture>20) Serial.write(1);
   else Serial.write(0);

//    if(moisture > MOISTURE_LEVEL) {
//        LedState(HIGH);
//    } else   {
//        LedState(LOW);
//    }
    delay(100);
}
