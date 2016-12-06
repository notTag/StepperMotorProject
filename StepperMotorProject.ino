#include <BlynkApiArduino.h>
#include <BlynkApiParticle.h>
#include <BlynkParticle.h>
#include <BlynkSimpleCC3000.h>
#include <BlynkSimpleCurieBLE.h>
#include <BlynkSimpleEnergiaEthernet.h>
#include <BlynkSimpleEnergiaWiFi.h>
#include <BlynkSimpleEsp32.h>
#include <BlynkSimpleEsp8266.h>
#include <BlynkSimpleEsp8266_SSL.h>
#include <BlynkSimpleEthernet.h>
#include <BlynkSimpleEthernet2.h>
#include <BlynkSimpleEthernetV2_0.h>
#include <BlynkSimpleFishino.h>
#include <BlynkSimpleIntelEdisonWiFi.h>
#include <BlynkSimpleLinkItONE.h>
#include <BlynkSimpleMKR1000.h>
#include <BlynkSimpleParticle.h>
#include <BlynkSimpleRedBear_Duo.h>
#include <BlynkSimpleRedBear_Duo_BLE.h>
#include <BlynkSimpleRedBearLab_BLE_Nano.h>
#include <BlynkSimpleRFduinoBLE.h>
#include <BlynkSimpleSerialBLE.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <BlynkSimpleSimbleeBLE.h>
#include <BlynkSimpleStream.h>
#include <BlynkSimpleTinyDuino.h>
#include <BlynkSimpleUIPEthernet.h>
#include <BlynkSimpleUserDefined.h>
#include <BlynkSimpleWifi.h>
#include <BlynkSimpleWiFiShield101.h>
#include <BlynkSimpleWiFiShield101_SSL.h>
#include <BlynkSimpleWiFly.h>
#include <BlynkSimpleWildFire.h>
#include <BlynkSimpleYun.h>
#include <BlynkWidgets.h>
#include <BlynkWrongInclude.h>
#include <WidgetBridge.h>
#include <WidgetGPS.h>
#include <WidgetLCD.h>
#include <WidgetLED.h>
#include <WidgetRTC.h>
#include <WidgetSD.h>
#include <WidgetTable.h>
#include <WidgetTerminal.h>
#include <WidgetTimeInput.h>



int dirpin = 2;   //direction pin on pin 2
int steppin = 4; //step pin on pin 4
int potPin = 0; //5 volt potentiometer on pin 0

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
  int potDelay = analogRead(potPin)/3;
  Serial.println(potDelay);

  digitalWrite(steppin, HIGH);
  delayMicroseconds(potDelay);
  digitalWrite(steppin, LOW);
  delayMicroseconds(potDelay);
}
