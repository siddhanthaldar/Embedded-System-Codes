import processing.serial.*;
Serial port; // the Serial Port object is created
int val; // variable used to receive thermistor data from Arduino
void setup() {
size(440, 440); // size of canvas
String portname = Serial.list()[0];
port = new Serial(this, portname, 9600); // baud rate for COM port
background(0); // create a black canvas
}
void draw() {
  if (port.available() > 0){ // check for available data on COM port
    val= port.read(); // store COM port data in variable "val"
    print(val);
    print("\n");// print COM data on Console Monitor
   if(val==0) background(0,255,0);  
   else background(255,0,0);

  } 
  
  delay(50);
}
