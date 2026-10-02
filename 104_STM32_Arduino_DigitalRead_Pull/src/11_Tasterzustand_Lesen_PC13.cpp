#if 0
#include <Arduino.h>

void setup() {
    pinMode(PC13, INPUT);
    pinMode(PA5, OUTPUT);
}

void loop() {
    int input = digitalRead(PC13);

    if(input == 1) {
        digitalWrite(PA5, LOW);
    }
    else {
        digitalWrite(PA5, HIGH);
    }
}

#endif