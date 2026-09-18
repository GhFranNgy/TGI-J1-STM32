#if 0
#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    pinMode(PC0, OUTPUT);
    pinMode(PC1, OUTPUT);
    pinMode(PC2, OUTPUT);
    pinMode(PC3, OUTPUT);

    while (!Serial) {
        ;//nichts tun
    }
}

void loop() {
    char input = Serial.read();

    if(input == 'a') {
        digitalWrite(PC0, LOW);
    } else if (input == 'b') {
        digitalWrite(PC1, LOW);
    } else if (input == 'c') {
        digitalWrite(PC2, LOW);
    } else if (input == 'd') {
        digitalWrite(PC3, LOW);
    } else if (input == 'A') {
        digitalWrite(PC0, HIGH);
    } else if (input == 'B') {
        digitalWrite(PC1, HIGH);
    } else if (input == 'C') {
        digitalWrite(PC2, HIGH);
    } else if (input == 'D') {
        digitalWrite(PC3, HIGH);
    } 
}
#endif