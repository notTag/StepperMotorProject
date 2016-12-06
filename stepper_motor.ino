int dirpin = 2;   //direction pin on pin 2
int steppin = 4; //step pin on pin 4
int potPin = 0; //5 volt potentiometer on pin 0

void setup() {
  Serial.begin(9600);
  
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  digitalWrite(dirpin,LOW);
  digitalWrite(steppin,LOW);
}

void loop() {
  int potDelay = analogRead(potPin)/3;
  Serial.println(potDelay);

  digitalWrite(steppin, HIGH);
  delayMicroseconds(potDelay);
  digitalWrite(steppin, LOW);
  delayMicroseconds(potDelay);
}
