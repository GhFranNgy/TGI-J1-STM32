#if 0
#include <Arduino.h>

int delay_time = 0;

void setup() {
    Serial.begin(115200);

    pinMode(PA5, OUTPUT);

    while (!Serial) {
        ;//nichts tun
    }
}

void loop() {
    char input = Serial.read();

    if(input == '1') {
        delay_time = 1000;
    } else if (input == '2') {
        delay_time = 500;
    } else if (input == '3') {
        delay_time = 250;
    } else if (input == '4') {
        delay_time = 100;
    } else if (input == '5') {
        delay_time = 50;
    } 
    digitalWrite(PA5, HIGH);
    delay(delay_time);
    digitalWrite(PA5, LOW);
    delay(delay_time);
}

#endif