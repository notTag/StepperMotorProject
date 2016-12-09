#include <BlynkApiArduino.h>
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(8,9); //Rx, Tx

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

char auth[] = "bfb4b59a268a471f9b0ec05b31db8b52";

int dirPin = 2;   //direction pin on pin 2
int stepPin = 4; //step pin on pin 4
int delayTime = 100;

void setup() {
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(auth, Serial);
  
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(dirPin,LOW);
  digitalWrite(stepPin,LOW);
}

void loop() {
  Blynk.run();

//  fwd(delayTime);
}

void rotate(int delayTime, int dir){
//  Serial.println(LOW);
  if(dir == 1){
    digitalWrite(dirPin, LOW);
  } else {
    digitalWrite(dirPin, HIGH);
  }
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(delayTime);
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // String str = param.asStr();
  // double dbl = param.asDouble();
//  Serial.print("V1 Slider value is: ");
//  Serial.println(pinValue);

  //Currently I have the slider set up to send values between -1000 and 1000. 
  //Negative numbers rotates the pin counter clockwise
  //Positive numbers rotates the pin clockwise
  //Dead zone between -50 and 50 as a means to create an easy off for testing. 
  if(pinValue >= 50){
      for(int i=0; i<1000; i++){
        rotate(pinValue, 1);
      }  
  } else if(pinValue <= -50){
     for(int i=0; i<1000; i++){
        rotate(-1*pinValue, 0);  
      }
  }
  
}

