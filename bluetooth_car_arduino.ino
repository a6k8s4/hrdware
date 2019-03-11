/* This Project Uses L298N motor driver. */
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(0,1);
int okunanKarakter;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
void setup() {
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    bluetooth.begin(9600);
    
}
void loop() {
  
  while(bluetooth.available()>0){
    okunanKarakter = bluetooth.read(); 
    switch(okunanKarakter){
      case 'a': 
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);

        bluetooth.println("Forward");
        break;
      case 'b': 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);

        bluetooth.println("Backward");
        break;  
      case 'c':
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        bluetooth.println("Right");
        break;
      case 'd':
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
     
        bluetooth.println("Left");
        break;
      case 'e':
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
        bluetooth.println("Stop");
       break;
    } 
  }
}