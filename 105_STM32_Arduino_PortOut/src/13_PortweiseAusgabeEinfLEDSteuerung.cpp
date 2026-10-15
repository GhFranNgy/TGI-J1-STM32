#if 0
#include <Arduino.h>

#define LED_PORTC GPIOC
int portValue = 0b1;
int i = 0;


void setup() {
    // Aktiviere den Takt für Port C
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    // Setze PA0 bis PA7 als Output (00 für jede Pin-Gruppe)
    LED_PORTC->MODER &= ~0xFFFFFFFF; // lösche die Bits
    LED_PORTC->MODER |= 0x00005555; // setze PC0 bis PC7 auf Output
    // Setze alle LEDs auf LOW (aus)
    LED_PORTC->ODR = 0x00000000; // Output Data Register
}

void loop() {
    LED_PORTC -> ODR = (portValue);
    portValue = (0b00000001 << i);
    delay(200);
    i++;
    if (i > 7) {
        i = 0;
    }
}

#endif