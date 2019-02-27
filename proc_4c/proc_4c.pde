import processing.serial.*;

Serial port;

String val;
float bg;

void setup(){
 size(500,500);
 port = new Serial(this, "COM7", 9600);
 background(0,0,0);
}

void draw(){
   if(port.available() >0){
    val = port.readStringUntil('\n'); 
    println(val);
   } 
   if(val!=null){
     bg = float(val)/500*255;
     if(bg<100) background(255,0,0);
     if(bg>=100 && bg<200) background(0,255,0);
     if(bg>=200) background(0,0,255);
//     background(bg-30,bg,bg+60);
//     delay(100);
   }
}
