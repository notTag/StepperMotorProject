#include <BlynkApiArduino.h>
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(8,9); //Rx, Tx

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

char auth[] = "bfb4b59a268a471f9b0ec05b31db8b52";

int dirpin = 2;   //direction pin on pin 2
int steppin = 4; //step pin on pin 4
int delayTime = 100;

void setup() {
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(auth, Serial);
  
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  digitalWrite(dirpin,LOW);
  digitalWrite(steppin,LOW);
}

void loop() {
  Blynk.run();

//  fwd(delayTime);
}

void fwd(int delayTime){
//  Serial.println(LOW);
  digitalWrite(steppin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(steppin, LOW);
  delayMicroseconds(delayTime);
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  fwd(pinValue);
}

