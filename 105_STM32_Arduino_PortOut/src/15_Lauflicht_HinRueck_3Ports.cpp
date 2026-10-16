#if 1
#include <Arduino.h>

#define LED_PORTC GPIOC
#define LED_PORTB GPIOB
#define LED_PORTA GPIOA

int portValue = 0b1;
int movingLED = 0;
int portCounter = 0; // 0 = Port C, 1 = Port B, 2 = Port A
bool rück = false;

void setup() {
    // Aktiviere den Takt für Port C, B und A
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    RCC->AHBENR |= (1<<1); // Enable the GPIOB clock
    RCC->AHBENR |= (1<<0); // Enable the GPIOA clock

    // Setze PC, PB und PA (0 bis 7) als Output
    LED_PORTC->MODER &= ~0xFFFFFFFF; 
    LED_PORTC->MODER |= 0x55555555; 
    LED_PORTB->MODER &= ~0xFFFFFFFF; 
    LED_PORTB->MODER |= 0x55555555; 
    LED_PORTA->MODER &= ~0xFFFFFFFF; 
    LED_PORTA->MODER |= 0x55555555; 

    // Setze alle LEDs auf LOW (aus)
    LED_PORTC->ODR = 0x00000000; 
    LED_PORTB->ODR = 0x00000000; 
    LED_PORTA->ODR = 0x00000000; 
}

void loop() {
    if (rück == false) {
        // Vorwärtslauf
        portValue = (1 << movingLED);
        
        // Aktiven Port einschalten, andere ausschalten
        LED_PORTC->ODR = (portCounter == 0) ? portValue : 0;
        LED_PORTB->ODR = (portCounter == 1) ? portValue : 0;
        LED_PORTA->ODR = (portCounter == 2) ? portValue : 0;
        
        delay(200);
        movingLED++;
        
        if (movingLED >= 15) { // Auf 8 geändert, da GPIO meist 8 Pins pro Port nutzt (oder 15/16 je nach Setup)
            movingLED = 0;
            portCounter++;
            
            if (portCounter > 2) {
                rück = true;
                portCounter = 2; // Starte Rückwärts bei Port A
            }
        }
    } 
    else {
        // Rückwärtslauf
        portValue = (0x8000 >> movingLED); // Bitshift angepasst für 8 Pins (0x80 = Pin 7)
        
        // Aktiven Port einschalten, andere ausschalten
        LED_PORTC->ODR = (portCounter == 0) ? portValue : 0;
        LED_PORTB->ODR = (portCounter == 1) ? portValue : 0;
        LED_PORTA->ODR = (portCounter == 2) ? portValue : 0;
        
        delay(200);
        movingLED++;
        
        if (movingLED >= 15) {
            movingLED = 0;
            portCounter--;
            
            if (portCounter < 0) {
                rück = false;
                portCounter = 0; // Starte Vorwärts bei Port C
            }
        }
    }
}

#endif