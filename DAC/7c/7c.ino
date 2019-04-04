unsigned char sine[50] = {52,57,62,66,70,74,77,80,82,84,85,86,86,86,85,83,81,78,75,72,69,65,61,56,52,48,44,39,35,31,28,25,22,19,17,15,14,14,14,15,16,18,20,23,26,30,34,38,43,48};

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
for(int j=0;j<50;j++)
  {
    int b=sine[j];
    int a;
    for(int i=9;i>=2;i--)
    {
      a=b%2;
      b=b/2;
      if (a==1){
      digitalWrite(i, HIGH);}
      else{digitalWrite(i, LOW);}
    }
    int c=analogRead(A0);
    Serial.println(c);
    delay(5);
  }
}
