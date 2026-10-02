#if 0
#include <Arduino.h>

const int f_toneC4 = 262; // C4
const int f_toneD4 = 294; // D4
const int f_toneE4 = 330; // E4
const int f_toneF4 = 349; // F4
const int f_toneG4 = 392; // G4


// Funktion zur Erzeugung eines Tons ohne tone()
void playTone(int pin, int frequency) {
    long period = 1000000 / frequency; // Periodendauer in Mikrosekunden
    long duration = 500000; // Dauer des Tons in Mikrosekunden (0,5 Sekunden)
    for (long i = 0; i < duration; i += period) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pin, LOW);
        delayMicroseconds(period / 2);
    }
}

void setup() {
    pinMode(PB0, INPUT_PULLDOWN);
    pinMode(PB3, INPUT_PULLDOWN);
    pinMode(PB4, INPUT_PULLDOWN);
    pinMode(PA6, INPUT_PULLDOWN);
    pinMode(PA10, INPUT_PULLDOWN);
    pinMode(PA4, OUTPUT);
}

void loop() {
    int inputPB0 = digitalRead(PB0);
    int inputPB3 = digitalRead(PB3);
    int inputPB4 = digitalRead(PB4);
    int inputPA6 = digitalRead(PA6);
    int inputPA10 = digitalRead(PA10);

    if(inputPB0 == HIGH) {
        playTone(PA4, f_toneC4);
    } 
    if(inputPB3 == HIGH) {
        playTone(PA4, f_toneD4);
    } 
    if(inputPB4 == HIGH) {
        playTone(PA4, f_toneE4);
    } 
    if(inputPA6 == HIGH) {
        playTone(PA4, f_toneF4);
    } 
    if(inputPA10 == HIGH) {
        playTone(PA4, f_toneG4);
    } 
}
#endif