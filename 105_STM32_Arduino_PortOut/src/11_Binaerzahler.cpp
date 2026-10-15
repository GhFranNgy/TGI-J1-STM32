#if 0
#include <Arduino.h>

#define LED_PORT GPIOC
int Port = 0;


void setup() {
    // Aktiviere den Takt für Port C
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    //RCC->AHBENR |= (1<<1); // Enable the GPIOB clock
    //RCC->AHBENR |= (1<<0); // Enable the GPIOA clock
    // Setze PA0 bis PA7 als Output (00 für jede Pin-Gruppe)
    LED_PORT->MODER &= ~0x0000FFFF; // lösche die Bits
    LED_PORT->MODER |= 0x00005555; // setze PC0 bis PC7 auf Output
    // Setze alle LEDs auf LOW (aus)
    LED_PORT->ODR = 0x0000; // Output Data Register
}

void loop() {
    LED_PORT -> ODR = (Port);
    Port++;
    delay(200);

    if(Port == 255) {
        Port = 0;
    }
}

#endif