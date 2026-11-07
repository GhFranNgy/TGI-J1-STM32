#if 1
#include <Arduino.h>

#define LED_PORTC GPIOC

// Zuweisung der Ziffer zu den Pins
// anzeigePins[0] = Einer (rechts), anzeigePins[1] = Zehner (links)
const int anzeigePins[2] = {PC7, PC8}; 

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
    LED_PORTC->ODR = ziffern[ziffer];
    // Aktiviere die gewünschte Anzeige und deaktiviere die andere
    digitalWrite(anzeigePins[anzeige], LOW);
    digitalWrite(anzeigePins[1 - anzeige], HIGH); // Deaktiviert die andere Anzeige
}

void setup() {

    RCC->AHBENR |= (1 << 2);

    LED_PORTC->MODER &= 0xFFF00000; 
    LED_PORTC->MODER |= 0x00055555; 

    LED_PORTC->ODR = 0;
}

void loop() {
    for (int zahl = 0; zahl < 100; zahl++) {
        int zehner = zahl / 10;
        int einer = zahl % 10;

        for (int i = 0; i < 50; i++) {
            zeigeZiffer(zehner, 1);
            delay(5);

            zeigeZiffer(einer, 0);
            delay(5);
        }
    }
}

#endif