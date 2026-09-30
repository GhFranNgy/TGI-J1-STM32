#if 1
#include <Arduino.h>
 
int pos = 0;
int direction = 1;
 
void setup() {
    Serial.begin(115200);
    pinMode(PC0, OUTPUT);
    pinMode(PC1, OUTPUT);
    pinMode(PC2, OUTPUT);
    pinMode(PC3, OUTPUT);
    pinMode(PC4, OUTPUT);
    pinMode(PC5, OUTPUT);
    pinMode(PC6, OUTPUT);
    pinMode(PC7, OUTPUT);
    /*for (int i = PC0; i < PC7; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }*/
}
void setLeds(int led0, int led1, int led2, int led3, int led4, int led5, int led6, int led7) {
    digitalWrite(PC0, led0);
    digitalWrite(PC1, led1);
    digitalWrite(PC2, led2);
    digitalWrite(PC3, led3);
    digitalWrite(PC4, led4);
    digitalWrite(PC5, led5);
    digitalWrite(PC6, led6);
    digitalWrite(PC7, led7);
}
 
void loop() {
    setLeds(1, 0, 0, 0, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 1, 0, 0, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 1, 0, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 1, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 1, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 0, 1, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 0, 0, 1, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 0, 0, 0, 1);
    delay(100);
    setLeds(0, 0, 0, 0, 0, 0, 1, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 0, 1, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 0, 1, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 0, 1, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 0, 1, 0, 0, 0, 0, 0);
    delay(100);
    setLeds(0, 1, 0, 0, 0, 0, 0, 0);
    delay(100);
}

#endif