#if 0
#include <Arduino.h>

#define LED_PORTC GPIOC

int bcd_7seg[] = {
    ~0x3F, 
    ~0x06, 
    ~0x5B, 
    ~0x4F, 
    ~0x66, 
    ~0x6D, 
    ~0x7D, 
    ~0x07, 
    ~0x7F,
    ~0x6F};

void ausgebenEiner(int zahl) {LED_PORTC -> ODR = bcd_7seg[zahl];}

void setup() {
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock

    LED_PORTC->MODER &= 0xFFFF0000; 
    LED_PORTC->MODER |= 0x00005555; 

    LED_PORTC->ODR = 0x00000000; 
}

void loop() {
    for (int i = 0; i < 10; i++) {
        ausgebenEiner(i);
        delay(200);
    }

}

#endif