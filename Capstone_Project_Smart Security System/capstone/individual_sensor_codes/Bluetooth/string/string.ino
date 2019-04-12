char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

void setup() {
    Serial.begin(38400);
    Serial.write("Power On");
    pinMode(7,OUTPUT);
    pinMode(13,OUTPUT);
}

char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }        index=0;
        return 0;
    }
    else {
        index=0;
        return 1;
    }
}

void loop()
{
//    if (Comp("Shivam")==0) {
//        digitalWrite(13,HIGH);
//    }
//    if (Comp("Siddhant")==0) {
//        digitalWrite(7,HIGH);
//    }

  if (Comp("y")==0){
    digitalWrite(7,HIGH);
    delay(3000);
    digitalWrite(7,LOW);
  }
}
