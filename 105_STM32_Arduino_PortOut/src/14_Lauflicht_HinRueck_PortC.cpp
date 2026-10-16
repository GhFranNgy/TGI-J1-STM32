#if 0
#include <Arduino.h>

#define LED_PORTC GPIOC
int portValue = 0b1;
int i = 0;
bool rück = false;


void setup() {
    // Aktiviere den Takt für Port C
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    // Setze PA0 bis PA7 als Output (00 für jede Pin-Gruppe)
    LED_PORTC->MODER &= ~0xFFFFFFFF; // lösche die Bits
    LED_PORTC->MODER |= 0x55555555; // setze PC0 bis PC7 auf Output
    // Setze alle LEDs auf LOW (aus)
    LED_PORTC->ODR = 0x00000000; // Output Data Register
}

void loop() {
    if (rück == false) {
        // Erster Ast: rück ist false (z. B. Vorwärtslauf)
        portValue = (1 << i);
        LED_PORTC->ODR = portValue;
        delay(200);
        i++;
        
        // Nach 15 Durchläufen auf true umschalten und i zurücksetzen
        if (i >= 15) {
            rück = true;
            i = 0;
        }
    } 
    else {
        // Zweiter Ast: rück ist true (z. B. Rückwärtslauf / andere Muster)
        portValue = (0x8000 >> i); 
        LED_PORTC->ODR = portValue;
        delay(200);
        i++;
        
        // Nach 15 Durchläufen wieder auf false umschalten und i zurücksetzen
        if (i >= 15) {
            rück = false;
            i = 0;
        }
    }
}

#endif