
/* 
Dec 1 2017
 Code designed for use with the Standard Gripper Kit B with an HS-422 Actuator.
 Take care to adjust the open/close settings for each setup
 Serial inputs include "open", "close", and actuator angles
 Black - Grnd
 Yellow - Signal
 Red = Power
 
*/

#include <Servo.h>
#include <ctype.h>

Servo myservo;   // create servo object to control a servo

int open = 120;  // Actuator angle defined as "open"
int close = 110; // Actuator angle defined as "closed"



void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //Serial.begin(9600);
  Serial.begin(115200);       // initialize Serial Communication
}


void loop() {


    myservo.write(open);    
    while(true)  {
      String sd = Serial.readString();
      Serial.println(sd);
      if(sd == "close") {
        myservo.write(close);
      }
      if(sd == "open") {
        myservo.write(open);
      }
      Serial.println(sd.toInt());
      if(sd.toInt() != 0) {
        myservo.write(sd.toInt());   
      }
    }

 
}

////180 closes hard
//closegrip();
//delay(1000);
//opengrip();
//delay(1000);
