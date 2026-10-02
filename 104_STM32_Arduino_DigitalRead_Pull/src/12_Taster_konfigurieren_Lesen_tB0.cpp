#if 0
#include <Arduino.h>

void setup() {
    pinMode(PB0, INPUT_PULLDOWN);
    pinMode(PC0, OUTPUT);
}

void loop() {
    int input = digitalRead(PB0);

    digitalWrite(PC0, input);
}
#endif