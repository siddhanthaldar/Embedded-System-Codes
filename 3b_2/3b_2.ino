#include <LiquidCrystal.h>
// set up pins on Arduino for LCD and test lead
LiquidCrystal lcd(12,11,5,4,3,2);
// set up the LCD's number of columns and rows
#define Xdelay 1900

int analogPin = 1;
int raw = 0; 
int Vin = 5; 
float R1 = 220;
float R2 = 0;
float Vout = 0; 
float res = 0;
float buffer = 0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  clearLCD();
  backlightOn();
  lcd.print("HELLO, WORLD!");
  delay(Xdelay);
//  clearLCD();
//  Serial.begin(9600);
}

void loop(){
  raw = analogRead(analogPin);
  if(raw){
    lcd.clear();
    lcd.print("R1 = ");
    lcd.print(R1);
    delay(Xdelay);

    lcd.clear();
    lcd.print("V1 = ");
    lcd.print(raw*Vin/1024.0);
    delay(Xdelay);

    lcd.clear();
    lcd.print("V2 = ");
    Vout = (1024.0-raw)*Vin/1024.0;
    lcd.print(Vout);
    delay(Xdelay);

    lcd.clear();
    lcd.print("R2 = ");
    lcd.print(Vout/(Vin-Vout)*R1);
    delay(Xdelay);
    
  }
}

//void loop(){
//  raw = analogRead(analogPin);
//  if(raw){
//    lcd.clear();
//    buffer = raw*Vin;
//    Vout = buffer / 1024.0;
////    buffer = (Vin/Vout)-1;
//    res = Vout/Vin * 10000.0;
//    lcd.print(res);
//    Serial.println(res);
//    delay(Xdelay); 
//      
//  }
//
//}

void clearLCD()
{
  lcd.write(0xFE); //command flag
  lcd.write(0x01); //clear command
  delay(10);
}

void backlightOn()
{
  lcd.write(0x7C); //command flag for backlight stuff
  lcd.write(157); //light level
  delay(10);
}
void backlightOff()
{
  lcd.write(0x7C); //command flag for backlight stuff
  lcd.write(128); //light level for off
  delay(10);
}
void backlightValue(int bv)
{
  int val = bv;
  if (bv < 128) val= map(bv, 0, 1023, 128, 157);
  if (bv > 157) val = map(bv, 0, 1023, 128, 157);
  lcd.write(0x7C); //command flag for backlight stuff
  lcd.write(val); //light level
  delay(10);
}

void displayOn()
{
  lcd.write(0xFE); //command flag
  lcd.write(0x0C); //clear command
  delay(10);
}

void displayOff()
{
  lcd.write(0xFE); //command flag
  lcd.write(0x08); //clear command
  delay(10);
}
