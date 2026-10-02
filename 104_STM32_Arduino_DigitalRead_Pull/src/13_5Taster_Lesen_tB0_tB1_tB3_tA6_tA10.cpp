#if 1
#include <Arduino.h>

void setup() {
    for(int i = PC0; i <= PC4; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(PB0, INPUT_PULLDOWN);
    pinMode(PB1, INPUT_PULLDOWN);
    pinMode(PB3, INPUT_PULLDOWN);
    pinMode(PA6, INPUT_PULLDOWN);
    pinMode(PA10, INPUT_PULLDOWN);
}

void loop() {
    int inputPB0 = digitalRead(PB0);
    int inputPB1 = digitalRead(PB1);
    int inputPB3 = digitalRead(PB3);
    int inputPA6 = digitalRead(PA6);
    int inputPA10 = digitalRead(PA10);

    digitalWrite(PC0, inputPB0);
    digitalWrite(PC1, inputPB1);
    digitalWrite(PC2, inputPB3);
    digitalWrite(PC3, inputPA6);
    digitalWrite(PC4, inputPA10);

}
#endif