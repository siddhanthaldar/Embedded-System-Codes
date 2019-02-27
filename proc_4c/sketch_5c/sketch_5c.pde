import processing.serial.*;

Serial port;

String val;
int bg;
//PFont f;
//f = createFont("Arial",16,true);

void setup(){
 size(300,300);
 port = new Serial(this, "COM7", 9600);
// background(255,0,0);
}

void draw(){
   if(port.available() >0){
//    val = port.readStringUntil('\n'); 
    bg = port.read();
   } 
//   if(val!=null){
//     println(val);
//     bg = int(val);
     println(bg);
     if(bg==1) background(255,0,0);
     else background(0,255,0); 
//    }
//    delay(100);
//     if(bg==1){
////     textFont(f,16);
////     fill(0);
//     text("1", 10,50);
//     }
//     else{
////       textFont(f,16);
////     fill(0);
//     text("0",10,50);  
//     }
}
