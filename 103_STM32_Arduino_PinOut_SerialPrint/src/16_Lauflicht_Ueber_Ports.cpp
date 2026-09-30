#if 1
#include <Arduino.h>

int ledPins[] = {
    PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8, PC9, PC10, PC11, PC12, PC13,
    PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15
};
void setup() {
    Serial.begin(115200);

    for(int i = 0; i < 46; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

void loop() {
    for(int i = 0; i < 46; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(10);
        digitalWrite(ledPins[i], LOW);
        delay(10);
    }
    for(int i = 46; i > 0; i--) {
        digitalWrite(ledPins[i], HIGH);
        delay(10);
        digitalWrite(ledPins[i], LOW);
        delay(10);
    }

    /*for(int i = 0; i < 46; i++) {
        digitalWrite(ledPins[i], HIGH);
        if (i < 46) {
            digitalWrite(ledPins[i+1], HIGH);
        }
        delay(20);

        digitalWrite(ledPins[i], LOW);
        delay(10);
    }
    for(int i = 46; i > 0; i--) {
        digitalWrite(ledPins[i], HIGH);
        if (i > 0) {
            digitalWrite(ledPins[i-1], HIGH);
        }
        delay(20);

        digitalWrite(ledPins[i], LOW);
        delay(10);
    }*/
}

#endif