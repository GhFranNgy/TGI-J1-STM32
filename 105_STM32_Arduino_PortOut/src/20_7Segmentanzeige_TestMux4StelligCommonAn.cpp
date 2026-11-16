#if 1
#include <Arduino.h>

#define LED_PORTB GPIOB

// Zuweisung der Ziffer zu den Pins
// anzeigePins[3] = Einer, anzeigePins[2] = Zehner, anzeigePins[1] = Hundert, anzeigePins[0] = Tausend
const int anzeigePins[4] = {PB8, PB9, PB10, PB11}; 

int ziffern[] = {
    ~0x3F, // 0
    ~0x06, // 1
    ~0x5B, // 2
    ~0x4F, // 3
    ~0x66, // 4
    ~0x6D, // 5
    ~0x7D, // 6
    ~0x07, // 7
    ~0x7F, // 8
    ~0x6F  // 9
};

void zeigeZiffer(int ziffer, int anzeige) {
    // Setze die Segmente entsprechend der gewünschten Ziffer
    LED_PORTB->ODR = ziffern[ziffer];
    // Aktiviere die gewünschte Anzeige und deaktiviere die andere
    digitalWrite(anzeigePins[anzeige], LOW);
    digitalWrite(anzeigePins[3 - anzeige], HIGH); // Deaktiviert die andere Anzeige
}

void setup() {

    RCC->AHBENR |= (1 << 1);

    LED_PORTB->MODER &= 0x00000000; 
    LED_PORTB->MODER |= 0x55555555; 

    LED_PORTB->ODR = 0;
}

void loop() {
    for (int zahl = 0; zahl < 10000; zahl++) {
        int tausender = (zahl / 1000) % 10;
        int hunderter = (zahl / 100) % 10;
        int zehner = (zahl / 10) % 10;
        int einer = zahl % 10;

        for (int i = 0; i < 30; i++) {
            zeigeZiffer(tausender, 0);
            delay(2);
            zeigeZiffer(hunderter, 1);
            delay(2);
            zeigeZiffer(zehner, 2);
            delay(2);
            zeigeZiffer(einer, 3);
            delay(2);
        }
    }
}

#endif