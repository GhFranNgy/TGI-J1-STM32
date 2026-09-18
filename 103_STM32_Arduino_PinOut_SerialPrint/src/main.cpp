#if 1
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(PC0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PC0, HIGH);
  delay(1000);
  digitalWrite(PC0, LOW);
  delay(1000);
}

#endif