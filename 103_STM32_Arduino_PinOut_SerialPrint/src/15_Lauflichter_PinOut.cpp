#if 0
#include <Arduino.h>
 
#define NUM_LEDS 14  // PC0 bis PC13
int ledPins[NUM_LEDS] = {
    PC0, PC1, PC2, PC3, PC4, PC5, PC6,
    PC7, PC8, PC9, PC10, PC11, PC12, PC13
};
 
int pos = 0;
int direction = 1;
 
void setup() {
    Serial.begin(115200);
 
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}
 
void loop() {
    // alle LEDs aus
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], LOW);
    }
 
    // aktuelle LED an
    digitalWrite(ledPins[pos], HIGH);
 
    delay(150);
 
    // Richtung wechseln an den Enden
    if (pos == NUM_LEDS - 1) {
        direction = -1;
    } else if (pos == 0) {
        direction = 1;
    }
 
    pos += direction;
}

#endif